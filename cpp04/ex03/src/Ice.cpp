#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
    std::cout << "Ice copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice assignation operator" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Ice::Ice(std::string type) : AMateria(type)
{
    std::cout << "Ice parameterized constructor" << std::endl;
}

AMateria* Ice::clone() const
{
    std::cout << "Ice clone" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
