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
        Fixed(const int value);
        Fixed(const float value);

        
        // Overload operators
        Fixed &operator=(const Fixed &fixed);
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
        
        // member functions
        // Converte o valor de ponto fixo em um valor de ponto flutuante
        float toFloat(void) const;
        // Converte o valor de ponto fixo em um valor inteiro
        int toInt(void) const;

        //getters and setters
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
