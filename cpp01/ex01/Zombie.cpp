#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << "\033[1;31m" << this->_name << " is destroyed" << "\033[0m" << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::announce() const {
    std::cout << "\033[1;32m" << this->_name << ": BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}

