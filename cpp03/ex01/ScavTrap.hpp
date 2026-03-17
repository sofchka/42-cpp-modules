#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//What to write inside ScavTrap:
//  new functions
//  overridden functions
//  special constructors/destructor

class ScavTrap : public ClapTrap // Constructor calls ClapTrap first, because base class must exist before derived class.
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& src);
    ScavTrap& operator=(const ScavTrap& rhs);
    ~ScavTrap();

    void attack(const std::string& target); // This replaces (overrides) ClapTrap attack for ScavTrap objects and calls ScavTrap attack, not ClapTrap attack
    void guardGate();
};

#endif