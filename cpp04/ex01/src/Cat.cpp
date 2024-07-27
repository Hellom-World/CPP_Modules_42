#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
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
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    _brain = new Brain(*other._brain);
    return *this;
};

void Cat::makeSound() const
{
    std::cout << "Cat sound: HAU HAU HAU!" << std::endl;
};

void Cat::setBrainIdea(int index, std::string idea)
{
    _brain->setIdea(index, idea);
};

void Cat::getBrainIdea(int index) const
{
    _brain->getIdea(index);
};

void Cat::meditation() const
{
    for (int i = 0; i < 100; i++)
        std::cout << _type << " Idea " << i << ": " << _brain->getIdea(i) << std::endl;
};
