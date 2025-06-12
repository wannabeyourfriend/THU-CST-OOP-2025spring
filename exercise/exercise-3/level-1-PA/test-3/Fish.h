#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
class Fish : public Animal {
public:
    Fish(int _color, int _op=1) : Animal(_op, _color) { }
    void swim() override {
        if(color == 0) {
            cout << "Red fish is swimming." << endl;
        }
        else {
            cout << "Blue fish is swimming." << endl;
        }
    }
    void sing() override {
        cout << "Fish can not sing." << endl;
    }
    ~Fish() {
        if (color == 0) {
            cout << "Red fish is gone." << endl;
        }
        else {
            cout << "Blue fish is gone." << endl;
        }
    }
};