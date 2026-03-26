#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat(); // no virtual destructor in WrongAnimal, but we can still define one here
    // But it won't be called if we delete a WrongCat through a WrongAnimal pointer (Leaks)

    void makeSound() const; // not virtual in WrongAnimal, so this won't override it
};

#endif