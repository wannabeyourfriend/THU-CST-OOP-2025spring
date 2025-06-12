#include "ice_ninja.h"

IceNinja::IceNinja(string dragon_name, string weapon_name) : Ninja(dragon_name, weapon_name, false) {
    cout << "Ice ninja is coming!" << endl;
}

void IceNinja::describe() {
    cout << "Ice ninja is with " << dragon.get_name() << " and " << weapon.get_name() << "." << endl;
}

void IceNinja::ice_power() {
    cout << "You will be the dust of frozen bones!" << endl;
}