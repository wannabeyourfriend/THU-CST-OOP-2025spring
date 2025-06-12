#include"Fraction.h"
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void Fraction::simplify() {
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    else if( y == 0) {cout << "NAN" << endl;}
    int _gcd_ = gcd(abs(x), abs(y));
    x /= _gcd_;
    y /= _gcd_;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    return Fraction(a.x * b.y + a.y * b.x, a.y*b.y);
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    return a + Fraction(-b.x, b.y);
}

// Fraction operator+(const Fraction& a, int b) {
//     return a + Fraction(b);
// }
Fraction operator*(const Fraction& a, const Fraction& b) {
    return Fraction(a.x * b.x, a.y * b.y);
}

Fraction operator/(const Fraction& a, const Fraction& b) {
    Fraction b_ = Fraction(b.y, b.x);
    return a * b_;
}

ostream &operator<<(ostream &out, const Fraction& a) {
    if (a.y == 1){
        out << a.x;
    }
    else {
        out << a.x << "/" << a.y;
    }
    return out;
}