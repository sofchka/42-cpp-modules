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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    rawBits = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    rawBits = roundf(value * (1 << fractionalBits)); // qanzi value n float a << chem kara anem 
}

float Fixed::toFloat() const
{
    return (float)rawBits / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return rawBits >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}