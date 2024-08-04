#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_sources[i])
            delete _sources[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_sources[i])
                delete _sources[i];
            _sources[i] = other._sources[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_sources[i])
        {
            _sources[i] = materia;
            return;
        }
    }
    if (materia)
        delete materia;

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_sources[i] && _sources[i]->getType() == type)
        {
            return _sources[i]->clone();
        }
    }
    std::cout << "slot is full" << std::endl;
    return NULL;
}

