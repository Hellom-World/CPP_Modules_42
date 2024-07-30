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

// O metodo use é um metodo virtual puro, utilizado para lançar feitiços em um alvo (ICharacter)
// O método use é implementado nas classes filhas Ice e Cure e utilizado na classe Character
// para lançar feitiços em um alvo (ICharacter)
void AMateria::use(ICharacter& target)
{
    std::cout << "used " << _type << " on " << target.getName() << std::endl;
}

// O método clone é um método virtual puro que é implementado nas classes filhas Ice e Cure
