#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

// A classe Character é uma classe que representa um personagem que pode equipar até 4 matérias
// e que pode usar essas matérias em um alvo (ICharacter)
// Character é a classe derivada de ICharacter.
class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    // [...]

public:
    // construtores, destrutores e métodos da classe
    Character(std::string name);
    Character(Character const &);
    Character& operator=(Character const &);
    ~Character();

    std::string const & getName() const;
    void getInventory() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


#endif
