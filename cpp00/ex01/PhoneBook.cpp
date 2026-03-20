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
            std::cout << "\n Exiting..." << std::endl;
            return "";
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
    Contact &c = contacts[index];

    std::string input;

    input = getInput("First name: ");
    if (input.empty())
        return;
    c.setFirstName(input);

    input = getInput("Last name: ");
    if (input.empty())
        return;
    c.setLastName(input);

    input = getInput("Nickname: ");
    if (input.empty())
        return;
    c.setNickname(input);

    while (true)
    {
        input = getInput("Phone number: ");
        if (!isDigits(input))
        {
            std::cout << "    !  Phone number invalid." << std::endl;
            continue;
        }
		else if (input.empty())
        	return;
        c.setPhoneNumber(input);
        break;
    }

    input = getInput("Darkest secret: ");
    if (input.empty())
        return;
    c.setDarkestSecret(input);

    if (count < 8)
        count++;
    index = (index + 1) % 8;

	std::cout << "Contact added successfully." << std::endl;
}

static int	my_atoi(const char *str)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (numb * 10) + (str[i] - '0');
		i++;
	}
	return (numb * sign);
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
        return ;
    }

    if (isDigits(input_index))
        i = my_atoi(input_index.c_str()); // convert input string to integer index
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
