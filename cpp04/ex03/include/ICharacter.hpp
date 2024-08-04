#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;
// A classe Icharacter é uma interface que parametriza de forma obrigatória os métodos que
// devem ser implementados por uma classe que deseja ser um personagem.
// Por se tratar de uma interface, todos os métodos são virtuais puros.
// Ou seja, a classe que herdar de ICharacter é obrigada a implementar os métodos da interface.
// ICharacter é a classe base para Character.
class ICharacter
{
public:
    virtual ~ICharacter(); // Destrutor on the Chraracter.cpp
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif
