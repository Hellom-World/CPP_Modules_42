#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;
class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _sources[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();

        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& other);

        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const & type);
};

#endif
