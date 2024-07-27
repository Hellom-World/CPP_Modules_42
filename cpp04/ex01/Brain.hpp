#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        virtual ~Brain();

        // Copy constructor and parameterized constructor
        Brain(const Brain& copy);
        Brain(std::string type);
        virtual void imagine() const;

        Brain& operator=(const Brain& other);

        std::string setIdea(int index, std::string idea);
        std::string getIdea(int index) const;


};

#endif
