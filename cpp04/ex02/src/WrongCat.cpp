#include "../include/WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
};

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat "<< _type << " constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
};

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
};

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound: MIOOOOOOOWN!" << std::endl;
};
