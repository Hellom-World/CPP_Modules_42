#include <iostream>
#include "tempo.h"

int main() {
    Tempo padrao1;
    Tempo custom(11, 20, 36);

    std::cout << "Hora padrao: ";
    padrao1.imprime();

    std::cout << "\nHora customizada: ";
    custom.imprime();

    padrao1.setTempo(110, 25, 00);
    std::cout << "\nHora Atualizada: ";
    padrao1.imprime();

    std::cout << "\n";
    return 0;
}