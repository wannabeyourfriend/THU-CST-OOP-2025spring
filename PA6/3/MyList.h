#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <vector>
#include <memory>   // Required for std::shared_ptr
#include <cstddef>  // Required for size_t

// Forward declarations
class MyList;
std::ostream& operator<<(std::ostream& os, const MyList& list);

/**
 * @class MyList
 * @brief A C++ implementation of a list with Python-like reference and slicing semantics.
 */
class MyList {
private:
    std::shared_ptr<std::vector<int>> data; // Shared pointer to the underlying data
    size_t start;                           // Starting index of this view in the data vector
    size_t len;                             // Length of this view (only used for slices)
    bool is_slice;                          // Flag to distinguish master lists from slices

    /**
     * @brief Private constructor to create a slice.
     * @param d The shared_ptr to the data vector.
     * @param s The start index for the slice.
     * @param l The length of the slice.
     */
    MyList(std::shared_ptr<std::vector<int>> d, size_t s, size_t l)
        : data(d), start(s), len(l), is_slice(true) {}

public:
    /**
     * @brief Default constructor. Creates an empty master list.
     */
    MyList() 
        : data(std::make_shared<std::vector<int>>()), start(0), len(0), is_slice(false) {}

    /**
     * @brief Gets the number of elements in the list or slice.
     * @return The size.
     */
    size_t size() const {
        if (is_slice) {
            return len; // A slice has a stored length.
        }
        // A master list's size is the entire vector's size.
        return data->size();
    }

    /**
     * @brief Appends an element to the end of the list or slice.
     * @param value The integer value to append.
     */
    void append(int value) {
        if (is_slice) {
            // For a slice, insert into the master vector at the slice's end.
            data->insert(data->begin() + start + len, value);
            len++; // The slice itself grows.
        } else {
            // For a master list, simply append to the vector.
            data->push_back(value);
        }
    }

    /**
     * @brief Accesses an element by index.
     * @param index The index of the element relative to the start of the view.
     * @return A reference to the element.
     */
    int& operator[](size_t index) {
        return (*data)[start + index];
    }
    
    /**
     * @brief Accesses a const element by index.
     * @param index The index of the element relative to the start of the view.
     * @return A const reference to the element.
     */
    const int& operator[](size_t index) const {
        return (*data)[start + index];
    }

    /**
     * @brief Creates a new MyList as a slice of the current one.
     * @param from The starting index of the slice (inclusive).
     * @param to The ending index of the slice (exclusive).
     * @return A new MyList object representing the slice.
     */
    MyList operator()(size_t from, size_t to) {
        return MyList(data, start + from, to - from);
    }

    /**
     * @brief Friend function to enable printing MyList with std::cout.
     */
    friend std::ostream& operator<<(std::ostream& os, const MyList& list);
};

/**
 * @brief Overloads the << operator for printing a MyList.
 * @param os The output stream.
 * @param list The MyList to print.
 * @return The output stream.
 */
inline std::ostream& operator<<(std::ostream& os, const MyList& list) {
    os << "[";
    size_t current_size = list.size();
    for (size_t i = 0; i < current_size; ++i) {
        os << list[i]; // Uses the const version of operator[]
        if (i < current_size - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

#endif // MYLIST_H