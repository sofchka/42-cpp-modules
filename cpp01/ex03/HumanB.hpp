#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon; // Weapon object (not a reference, not strictly required for HumanB + can be nullptr)

public:
    HumanB(const std::string& name);

    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif