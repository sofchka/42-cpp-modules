#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
    ScavTrap a("Sofi");
    ScavTrap b = a;;

    a.attack("target");
    a.takeDamage(5);
    a.beRepaired(3);
    a.guardGate();

    return 0;
}