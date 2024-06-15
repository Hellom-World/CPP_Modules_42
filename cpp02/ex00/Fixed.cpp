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



Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << GREEN << "| Assignation operator called        |" << RESET << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << BLUE << "| getRawBits member function called  |" << RESET << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << BLUE << "| setRawBits member function called  |" << RESET << std::endl;
    this->_value = raw;
}


