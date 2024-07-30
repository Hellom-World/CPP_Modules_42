#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

// Cure é uma classe que representa uma matéria de cura que pode ser equipada por um personagem
// e que pode ser usada para lançar feitiços de cura em um alvo (ICharacter)
// Cure é uma classe derivada de AMateria.

class Cure : public AMateria
{
    public:
        Cure();
        virtual ~Cure();

        Cure(const Cure& copy);
        Cure& operator=(const Cure& other);

        Cure(std::string type);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
