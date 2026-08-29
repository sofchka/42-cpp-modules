#include "identify.hpp"

#include <iostream>

int main()
{
    Base *one = new A();
    Base *two = new B();
    Base *three = new C();

    std::cout << "Pointer tests:" << std::endl;
    identify(one);
    identify(two);
    identify(three);

    delete one;
    delete two;
    delete three;

    A objectA;
    B objectB;
    C objectC;

    std::cout << "Reference tests:" << std::endl;
    identify(objectA);
    identify(objectB);
    identify(objectC);

    return 0;
}