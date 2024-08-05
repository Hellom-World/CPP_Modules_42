#include "../include/Brain.hpp"

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

std::string Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "Index out of range < 0 ~ 100 >" << std::endl;
        return "Invalid index";
    }
    _ideas[index] = idea;
    std::cout << "Idea \"" << idea << "\" set at index " << index << std::endl;
    return _ideas[index];
};
std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        return "Index out of range < 0 ~ 100 >";
    }
    std::cout << "Get Idea! index " << index << std::endl;
    return _ideas[index];
};
