#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : weapon(weapon)
{
    this->name = name;
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}