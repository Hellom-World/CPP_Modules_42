#include "Dog.hpp"
#include "Cat.hpp"


void subMain()
{
    std::cout << "-------start SUBMAIN--------------" << std::endl;
    Brain b1;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; //não deve criar um vazamento
    delete i;

    return;
}

void subMandatory(int n)
{
    std::cout << "-------start SUBMANDATORY----------" << std::endl;
    Animal *animals[n];

    for (int i = 0; i < (n); i++)
    {
        std::cout << "id: " << i << " - ";
        if (i > i / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }


    for (int i = 0; i < n; i++)
    {
        std::cout << "id: " << i << " - ";
        delete animals[i];
    }

    std::cout << "------------------------------------" << std::endl << std::endl;
    std::cout << "-------TEST-COPY-CONSTRUCTOR--------" << std::endl;

    std::cout << "v------DOG a----------v" << std::endl;
    const Dog* a = new Dog();
    {
        std::cout << "v------DOG d----------v" << std::endl;
        Dog d = *a;
        d.makeSound();
    }
    std::cout << "v------DOG b----------v" << std::endl;
    Dog b = *a;
    std::cout << "v------DOG c----------v" << std::endl;
    Dog c(b);
    std::cout << "v------Ideas----------v" << std::endl;
    std::cout <<"DOG a idea: "<< a->getBrainIdea(0) << std::endl;
    std::cout <<"DOG b idea: "<< b.getBrainIdea(0) << std::endl;
    std::cout <<"DOG c idea: "<< c.getBrainIdea(0) << std::endl;
    a->setBrainIdea(0, "Acho que sou um cachorro");
    std::cout <<"DOG a idea: "<< a->getBrainIdea(0) << std::endl;
    std::cout <<"DOG b idea: "<< b.getBrainIdea(0) << std::endl;
    std::cout <<"DOG c idea: "<< c.getBrainIdea(0) << std::endl;

    //a->meditation();
    std::cout << "v------Destructor------v" << std::endl;
    delete a;
    return;
}

int main()
{
    subMain();
    std::cout << "-----------------------------------" << std::endl << std::endl;
    subMandatory(4);

    return 0;
}

