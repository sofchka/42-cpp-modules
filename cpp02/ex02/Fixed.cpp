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

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator<(const Fixed& other) const
{
    return rawBits < other.rawBits;
}

bool Fixed::operator>(const Fixed& other) const
{
    return rawBits > other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return rawBits <= other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return rawBits >= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return rawBits != other.rawBits;
}

Fixed& Fixed::operator++()
{
    rawBits += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this); 
    rawBits += 1;
    return tmp;
}

Fixed& Fixed::operator--()
{
    rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this); 
    rawBits -= 1;
    return tmp;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}