#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nExiting..." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
            std::cout << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
            std::cout << std::endl;
        }
        else if (command == "EXIT")
            break;
    }
    return 0;
}
