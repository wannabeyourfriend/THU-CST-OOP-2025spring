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
    
    // Protected constructor for derived classes to use
    Ninja(string dragon_name, string weapon_name, bool print) : dragon(dragon_name), weapon(weapon_name) {
        if (print) {
            cout << "Ninja is coming!" << endl;
        }
    }
    
public:
    // Public constructor for direct use - declaration only
    Ninja(string dragon_name, string weapon_name);
    
    virtual void describe();
};