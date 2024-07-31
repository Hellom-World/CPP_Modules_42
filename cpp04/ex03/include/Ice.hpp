#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// Ice é uma classe que representa uma matéria de gelo que pode ser equipada por um personagem
// e que pode ser usada para lançar feitiços de gelo em um alvo (ICharacter)
// Ice é uma classe derivada de AMateria.

class Ice : public AMateria
{
    public:
        Ice();
        virtual ~Ice();

        Ice(const Ice& copy);
        Ice& operator=(const Ice& other);

        Ice(std::string type);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
