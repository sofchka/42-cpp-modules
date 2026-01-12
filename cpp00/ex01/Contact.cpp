#include "Contact.hpp"

Contact::Contact() // default constructor which runs when we create an object of the class (in this case it does nothing)
{
}

void Contact::setFirstName(const std::string &value) // if we dont write in input "const&"" it will make a copy of the string and we cant make changes
{
    firstName = value;
}

void Contact::setLastName(const std::string &value)
{
    lastName = value;
}

void Contact::setNickname(const std::string &value)
{
    nickname = value;
}

void Contact::setPhoneNumber(const std::string &value)
{
    phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value)
{
    darkestSecret = value;
}

std::string Contact::getFirstName() const // we use const after the function name => to not modify the value (for the further use as const)
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

bool Contact::isEmpty() const
{
    return firstName.empty(); //.empty() is a function of the string class that checks if the string is empty (true/false)
}
