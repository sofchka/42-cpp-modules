#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(const std::string& type);

    const std::string& getType() const; // to avoide returning a copy
    void setType(const std::string& type); // to avoide making a copy (better performance)
};

#endif