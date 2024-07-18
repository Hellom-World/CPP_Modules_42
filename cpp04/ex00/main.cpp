#include "Animal.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    //const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    //std::cout << i->getType() << " " << std::endl;
    //i->makeSound(); //deve imprimir o som do gato!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;

    return 0;
}
