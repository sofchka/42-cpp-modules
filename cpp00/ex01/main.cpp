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
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phoneBook.addContact();
            std::cout << "Contact added successfully." << std::endl;
            std::cout << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
            std::cout << std::endl;
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
    return 0;
}
