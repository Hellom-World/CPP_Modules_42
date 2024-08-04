#include "../include/AMateria.hpp"

AMateria::AMateria()
{
    std::cout <<  "AMateria default constructor" << std::endl;
    _locked = false;
    _type = "default";
}

AMateria::~AMateria()
{
    _locked = false;
    std::cout <<  "AMateria destructor" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
    std::cout <<  "AMateria copy constructor" << std::endl;
    *this = copy;
}

AMateria::AMateria(std::string type)
{
    if (type != "ice" && type != "cure")
        _type = "default";
    std::cout <<  "AMateria parameterized constructor" << std::endl;
    _locked = false;
    _type = type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout <<  "AMateria assignation operator" << std::endl;
    if (this != &other )
    {
        _type = other._type;
        _locked = other._locked;
    }

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
bool AMateria::getIsLocked(const AMateria& materia) const
{
    if (materia._locked == true)
    {
        std::cout << "Materia is locked: " << materia._locked << std::endl;
        return materia._locked;
    }
    else
    {
        std::cout << "Materia is not locked: " << materia._locked << std::endl;
        return materia._locked;
    }
}

void AMateria::setLockMateria(bool locked)
{
    if (locked == true)
    {
        std::cout << "Material was locked" << std::endl;
        _locked = true;
    }
    else
    {
        std::cout << "Material has been unlocked" << std::endl;
        _locked = false;
    }
}
