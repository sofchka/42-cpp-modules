#include "Serializer.hpp"

#include <iostream>

int main()
{
    Data information;

    information.id = 42;
    information.name = "Sofi";
    information.value = 3.14;

    Data *original = &information;

    uintptr_t address = Serializer::serialize(original);
    Data *restored = Serializer::deserialize(address);

    std::cout << "Original address:  " << original << std::endl;
    std::cout << "Serialized value: " << address << std::endl;
    std::cout << "Restored address:  " << restored << std::endl;

    if (original == restored)
        std::cout << "Pointers are equal." << std::endl;
    else
        std::cout << "Pointers are different." << std::endl;

    std::cout << std::endl;

    std::cout << "Data:" << std::endl;
    std::cout << "id: " << restored->id << std::endl;
    std::cout << "name: " << restored->name << std::endl;
    std::cout << "value: " << restored->value << std::endl;

    return 0;
}