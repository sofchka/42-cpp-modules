#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Animal a; // cannot instantiate an abstract class, will cause a compile error

    const int size = 4;
    Animal* animals[size];

    std::cout << "Start\n" << std::endl;

    // fill half dogs, half cats
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    
    std::cout << std::endl;

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << std::endl;

    // delete as Animal*
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << std::endl;

    std::cout << "\nDEEP COPY TEST\n";

    Dog original;

    std::cout << std::endl;

    original = Dog();

    std::cout << std::endl;

    Dog copy = original;

    std::cout << std::endl;

    return 0;
}