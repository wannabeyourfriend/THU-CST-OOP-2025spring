#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Factor 
{
private:
    long long numerator;      
    long long denominator;    

    long long gcd(long long a, long long b);

    void simplify();

public:
    Factor() : numerator(0), denominator(1) {}
    Factor(long long n, long long d) : numerator(n), denominator(d) {
        simplify();
    }

    Factor operator+(const Factor& other) const;
    Factor operator*(const Factor& other) const;
    Factor operator/(const Factor& other) const;
    bool operator<(const Factor& other) const;
    bool operator>(const Factor& other) const;
    bool operator==(const Factor& other) const;

    friend istream& operator>>(istream& in, Factor& f);
    friend ostream& operator<<(ostream& out, const Factor& f);
};
