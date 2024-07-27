#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        ~WrongAnimal();

        // Copy constructor and parameterized constructor
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal(std::string type);

        WrongAnimal& operator=(const WrongAnimal& other);

        void makeSound() const;
        std::string getType() const;
};

#endif
