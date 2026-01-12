#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string getInput(const std::string &prompt)
{
    std::string input;

    while (input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, input); // Read entire line including spaces into input with newline removed!
    }
    return input;
}

static std::string formatText(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

PhoneBook::PhoneBook() // constructor to initialize count and index
{
    count = 0;
    index = 0;
}

void PhoneBook::addContact()
{
    Contact &c = contacts[index]; // it points to our contacts array at position index from PhoneBook class

    c.setFirstName(getInput("First name: "));
    c.setLastName(getInput("Last name: "));
    c.setNickname(getInput("Nickname: "));
    c.setPhoneNumber(getInput("Phone number: "));
    c.setDarkestSecret(getInput("Darkest secret: "));

    if (count < 8)
        count++;
    index = (index + 1) % 8;
}

void PhoneBook::searchContact() const
{
    int i;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|" // setw => set width for output formatting to print in table format -> orgnized
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatText(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatText(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatText(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index: ";
    std::cin >> i; // read integer input for index with newline still in the buffer 
    std::cin.ignore(); // ignore the newline character left in the buffer after reading

    if (i < 0 || i >= count)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
}
