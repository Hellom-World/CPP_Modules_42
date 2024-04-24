#include "Phonebook.hpp"

int main() {
    PhoneBook   pb;
    std::string comando;

    while (true) {
        std::cout << "\n              CONTACTS COUNT [" << pb.getContactsCount() << "]";
        printMenu();
        std::cin >> comando;

        // Transformar o comando para maiúsculas
        for (size_t i = 0; i < comando.length(); ++i) {
            comando[i] = std::toupper(static_cast<unsigned char>(comando[i])); // static_cast é usado para lidar com valores negativos de char
        }
        // Condições para os comandos
        if (comando == "ADD") {
            pb.addContact(); // Aqui entra a logica para o comando ADD
        } else if (comando == "SEARCH") {
            pb.searchContact(); // Aqui entra a Lógica para o comando SEARCH
        } else if (comando == "EXIT") {
            std::cout << "Saindo do programa...\n";
            break; // Comando para sair do loop
        } else {
            std::cout << "Comando inválido. Tente novamente.\n";
        }
    }

    return 0;
}
