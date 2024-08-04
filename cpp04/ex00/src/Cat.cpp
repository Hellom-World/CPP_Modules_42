#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
};

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat "<< _type << " constructor called" << std::endl;
};

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
};

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
};

void Cat::makeSound() const
{
    std::cout << "Cat sound: Meow Meow" << std::endl;
};
