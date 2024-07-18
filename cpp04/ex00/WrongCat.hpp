#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();

        // Copy constructor and parameterized constructor
        WrongCat(const WrongCat& copy);
        WrongCat(std::string type);

        WrongCat& operator=(const WrongCat& other);

        void makeSound() const;
};

#endif
