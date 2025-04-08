#pragma once
#include "weapon.hpp"
#include <memory>
#include <algorithm>
#include <functional>
#include <numeric>

class WeaponSlot {
private:
    std::unique_ptr<Weapon> arsenal;

public:
    WeaponSlot() : arsenal(nullptr) {}

    ~WeaponSlot() = default;
    
    WeaponSlot(WeaponSlot&& source) noexcept : arsenal(std::move(source.arsenal)) {}

    WeaponSlot& operator=(WeaponSlot&& source) noexcept {
        if (std::addressof(source) != this) {
            arsenal = std::move(source.arsenal);
        }
        return *this;
    }

    WeaponSlot& operator=(const WeaponSlot& source) {
        if (std::addressof(source) != this && source.arsenal) {
            arsenal = std::make_unique<Weapon>(source.arsenal->penetration);
            
            std::for_each(source.arsenal->spells.begin(), source.arsenal->spells.end(),
                [this](const int& magic_power) {
                    if ((magic_power & 1) == 0) { // 位运算检查偶数
                        arsenal->spells.push_back(magic_power);
                    }
                });
        }
        return *this;
    }

    void create_weapon(int armor_pierce) {
        arsenal = std::make_unique<Weapon>(armor_pierce);
    }

    void add_spell(int magic_power) {
        if (arsenal) {
            arsenal->spells.emplace_back(magic_power);
        }
    }

    int calc_damage_typeA(int armor) {
        if (!arsenal) return 0;
        
        int reduced_armor = std::max(0, armor - arsenal->penetration);
        
        return std::accumulate(arsenal->spells.begin(), arsenal->spells.end(), 0,
            [reduced_armor](int sum, int magic_power) {
                return sum + std::max(0, magic_power - reduced_armor);
            });
    }

    int calc_damage_typeB() {
        if (!arsenal) return 0;
        
        int cumulative_damage = 0;
        int dynamic_armor = 0;
        
        for (const auto& magic_power : arsenal->spells) {
            int battle_armor = std::max(0, dynamic_armor - arsenal->penetration);
            
            cumulative_damage += std::max(0, magic_power - battle_armor);
            
            dynamic_armor++;
        }
        
        return cumulative_damage;
    }

    int calc_damage_typeC() {
        if (!arsenal) return 0;
        
        int final_damage = 0;
        int adaptive_armor = 0;
        
        for (const auto& magic_power : arsenal->spells) {
            int effective_armor = std::max(0, adaptive_armor - arsenal->penetration);
            
            int raw_damage = std::max(0, magic_power - effective_armor);
            
            if (raw_damage > 0) {
                if (raw_damage % 2) { // 奇数伤害
                    final_damage += raw_damage;
                    adaptive_armor++; // 防御力增加
                } else { // 偶数伤害
                    final_damage += (raw_damage >> 1); // 位运算除以2
                }
            }
        }
        
        return final_damage;
    }
};