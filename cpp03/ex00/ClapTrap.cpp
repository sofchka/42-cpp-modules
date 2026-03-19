#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called\n";
    name = "";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    std::cout << "Copy constructor called\n";
    name = src.name;
    hitPoints = src.hitPoints;
    energyPoints = src.energyPoints;
    attackDamage = src.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
    {
        name = rhs.name;
        hitPoints = rhs.hitPoints;
        energyPoints = rhs.energyPoints;
        attackDamage = rhs.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const std::string name)
{
    std::cout << "String constructor called\n";
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return;
    }
	if ((unsigned int)this->hitPoints <= amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;

}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0 || this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can't repair" << std::endl;
        return;
    }
    this->hitPoints += amount;
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}
