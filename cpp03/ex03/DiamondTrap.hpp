#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap // virtual inheritance: because only one ClapTrap is needed in DiamondTrap
{
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& src);
    DiamondTrap& operator=(const DiamondTrap& rhs);
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI();
};

#endif