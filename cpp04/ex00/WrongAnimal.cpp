#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default")
{
    std::cout << "WrongAnimal " << _type << " constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal "<< _type << " constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
};

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << _type << " destructor called" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
};

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
};

std::string WrongAnimal::getType() const
{
    return _type;
};

std::ostream &operator<<(std::ostream &out, WrongAnimal const &other)
{
    out << other.getType();
    return out;
}

