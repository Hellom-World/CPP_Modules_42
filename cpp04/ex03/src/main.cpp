#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"


void  submain()
{
      std::cout << "------Main test-------" << std::endl;
      IMateriaSource* src = new MateriaSource();
      src->learnMateria(new Ice());
      src->learnMateria(new Cure());
      ICharacter* me = new Character("me");
      AMateria* tmp;
      tmp = src->createMateria("ice");
      me->equip(tmp);
      std::cout << "--------------------------------------" << std::endl;
      tmp = src->createMateria("cure");
      std::cout << "--------------------------------------" << std::endl;
      me->equip(tmp);
      std::cout << "--------------------------------------" << std::endl;
      ICharacter* bob = new Character("bob");
      me->use(0, *bob);
      me->use(1, *bob);
      std::cout << "--------------------------------------" << std::endl;
      delete bob;
      delete me;
      delete src;
      std::cout << "-----------Finish submain()----------------" << std::endl;
      std ::cout << "                  |                   " << std::endl;
      return;
}
void mymain()
{
      std::cout << "------Creating AMateria objects-------" << std::endl;
      AMateria* ice = new Ice();
      AMateria* cure = new Cure();
      std::cout << "     *            *             *     " << std::endl;
      AMateria* ice2 = new Ice("ice3");
      AMateria* cure2 = new Cure("cure3");
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;

      std::cout << "--Testing getType method on material--" << std::endl;
      std::cout << "Ice type: " << ice->getType() << std::endl;
      std::cout << "Cure type: " << cure->getType() << std::endl;
      std::cout << "Ice2 type: " << ice2->getType() << std::endl;
      std::cout << "Cure2 type: " << cure2->getType() << std::endl;
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;

      std::cout << "------Testing clone method on material-------" << std::endl;
      AMateria* ice3 = ice->clone();
      AMateria* cure3 = cure->clone();
      AMateria* ice4 = ice2->clone();
      AMateria* cure4 = cure2->clone();
      std::cout << "Ice3 type: " << ice3->getType() << std::endl;
      std::cout << "Cure3 type: " << cure3->getType() << std::endl;
      std::cout << "Ice4 type: " << ice4->getType() << std::endl;
      std::cout << "Cure4 type: " << cure4->getType() << std::endl;
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Create Character objects-------" << std::endl;
      Character* iron = new Character("IronMan");
      Character* spider = new Character("SpiderMan");
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing equip method on Character-------" << std::endl;
      iron->equip(ice);
      iron->equip(cure);
      iron->equip(ice2);
      iron->equip(ice3);
      iron->equip(cure2);
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing reuse alocked materia-------" << std::endl;
      spider->equip(ice);
      spider->equip(cure);
      spider->equip(ice2);
      spider->equip(cure2);
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing view inventory of Character-------" << std::endl;
      iron->getInventory();
      spider->getInventory();
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing use method on Character-------" << std::endl;
      iron->use(0, *spider);
      iron->use(1, *spider);
      spider->use(0, *iron);
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing unequip method on Character-------" << std::endl;
      iron->unequip(0);
      iron->unequip(1);
      iron->unequip(2);
      iron->unequip(3);
      iron->unequip(5);
      spider->unequip(0);
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing delete Character objects-------" << std::endl;
      delete iron;
      delete spider;
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;
      std::cout << "------Testing delete AMateria objects-------" << std::endl;
      delete ice;
      delete cure;
      delete ice2;
      delete cure2;
      delete ice3;
      delete cure3;
      delete ice4;
      delete cure4;
      std::cout << "--------------------------------------" << std::endl;
      return;
}

int main(void)
{

      submain();
      mymain();
      return 0;
}
