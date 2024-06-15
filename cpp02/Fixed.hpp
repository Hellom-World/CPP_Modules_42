#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        // Constructors and destructors
        Fixed();
        ~Fixed();
        
        // Copy constructor
        Fixed(const Fixed &fixed);
        
        // Overload operators
        Fixed &operator=(const Fixed &fixed);
        
        // Comparison operators
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
