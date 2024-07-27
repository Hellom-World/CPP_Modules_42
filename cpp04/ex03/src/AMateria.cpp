#include "../include/AMateria.hpp"

AMateria::AMateria()
{
    std::cout <<  "AMateria default constructor" << std::endl;
    _type = "default";
}

AMateria::~AMateria()
{
    std::cout <<  "AMateria destructor" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
    std::cout <<  "AMateria copy constructor" << std::endl;
    *this = copy;
}

AMateria::AMateria(std::string type)
{
    std::cout <<  "AMateria parameterized constructor" << std::endl;
    _type = type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout <<  "AMateria assignation operator" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}

// Use é um método virtual puro, então é necessário implementar nas classes filhas
// Ele foi implementado aqui pois deriva da interface ICharacter que não foi implementada
void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << _type << " used on " << target.getName() << std::endl;
}

// para implementar o método clone, é necessário implementar o método clone nas classes filhas
