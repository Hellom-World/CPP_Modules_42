#include "Dog.hpp"
#include "Cat.hpp"


void subMain()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; //não deve criar um vazamento
    delete i;
}

int main()
{
    subMain();

    return 0;
}

