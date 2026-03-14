#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    rawBits = 0;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called\n";
    rawBits = src.rawBits;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        rawBits = rhs.rawBits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return rawBits;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    rawBits = raw;
}