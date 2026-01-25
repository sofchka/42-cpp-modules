#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie* zombie1 = newZombie( "Zombie1" );
    std::cout << "Anouncing zombie1..." << std::endl;
    zombie1->announce();
    std::cout << "Deleting zombie1..." << std::endl;
    delete zombie1;

    randomChump( "Zombie2" );

    return 0;
}