#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

// AMateria é uma Classe abstrata que representa uma matéria que pode ser equipada por um personagem
// e que pode ser usada para lançar feitiços em um alvo (ICharacter)
// AMateria é uma classe abstrata que contém um tipo de matéria e um método use que
// é virtual puro. AMateria é a classe base para Ice e Cure.


class ICharacter;
class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        virtual ~AMateria();
        //~AMateria();

        // Copy constructor and parameterized constructor
        AMateria(const AMateria& copy);
        AMateria(std::string type);

        AMateria& operator=(const AMateria& other);

        std::string const & getType() const; //Retorna o tipo da matéria

        virtual AMateria* clone() const = 0;
        // Erro ICharacter was not declared
        // Para
        virtual void use(ICharacter& target);
};

#endif
