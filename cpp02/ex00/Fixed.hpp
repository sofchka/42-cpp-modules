#ifndef FIXED_HPP
#define FIXED_HPP

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

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif