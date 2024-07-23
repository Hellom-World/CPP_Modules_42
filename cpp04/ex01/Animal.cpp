#include "Animal.hpp"

Animal::Animal() : _type("default")
{
    std::cout << "Animal " << _type << " constructor called" << std::endl;
};

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal "<< _type << " constructor called" << std::endl;
};

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
};

Animal::~Animal()
{
    std::cout << "Animal " << _type << " destructor called" << std::endl;
};

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
};

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
};

std::string Animal::getType() const
{
    return _type;
};
