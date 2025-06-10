#pragma once
#include<iostream>
using namespace std;
class Animal {
protected:
    int op, color;
public:
    Animal(int _op = 0, int _color = 0) : op(_op), color(_color) {}
    virtual void sing() {
    }
    virtual void swim() {
    }
    virtual ~Animal() {}
};