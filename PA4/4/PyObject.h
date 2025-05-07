#ifndef PYOBJECT_H
#define PYOBJECT_H

#include <iostream>
#include <string>
#include <typeinfo>     // For std::type_info
#include <utility>      // For std::move, std::forward
#include <stdexcept>    // For std::runtime_error
#include <type_traits>  // For SFINAE helpers like std::is_fundamental, std::remove_cv, etc.

// Forward declaration
class PyObject;

// Base class for type erasure and polymorphism
struct HolderBase {
    virtual ~HolderBase() {}
    virtual const std::type_info& type() const = 0;
    virtual void* get_void_ptr() = 0;             // Non-const access to underlying data
    virtual const void* get_void_ptr() const = 0; // Const access
    virtual HolderBase* clone_owned() const = 0;  // Creates a new owned copy (ActualHolder)
    virtual HolderBase* clone_as_ref() const = 0; // Creates a new reference holder (RefHolder)
};

// Forward declaration for RefHolder to be used in ActualHolder
template<typename T> struct RefHolder;

// Template derived class to actually hold data (owns the data)
template<typename T>
struct ActualHolder : public HolderBase {
    T data;

    ActualHolder(const T& val) : data(val) {}
    ActualHolder(T&& val) : data(std::move(val)) {}
    ~ActualHolder() override {} // T's destructor is automatically called for 'data'

    const std::type_info& type() const override { return typeid(T); }
    void* get_void_ptr() override { return &data; }
    const void* get_void_ptr() const override { return &data; }

    HolderBase* clone_owned() const override {
        return new ActualHolder<T>(data); // T's copy constructor
    }

    HolderBase* clone_as_ref() const override {
        // This allows creating a RefHolder to this ActualHolder's data.
        // const_cast is used to allow subsequent non-const access via the RefHolder,
        // aligning with behaviors like ((Test&)p).mutating_method().
        return new RefHolder<typename std::remove_cv<T>::type>(const_cast<typename std::remove_cv<T>::type&>(data));
    }
};

// Template derived class to hold a reference to data (does not own)
template<typename T>
struct RefHolder : public HolderBase {
    T* data_ptr; // Points to external data

    RefHolder(T& val) : data_ptr(&val) {}
    ~RefHolder() override {} // Does not own the data, so no deletion here

    const std::type_info& type() const override { return typeid(T); }
    void* get_void_ptr() override { return data_ptr; }
    const void* get_void_ptr() const override { return data_ptr; }

    HolderBase* clone_owned() const override {
        // Create an owned copy of the object this RefHolder points to.
        return new ActualHolder<T>(*data_ptr); // T's copy constructor
    }

    HolderBase* clone_as_ref() const override {
        // Create another RefHolder pointing to the same external data.
        return new RefHolder<T>(*data_ptr);
    }
};


class PyObject {
private:
    HolderBase* content;
    bool owns_data;      // True if 'content' is an ActualHolder and this PyObject owns it.

    void clear() {
        if (owns_data && content) {
            delete content; // Calls ActualHolder's destructor, which then calls T's destructor.
        } else if (content) { // For RefHolders or unowned ActualHolders (latter not in current design).
            delete content; // Calls RefHolder's destructor (typically empty).
        }
        content = nullptr;
        owns_data = false;
    }

    // Helper for fundamental types assignment
    template<typename T_val>
    void assign_fundamental(T_val val) {
        std::cout << "PyObject got a value" << std::endl;
        clear();
        // Use std::remove_cv and std::remove_reference to get the base type for ActualHolder
        using CleanT = typename std::remove_cv<typename std::remove_reference<T_val>::type>::type;
        content = new ActualHolder<CleanT>(val);
        owns_data = true; // PyObject always owns copies of fundamental types.
    }

    // Helper for complex lvalue assignment
    template<typename T_ref>
    void assign_complex_lvalue(T_ref& val) {
        std::cout << "PyObject got a value" << std::endl;
        clear();
        using CleanT = typename std::remove_cv<typename std::remove_reference<T_ref>::type>::type;
        content = new RefHolder<CleanT>(val); // Store a reference
        owns_data = false;                    // Does not own
        std::cout << "Borrowing" << std::endl;
    }

    // Helper for complex rvalue assignment
    template<typename T_rval>
    void assign_complex_rvalue(T_rval&& val) {
        std::cout << "PyObject got a value" << std::endl;
        clear();
        using CleanT = typename std::remove_cv<typename std::remove_reference<T_rval>::type>::type;
        content = new ActualHolder<CleanT>(std::forward<T_rval>(val)); // Move construct into ActualHolder
        owns_data = true;                                            // Takes ownership
        std::cout << "Owning" << std::endl;
    }

public:
    PyObject() : content(nullptr), owns_data(false) {}

    // Copy constructor
    PyObject(const PyObject& other) : content(nullptr), owns_data(false) {
        if (other.content) {
            if (other.owns_data) { // 'other' owns its data (likely ActualHolder)
                this->content = other.content->clone_owned(); // Deep copy
                this->owns_data = true;
            } else { // 'other' is a reference (likely RefHolder)
                this->content = other.content->clone_as_ref(); // Copy the reference
                this->owns_data = false;
            }
        }
    }

    // Move constructor
    PyObject(PyObject&& other) noexcept : content(other.content), owns_data(other.owns_data) {
        other.content = nullptr;
        other.owns_data = false;
    }

    ~PyObject() {
        clear();
    }

    // --- Assignment Operators ---

    // For fundamental types (e.g., int, char, double) by value
    
    template<typename T>
    typename std::enable_if<std::is_fundamental<typename std::remove_cv<typename std::remove_reference<T>::type>::type>::value, PyObject&>::type
    operator=(T val) {
        assign_fundamental(val);
        return *this;
    }

    // For complex types (lvalue reference)
    template<typename T>
    typename std::enable_if<
        !std::is_fundamental<typename std::remove_cv<typename std::remove_reference<T>::type>::type>::value &&
        !std::is_same<typename std::decay<T>::type, PyObject*>::value && // Exclude PyObject* (has own overload)
        !std::is_same<typename std::decay<T>::type, PyObject>::value,    // Exclude PyObject (has own overload)
    PyObject&>::type
    operator=(T& val) { // T& is an lvalue reference
        assign_complex_lvalue(val);
        return *this;
    }

    // For complex types (rvalue reference)
    template<typename T>
    typename std::enable_if<
        !std::is_fundamental<typename std::remove_cv<typename std::remove_reference<T>::type>::type>::value &&
        !std::is_same<typename std::decay<T>::type, PyObject*>::value && // Exclude PyObject*
        !std::is_same<typename std::decay<T>::type, PyObject>::value,    // Exclude PyObject
    PyObject&>::type
    operator=(T&& val) { // T&& is an rvalue reference
        assign_complex_rvalue(std::forward<T>(val));
        return *this;
    }

    // Copy assignment from another PyObject
    PyObject& operator=(const PyObject& other) {
        if (this == &other) {
            return *this;
        }
        std::cout << "PyObject got a value" << std::endl;
        clear();

        if (other.content) {
            // This PyObject becomes a reference to the data managed by 'other'.
            this->content = other.content->clone_as_ref();
            this->owns_data = false; // Now a reference, so does not own.
            std::cout << "Borrowing" << std::endl;
        }
        return *this;
    }

    // Move assignment from another PyObject
    PyObject& operator=(PyObject&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        std::cout << "PyObject got a value" << std::endl;
        clear(); // Clear current content

        // Transfer ownership and content from 'other'
        this->content = other.content;
        this->owns_data = other.owns_data;

        // Leave 'other' in a valid but empty state
        other.content = nullptr;
        other.owns_data = false;
        return *this;
    }

    // Assignment from PyObject*
    PyObject& operator=(PyObject* other_ptr) {
        std::cout << "PyObject got a value" << std::endl;
        clear();
        if (other_ptr && other_ptr->content) {
            // This PyObject becomes a reference to the data managed by '*other_ptr'.
            this->content = other_ptr->content->clone_as_ref();
            this->owns_data = false; // Now a reference, so does not own.
            std::cout << "Borrowing" << std::endl;
        } else {
            // If other_ptr is null or points to an empty PyObject, this PyObject becomes empty.
            this->content = nullptr;
            this->owns_data = false;
        }
        return *this;
    }

    // --- Type Conversion Operators ---

    // 非常量左值引用类型转换运算符
    template<typename T>
    operator T&() {
        if (!content) {
            throw std::runtime_error("PyObject is empty for reference conversion");
        }
        
        using RawType = typename std::remove_reference<T>::type;
        void* ptr = content->get_void_ptr();
        
        return *static_cast<RawType*>(ptr);
    }
    
    // 常量左值引用类型转换运算符
    template<typename T>
    operator const T&() const {
        if (!content) {
            throw std::runtime_error("PyObject is empty for const reference conversion");
        }
        
        using RawType = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
        const void* ptr = content->get_void_ptr();
        
        return *static_cast<const RawType*>(ptr);
    }
    
    // 值类型转换运算符
    template<typename T>
    operator T() const {
        if (!content) {
            throw std::runtime_error("PyObject is empty for value conversion");
        }
        
        using RawType = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
        const void* ptr = content->get_void_ptr();
        
        return *static_cast<const RawType*>(ptr);
    }

    // 特定类型的转换运算符，处理基本类型的转换
    operator int() const {
        if (!content) throw std::runtime_error("PyObject is empty for int conversion");
        const void* ptr = content->get_void_ptr();
        if (content->type() == typeid(int)) return *static_cast<const int*>(ptr);
        if (content->type() == typeid(long long)) return static_cast<int>(*static_cast<const long long*>(ptr));
        if (content->type() == typeid(double)) return static_cast<int>(*static_cast<const double*>(ptr));
        if (content->type() == typeid(char)) return static_cast<int>(*static_cast<const char*>(ptr));
        throw std::runtime_error("PyObject type mismatch for int conversion. Stored: " + std::string(content->type().name()));
    }

    operator double() const {
        if (!content) throw std::runtime_error("PyObject is empty for double conversion");
        const void* ptr = content->get_void_ptr();
        if (content->type() == typeid(double)) return *static_cast<const double*>(ptr);
        if (content->type() == typeid(int)) return static_cast<double>(*static_cast<const int*>(ptr));
        if (content->type() == typeid(char)) return static_cast<double>(*static_cast<const char*>(ptr));
        if (content->type() == typeid(long long)) return static_cast<double>(*static_cast<const long long*>(ptr));
        throw std::runtime_error("PyObject type mismatch for double conversion. Stored: " + std::string(content->type().name()));
    }

    operator char() const {
        if (!content) throw std::runtime_error("PyObject is empty for char conversion");
        const void* ptr = content->get_void_ptr();
        if (content->type() == typeid(char)) return *static_cast<const char*>(ptr);
        if (content->type() == typeid(int)) return static_cast<char>(*static_cast<const int*>(ptr));
        throw std::runtime_error("PyObject type mismatch for char conversion. Stored: " + std::string(content->type().name()));
    }
};

#endif // PYOBJECT_H