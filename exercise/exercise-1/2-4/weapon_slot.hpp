#pragma once
#include "weapon.hpp"
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
using namespace std;

class WeaponSlot //使用一个武器槽来包装武器类
{
private:
    unique_ptr<Weapon> arsenal;

public:
    WeaponSlot() : arsenal(nullptr) {}

    ~WeaponSlot() = default;

    //使用移动语义来实现所有权的转移，右值拷贝构造函数
    WeaponSlot(WeaponSlot&& source) : arsenal(std::move(source.arsenal)) {}

    //移动赋值运算符重载
    WeaponSlot& operator=(WeaponSlot&& source) {
        if(this != &source) {
            arsenal = std::move(source.arsenal);
        }
        return *this;
    }

    //拷贝赋值运算符
    WeaponSlot& operator=(const WeaponSlot& source) {
        if(this == &source || !source.arsenal) {
            return *this;
        }
        
        auto new_weapon = std::make_unique<Weapon>(source.arsenal->penetration);

        for(const int& magic_power : source.arsenal->spells) {
            if(magic_power % 2 == 0) {
                new_weapon->spells.push_back(magic_power);
            }
        }
        arsenal = std::move(new_weapon);
        return *this;
    }

    //在武器槽中创建一个具有穿甲值p的武器库
    void create_weapon(int p) {
        arsenal = std::make_unique<Weapon>(p);
    }

    void add_spell(int magic_power) {
        if(arsenal != nullptr) {
            arsenal->spells.push_back(magic_power);
        }
    }

    int calc_damage_typeA(int armor) {
        if(!arsenal) {
            return 0;
        }
        int reduced_armor = armor - arsenal->penetration;
        if(reduced_armor < 0) {
            reduced_armor = 0;
        }

        int total_damage = 0;
        for(int magic_power : arsenal->spells) {
            int damage_this_spell = std::max(0, magic_power - reduced_armor);
            // if (damage_this_spell < 0) {
            //     damage_this_spell = 0;
            // }
            total_damage += damage_this_spell;
        }
        return total_damage;
    }

    int calc_damage_typeB() {
        if(!arsenal) {
            return 0;
        }

        int armor = 0;
        int total_damage = 0;

        for(int magic_power : arsenal->spells) {

            int reduced_armor = std::max(0, armor - arsenal->penetration);

            int damage_this_spell = std::max(0, magic_power - reduced_armor);

            armor++;

            total_damage += damage_this_spell;
        }
        return total_damage;
    }

    int calc_damage_typeC() {
        if(!arsenal) {
            return 0;
        }
        int armor = 0;
        int total_damage = 0;
        
        for(int magic_power : arsenal->spells) {

            int reduced_armor = std::max(0, armor - arsenal->penetration);

            int damage_this_spell = std::max(0, magic_power - reduced_armor);
            
            if (damage_this_spell > 0) {

                if(damage_this_spell % 2 == 1) {
                    armor++;
                }
                else {
                    damage_this_spell /= 2;
                }
            }
            
            total_damage += damage_this_spell;
        }
        return total_damage;
    }

};