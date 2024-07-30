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
      AMateria* ice2 = new Ice("ice");
      AMateria* cure2 = new Cure("cure");
      std::cout << "--------------------------------------" << std::endl;
      std::cout << "                  |                   " << std::endl;

      std::cout << "--Testing getType method on material--" << std::endl;
      std::cout << "Ice type: " << ice->getType() << std::endl;
      std::cout << "Cure type: " << cure->getType() << std::endl;
      std::cout << "Ice2 type: " << ice2->getType() << std::endl;
      std::cout << "Cure2 type: " << cure2->getType() << std::endl;
      std::cout << "--------------------------------------" << std::endl;
      Character* iron = new Character("IronMan");
      Character* spider = new Character("SpiderMan");
      iron->equip(ice);
      iron->use(0, *spider);
      iron->unequip(0);

      delete iron;
      delete spider;
      delete ice;
      delete cure;
      delete ice2;
      delete cure2;

      return 0;


}
