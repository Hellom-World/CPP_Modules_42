#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}
/*Zombie::Zombie(std::string name) {
    _name = name;
}*/

Zombie::~Zombie() {
    std::cout << "\033[1;31m" << _name << " is destroyed" << "\033[0m" << std::endl;
}

void Zombie::announce() const {
    std::cout << "\033[1;32m" << _name << ": BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}
