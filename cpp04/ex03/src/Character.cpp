#include "../include/Character.hpp"

Character::Character(std::string name)
{
    std::cout << "Character default constructor" << std::endl;
    this->_name = name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const & copy)
{
    std::cout << "Character copy constructor" << std::endl;
    *this = copy;
}

Character& Character::operator=(Character const & other)
{
    std::cout << "Character assignation operator" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor" << std::endl;

}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* materia)
{
    if (materia->getType() != "ice" && materia->getType() != "cure")
    {
        std::cout << "Not equiped invalid materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = materia;
            std::cout << "AMateria " << materia->getType() << " equipped in " << this->_name << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
    std::cout << "Inventory slot " << idx << " is empty" << std::endl;
}

void Character::getInventory() const
{
    std::cout << "---------Inventory--------" << std::endl;
    std::cout << "| Character: " << _name.substr(0, 7) << "     |" << std::endl;
    std::cout << "| Slots      |0||1||2||3||" << std::endl;
    std::cout << "| Materials: ";
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] && _inventory[i]->getType() == "ice")
            std::cout << "|*|";
        else if (_inventory[i] && _inventory[i]->getType() == "cure")
            std::cout << "|+|";
        else
            std::cout << "|x|";
    }
    std::cout << "|";
    std::cout << std::endl << "--------------------------" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        std::cout << this->_name << " ";
       _inventory[idx]->use(target);
    }
    else
    {
        std::cout << "Inventory slot " << idx << " is empty" << std::endl;
    }
}
