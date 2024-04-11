#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string comando;

    while (true) {
        std::cout << "Digite um comando (ADD, SEARCH ou EXIT): ";
        std::cin >> comando;

        // Transformar o comando para maiúsculas
        for (size_t i = 0; i < comando.length(); ++i) {
            comando[i] = std::toupper(static_cast<unsigned char>(comando[i])); // static_cast é usado para lidar com valores negativos de char
        }
        // Condições para os comandos
        if (comando == "ADD") {
            std::cout << "Comando ADD inserido.\n";
            // Aqui entra a logica para o comando ADD
        } else if (comando == "SEARCH") {
            std::cout << "Comando SEARCH inserido.\n";
            // Aqui entra a Lógica para o comando SEARCH
        } else if (comando == "EXIT") {
            std::cout << "Saindo do programa...\n";
            break; // Comando para sair do loop
        } else {
            std::cout << "Comando inválido. Tente novamente.\n";
        }
    }

    return 0;
}
