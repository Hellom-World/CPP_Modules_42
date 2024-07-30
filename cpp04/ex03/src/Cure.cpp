#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
    std::cout << "Cure copy constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure assignation operator" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Cure::Cure(std::string type) : AMateria(type)
{
    std::cout << "Cure parameterized constructor" << std::endl;
}

AMateria* Cure::clone() const
{
    std::cout << "Cure clone" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "Cure used on " << target.getName() << std::endl;
}
