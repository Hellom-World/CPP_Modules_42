#include "Fixed.hpp"

//Constructor Padrao e destructor
Fixed::Fixed() : _value(0) {
    std::cout << GREEN << "| Default constructor called         |" << RESET << std::endl;
}
Fixed::~Fixed() {
    std::cout << RED << " ___________________" << RESET << std::endl;
    std::cout << RED << "| Destructor called |" << RESET << std::endl;
    std::cout << RED << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << RESET << std::endl;
}


//Construtor de copia
Fixed::Fixed(const Fixed &src) {
  std::cout << GREEN << "| Copy constructor called            |" << RESET << std::endl;  
  *this = src;
}
//Construtor com int
Fixed::Fixed(const int value) {
    std::cout << GREEN << "| Int constructor called             |" << RESET << std::endl;
    this->_value = value << this->_fractionalBits;
}
//Construtor com float
Fixed::Fixed(const float value) {
    std::cout << GREEN << "| Float constructor called           |" << RESET << std::endl;
    this->_value = roundf(value * (1 << this->_fractionalBits));
}




Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << GREEN << "| Assignation operator called        |" << RESET << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

//member functions
float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractionalBits);
}
int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

int Fixed::getRawBits() const {
    std::cout << BLUE << "| getRawBits member function called  |" << RESET << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << BLUE << "| setRawBits member function called  |" << RESET << std::endl;
    this->_value = raw;
}


