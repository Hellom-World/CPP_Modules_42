#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        virtual ~Dog();

        // Copy constructor and parameterized constructor
        Dog(const Dog& copy);
        Dog(std::string type);

        Dog& operator=(const Dog& other);

        virtual void makeSound() const;
        void setBrainIdea(int index, std::string idea) const;
        std::string getBrainIdea(int index) const;
        void meditation() const;

};

#endif
