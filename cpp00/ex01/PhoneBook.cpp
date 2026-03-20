#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static std::string getInput(const std::string &prompt)
{
    std::string input;

    while (input.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) // Read entire line including spaces into input with newline removed!
        {
            std::cin.clear();
            std::cout << "\nExiting..." << std::endl;
            exit(1);
        }
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

static bool isDigits(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    Contact &c = contacts[index]; // it points to our contacts array at position index from PhoneBook class

    c.setFirstName(getInput("First name: "));
    c.setLastName(getInput("Last name: "));
    c.setNickname(getInput("Nickname: "));
    while (true)
    {
        c.setPhoneNumber(getInput("Phone number: "));
        if (c.getPhoneNumber().empty() || !isDigits(c.getPhoneNumber()))
        {
            std::cout << "    !  Phone number invalid." << std::endl;
            continue;
        }
        break;
    }

    c.setDarkestSecret(getInput("Darkest secret: "));

    if (count < 8)
        count++;
    index = (index + 1) % 8;
}

void PhoneBook::searchContact() const
{
    int i;
    std::string input_index;

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
    if (!std::getline(std::cin, input_index)) // read integer input for index with newline still in the buffer 
    {
        std::cin.clear();
        std::cout << "\nExiting..." << std::endl;
        exit(1);
    }

    if (isDigits(input_index))
        i = std::atoi(input_index.c_str()); // convert input string to integer index
    else
        i = -1; // set to invalid index if input is not a number
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
