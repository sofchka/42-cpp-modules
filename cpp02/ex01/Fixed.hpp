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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
// std::cout << a == operator<<(std::cout, a);

#endif