#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    std::cout << "------Create Animal-------" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "------Create Dog-------" << std::endl;
    const Animal* j = new Dog();
    std::cout << "------Create Cat-------" << std::endl;
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
    std::cout << "--------Delete Dog-------" << std::endl;
    delete j;
    std::cout << "--------Delete Cat-------" << std::endl;
    delete i;
    std::cout << "--------Delete WrongCat-------" << std::endl;
    delete k;
    std::cout << "--------Delete WrongCat-------" << std::endl;
    delete l;

    return 0;
}
