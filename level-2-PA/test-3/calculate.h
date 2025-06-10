#pragma once
#include<iostream>
#include"Fraction.h"
using namespace std;
template <typename T> 
T calculate(char expressionType, T x, T y, T z) {
    if(expressionType == 'A') {
        return (x * x + y * y + z * z);
    }
    else if (expressionType == 'B') {
        return (x * y + y / z - x * z);  
    }
    else if (expressionType == 'C') {
        return (y * 3 * z - x * z / (y - 2) - x * y / (z + 1));
    }
    else {
        cout << "Wrong input" << endl;
    }
}