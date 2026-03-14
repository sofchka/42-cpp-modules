#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}