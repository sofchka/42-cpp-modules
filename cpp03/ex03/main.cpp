#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Diamondy");
    diamond.attack("Target");
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
    return 0;
}