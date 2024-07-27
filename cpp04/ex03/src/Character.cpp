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
        name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    std::cout << "Character getName"<< _name << std::endl;
    return _name;
}

void Character::equip(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = materia;
            std::cout << "AMateria " << materia->getType() << " equipped" << std::endl;
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
