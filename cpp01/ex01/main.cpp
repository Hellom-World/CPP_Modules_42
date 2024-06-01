#include "Zombie.hpp"

int main(int argc, char **argv) {

  int n_zombies = 5;
  Zombie* horde;

  if (argc != 1) {
    std::cout << "\033[1;31mUsage: " << argv[0] << "\033[0m" << std::endl;
    return 1;
  }

  Zombie* heapZombie = newZombie("Jhonata");
  if (!heapZombie) {
    std::cout << "\033[1;31mError: could not create zombie\033[0m" << std::endl;
    return 1;
  }

  heapZombie->announce();
  delete heapZombie;

  horde = zombieHorde(n_zombies, "VICTTOR");
  if (!horde) {
    std::cout << "\033[1;31mError: could not create horde\033[0m" << std::endl;
    return 1;
  }

  for (int i = 0; i < n_zombies; i++) {
    horde[i].announce();
  }
  //Necessario deletar o array de zombies pois ele foi criado com new.
  delete[] horde;

  return 0;
}
