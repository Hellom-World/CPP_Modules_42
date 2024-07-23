#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
};

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
};

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
};

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
};

Brain::Brain(std::string type)
{
    std::cout << "Brain parameterized constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = type;
};



