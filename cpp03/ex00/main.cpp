#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
    ClapTrap a;
    ClapTrap b(a);
    ClapTrap c;
    c = a;

    a.attack("target");
    a.takeDamage(5);
    a.beRepaired(3);

    return 0;
}