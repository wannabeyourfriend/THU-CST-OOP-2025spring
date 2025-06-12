#pragma once
#include "Node.h"

class Array {
private:
    Node* data;
    int length;

public:
    Array(int len);

    ~Array();

    Array(const Array& other);

    Array(Array&& other);

    Array& operator=(const Array& other);

    Array& operator=(Array&& other);

    Node& operator[](int index);

    const Node& operator[](int index) const;

};