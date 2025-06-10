#pragma once
#include <iostream>
#include <cmath>
using namespace std;
template <typename T> class Line;
template <typename T> class Point {
private:
    T x, y;
public:
    Point(T x_, T y_) : x(x_), y(y_) {};
    void move(T dx, T dy) {
        x += dx;
        y += dy;
        return;
    }
    bool check(const Line<T>& l) const {
        if(abs(y - l.getk() * x - l.getb()) < 1e-6) {
            return true;
        }
        else {
            return false;
        }
    }
    void show () {
        cout << "(" << x << "," << y << ")" << endl; 
    }
};