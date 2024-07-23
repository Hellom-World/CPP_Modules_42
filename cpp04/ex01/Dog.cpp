#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    _brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
};

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog "<< _type << " constructor called" << std::endl;
};

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
};

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
};

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
};

void Dog::makeSound() const
{
    std::cout << "Dog sound: HAU HAU HAU!" << std::endl;
};
