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
        ~Fixed() { };

        // Copy constructor
        Fixed(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);


        // Overload operators comparison

        Fixed &operator=(const Fixed &fixed);
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed);
        bool operator<=(const Fixed &fixed);
        bool operator==(const Fixed &fixed);
        bool operator!=(const Fixed &fixed);


        // Overload operators arithmetic
        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);

        // min and max
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        // Overload operators increment and decrement
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

        // member functions conversion
        float toFloat(void) const;
        int toInt(void) const;

        //getters and setters
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
