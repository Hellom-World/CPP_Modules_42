#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        //~Animal();

        // Copy constructor and parameterized constructor
        Animal(const Animal& copy);
        Animal(std::string type);

        Animal& operator=(const Animal& other);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif
