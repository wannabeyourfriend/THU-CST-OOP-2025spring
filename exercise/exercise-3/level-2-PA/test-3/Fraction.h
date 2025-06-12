#pragma once
#include<cmath>
#include<iostream>
using namespace std;
class Fraction {
public:
    int x, y;
public:
    Fraction(int _x, int _y = 1) : x(_x), y(_y) {
        simplify();
    }
    //Fraction(int&& _x) : x(_x), y(1) {
    //     simplify();
    // }
    void simplify();
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend ostream &operator<<(ostream &out, const Fraction& a);

};

