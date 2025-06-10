#pragma once
#include <iostream>
#include <cmath>
using namespace std;
template <typename T> class Line {
private:
    T k, b;
public:
    Line(T k_, T b_) : k(k_), b(b_) { }
    Line(T k_) : k(k_), b(0) { }
    bool intersect(const Line<T>& other) const;
    void show() const;

    bool operator<(const Line<T>& other) const;

    T getk() const;
    T getb() const;
};