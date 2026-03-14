#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
    int rawBits;
    static const int fractionalBits = 8;

public:
    Fixed();                  // Default constructor
    Fixed(const Fixed& src);  // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator
    ~Fixed();                 // Destructor

    Fixed(const int value); // Constructor from int
    Fixed(const float value); // Constructor from float

    float toFloat( void ) const;
    int toInt( void ) const;

    // Comparison operators
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment and decrement operators
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    // Increment and decrement operators
    static Fixed& min(Fixed& a, Fixed& b); // static => belongs to the class not an object, menak stex
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
// std::cout << a == operator<<(std::cout, a);
// we just inform ostream that we want to print the float representation of the fixed point number
// if we "<< Fixed"

#endif