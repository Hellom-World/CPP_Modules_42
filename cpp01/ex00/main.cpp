#include "Zombie.hpp"

int main(int argc, char **argv) {

  if (argc != 1) {
    std::cout << "\033[1;31mUsage: " << argv[0] << "\033[0m" << std::endl;
    return 1;
  }
  Zombie* heapZombie = newZombie("Jhonata");
  heapZombie->announce();
  delete heapZombie;

  randomChump("Pedro");
  randomChump("David");

  return 0;
}


//Esse exercicio é bem simples, ele pede para criar um programa que crie um zombie na stack e outro na heap, e que ambos printem uma mensagem na tela.

//Para isso, eu criei um arquivo Zombie.hpp e um arquivo Zombie.cpp, no arquivo .hpp eu declarei a classe Zombie e as funções newZombie e randomChump, e no arquivo .cpp eu implementei essas funções.

//No arquivo main.cpp eu inclui o arquivo Zombie.hpp e criei um zombie na heap e outro na stack, e chamei a função announce de ambos.

//O programa funciona da seguinte forma, ele cria um zombie na heap e outro na stack, e chama a função announce de ambos, que printa uma mensagem na tela.

//Depois ele deleta o zombie da heap e o programa termina.
