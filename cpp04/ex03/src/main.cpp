#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

int main(void)
{
    Character* me = new Character("me");
    std::cout << me->getName() << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << bob->getName() << std::endl;
    AMateria* tmp = new Ice();
    me->equip(tmp);
    me->use(0, *bob);
    delete bob;
    delete me;
    return 0;
}
