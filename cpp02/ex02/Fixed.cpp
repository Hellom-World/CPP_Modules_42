#include "Fixed.hpp"

//Constructor Padrao e destructor
Fixed::Fixed() {
    this->_value = 0;
}

//Construtor de copia
Fixed::Fixed(const Fixed &src) {
  *this = src;
}
//Construtor com int
Fixed::Fixed(const int value) {
    this->_value = value << this->_fractionalBits;
}
//Construtor com float
Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
}


//Overload operators comparison

Fixed &Fixed::operator=(const Fixed &src) {
    if (this != &src)
        this->_value = src.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &src) const {
    return this->_value > src.getRawBits();
}
bool Fixed::operator<(const Fixed &src) const {
    return this->_value < src.getRawBits();
}
bool Fixed::operator>=(const Fixed &src) {
    return this->_value >= src.getRawBits();
}
bool Fixed::operator<=(const Fixed &src) {
    return this->_value <= src.getRawBits();
}
bool Fixed::operator==(const Fixed &src) {
    return this->_value == src.getRawBits();
}
bool Fixed::operator!=(const Fixed &src) {
    return this->_value != src.getRawBits();
}

//Overload operators arithmetic
Fixed Fixed::operator+(const Fixed &src) {
    return Fixed(this->toFloat() + src.toFloat());
}
Fixed Fixed::operator-(const Fixed &src) {
    return Fixed(this->toFloat() - src.toFloat());
}
Fixed Fixed::operator*(const Fixed &src) {
    return Fixed(this->toFloat() * src.toFloat());
}
Fixed Fixed::operator/(const Fixed &src) {
    return Fixed(this->toFloat() / src.toFloat());
}

//increment and decrement
Fixed &Fixed::operator++(void) {
    this->_value++;
    return *this;
}
Fixed &Fixed::operator--(void) {
    this->_value--;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

//min and max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

//member functions
float Fixed::toFloat(void) const {
    return (float)(this->_value) / (1 << this->_fractionalBits);
}
int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

int Fixed::getRawBits() const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}


