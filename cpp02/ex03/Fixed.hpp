#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Fixed {
  private:
    int _value;
    static const int _fractionalBits = 8;
  public:
    Fixed();
    ~Fixed();

    // copy constructor
    Fixed(const Fixed &Fixed);

    // overload operator =
    Fixed &operator=(const Fixed &Fixed);

    // getter

    // setter

};

#endif