#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
class Bird : public Animal {
public:
    Bird(int _color, int _op=0) : Animal(_op, _color) { }
    void sing() override {
        if(color == 0) {
            cout << "Red bird is singing." << endl;
        }
        else {
            cout << "Blue bird is singing." << endl;
        }
    }
    void swim() override {
        cout << "Bird can not swim." << endl;
    }
    ~Bird() {
        if (color == 0) {
            cout << "Red bird is gone." << endl;
        }
        else {
            cout << "Blue bird is gone." << endl;
        }
    }
};