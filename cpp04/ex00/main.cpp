#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Correct Polymorphism" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl; // " " is for better readability
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\nWrong Polymorphism" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat* wrongCat2 = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); // will call WrongAnimal's version
    wrongMeta->makeSound();
    wrongCat2->makeSound(); // will call WrongCats's version

    delete wrongMeta;
    delete wrongCat;
    delete wrongCat2;

    return 0;
}