#include "Zombie.hpp"

int main(int argc, char **argv) {

  if (argc != 1) {
    std::cout << "\033[1;31mUsage: " << argv[0] << "\033[0m" << std::endl;
    return 1;
  }
  Zombie* heapZombie = newZombie("Jhonata");
  heapZombie->announce();
  delete heapZombie;

  randomChump("Victtor");

  return 0;
  
}
