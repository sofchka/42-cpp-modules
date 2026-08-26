#include "identify.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int choice = std::rand() % 3;

    if (choice == 0)
        return new A();
    if (choice == 1)
        return new B();

    return new C();
}

void identify(Base *object)
{
    if (dynamic_cast<A *>(object))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(object))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(object))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base &object)
{
    try
    {
        A &checkA = dynamic_cast<A &>(object);
        (void)checkA;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    try
    {
        B &checkB = dynamic_cast<B &>(object);
        (void)checkB;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    try
    {
        C &checkC = dynamic_cast<C &>(object);
        (void)checkC;
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &)
    {
        std::cout << "Unknown" << std::endl;
    }
}