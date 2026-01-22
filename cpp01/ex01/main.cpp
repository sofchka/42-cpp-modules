#include "Zombie.hpp"
#include <iostream>

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde( N, "HordeZombie" );
    std::cout << "Anouncing horde zombies..." << std::endl;
    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }
    std::cout << "Deleting horde zombies..." << std::endl;
    delete[] horde;

    return 0;
}