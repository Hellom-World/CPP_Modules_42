#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    std::cout << "------Create Animal-------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();
    const WrongCat* l = new WrongCat();
    std::cout << std::endl;


    std::cout << "---------getType----------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << "--------makeSound---------" << std::endl;
    i->makeSound(); //deve imprimir o som do gato!
    j->makeSound();
    std::cout << j->Animal::getType() << std::endl;
    j->Animal::makeSound();
    k->makeSound();
    l->makeSound();
    l->WrongAnimal::makeSound();
    meta->makeSound();
    std::cout << std::endl;

    std::cout << "--------Delete Animal-------" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;

    return 0;
}
