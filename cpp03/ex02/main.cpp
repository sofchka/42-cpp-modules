#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap a("Lina");
    FragTrap b(a);
    FragTrap c;

    c = a;

    a.attack("enemy");
    a.takeDamage(20);
    a.beRepaired(10);
    a.highFivesGuys();

    return 0;
}