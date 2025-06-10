#include "Array.h"
#include <stdexcept>

Array::Array(int len) : length(len)
{
    if(len <= 0) {
        throw std::invalid_argument("Array length must be positive");
    }
    data = new Node[len];
}

Array::~Array()
{
    delete[] data;
}

Array::Array(const Array &other) : length(other.length)
{
    data = new Node[length];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

Array::Array(Array &&other) : data(other.data), length(other.length)
{
    other.data = nullptr;
    other.length = 0;
}

Array &Array::operator=(const Array &other)
{
    // TODO: 在此处插入 return 语句
    if (this != &other) {
        delete[] data;
        
        length = other.length;
        data = new Node[length];
        
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array &Array::operator=(Array &&other)
{
    // TODO: 在此处插入 return 语句
    if (this != &other) {
        delete[] data;
        
        data = other.data;
        length = other.length;
        
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

Node &Array::operator[](int index)
{
    // TODO: 在此处插入 return 语句
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const Node &Array::operator[](int index) const
{
    // TODO: 在此处插入 return 语句
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
