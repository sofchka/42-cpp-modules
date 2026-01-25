#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon; // Reference to a Weapon object (strictly required for HumanA)

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif