#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie * heapZombie = new Zombie;
    if (!heapZombie)
        return NULL;
    heapZombie->setName(name);
    return heapZombie;
}
