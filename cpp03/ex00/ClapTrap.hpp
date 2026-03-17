#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
    int hitPoints;
    int energyPoints;
    int attackDamage;
    std::string name;

public:
    ClapTrap();                  // Default constructor
    ClapTrap(const ClapTrap& src);  // Copy constructor
    ClapTrap& operator=(const ClapTrap& rhs); // Copy assignment operator
    ~ClapTrap();                 // Destructor
    
    ClapTrap(const std::string name);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif