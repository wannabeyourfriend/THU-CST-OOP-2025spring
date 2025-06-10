#include"Factor.h"
#include<iostream>
using namespace std;

long long Factor::gcd(long long a, long long b) {
    return b == 0? a : gcd(b, a % b);
}

void Factor::simplify() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    if (numerator == 0 && denominator != 0) {
        denominator = 1;
        return;
    }
    if (denominator == 0) {
        numerator = 0;
        return;
    }
    long long d = gcd(abs(numerator), abs(denominator));
    numerator /= d;
    denominator /= d;
}

Factor Factor::operator+(const Factor& other) const {
    long long new_num = numerator * other.denominator + other.numerator * denominator;
    long long new_den = denominator * other.denominator;
    return Factor(new_num, new_den);
}

Factor Factor::operator*(const Factor& other) const {
    long long new_num = numerator * other.numerator;
    long long new_den = denominator * other.denominator;
    return Factor(new_num, new_den);
}

Factor Factor::operator/(const Factor& other) const {
    if (other.numerator == 0) {
        return Factor(0, 0);  
    }
    long long new_num = numerator * other.denominator;
    long long new_den = denominator * other.numerator;
    //cout << new_num << " " << new_den << endl;
    return Factor(new_num, new_den);
}

bool Factor::operator<(const Factor& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Factor::operator>(const Factor& other) const {
    return other < *this;
}

bool Factor::operator==(const Factor& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

istream& operator>>(istream& in, Factor& f) {
    char slash;
    in >> f.numerator >> slash >> f.denominator;
    f.simplify();
    return in;
}

ostream& operator<<(ostream& out, const Factor& f) {
    if (f.denominator == 0) {
        out << "nan";
    } else {
        out << f.numerator << "/" << f.denominator;
    }
    return out;
}