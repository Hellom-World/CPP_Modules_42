#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"


int main(void)
{
      std::cout << "------Creating AMateria objects-------" << std::endl;
      AMateria* ice = new Ice();
      AMateria* cure = new Cure();
      std::cout << "     *            *             *     " << std::endl;
      AMateria* ice2 = new Ice("ice1");
      AMateria* cure2 = new Cure("cure2");
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
      std::cout << "------Testing use method on material-------" << std::endl;
      Character* iron = new Character("IronMan");
      Character* spider = new Character("SpiderMan");
      iron->equip(ice);
      iron->equip(cure);
      iron->equip(ice2);
      iron->equip(cure2);
      iron->equip(ice3);
      iron->getInventory();
      iron->use(0, *spider);
      iron->use(1, *spider);
      iron->getInventory();
      iron->unequip(0);
      iron->unequip(1);

      delete iron;
      delete spider;
      delete ice;
      delete cure;
      delete ice2;
      delete cure2;
      std::cout << "--------------------------------------" << std::endl;
      delete ice3;
      delete cure3;
      delete ice4;
      delete cure4;

      return 0;


}
