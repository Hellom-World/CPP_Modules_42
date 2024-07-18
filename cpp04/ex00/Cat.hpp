#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat();

        // Copy constructor and parameterized constructor
        Cat(const Cat& copy);
        Cat(std::string type);

        Cat& operator=(const Cat& other);

        virtual void makeSound() const;
};

#endif
