#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}


void HumanB::attack() {
  if (_weapon == NULL)
  {
    std::cout << _name << " attacks with his bare hands" << std::endl;
  }
  else
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
  _weapon = &weapon;
}

HumanB::~HumanB() {}

