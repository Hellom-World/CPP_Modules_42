#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
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
