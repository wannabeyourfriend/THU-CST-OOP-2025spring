#include "ninja.h"

Ninja::Ninja(string dragon_name, string weapon_name) : dragon(dragon_name), weapon(weapon_name) {
    cout << "Ninja is coming!" << endl;
}

void Ninja::describe() {
    cout << "Ninja is with " << dragon.get_name() << " and " << weapon.get_name() << "." << endl;
}