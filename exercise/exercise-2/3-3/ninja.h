#pragma once
#include <iostream>
#include <string>
#include "dragon.h"
#include "weapon.h"
using namespace std;

class Ninja {
protected:
    Dragon dragon;
    Weapon weapon;

    Ninja(string dragon_name, string weapon_name, bool print) : dragon(dragon_name), weapon(weapon_name) {
        if (print) {
            cout << "Ninja is coming!" << endl;
        }
    }

public:

    Ninja(string dragon_name, string weapon_name);
    
    virtual void describe();
};