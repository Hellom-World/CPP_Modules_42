/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:16 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:23:21 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main() {
    PhoneBook   pb;
    std::string comando;

    std::cout << "\n              CONTACTS COUNT [" << pb.getContactsCount() << "]";
    printMenu();
    while (true) {

        std::getline(std::cin, comando);

        // Transformar o comando para maiúsculas
        for (size_t i = 0; i < comando.length(); ++i)
            comando[i] = std::toupper(static_cast<unsigned char>(comando[i])); // static_cast é usado para lidar com valores negativos de char
        
        // Condições para os comandos
        if (comando == "ADD") {
            pb.addContact(); // Aqui entra a logica para o comando ADD
            std::cout << "\n              CONTACTS COUNT [" << pb.getContactsCount() << "]";
            printMenu();
        } else if (comando == "SEARCH") {
            pb.searchContact(); // Aqui entra a Lógica para o comando SEARCH
            std::cout << "\n              CONTACTS COUNT [" << pb.getContactsCount() << "]";
            printMenu();
        } else if (comando == "EXIT") {
            std::cout << "leaving the program...\n";
            break; // Comando para sair do loop
        } else if (comando != ""){
            std::cout << "Invalid command. Try again.\n";
            std::cout << "\n              CONTACTS COUNT [" << pb.getContactsCount() << "]";
            printMenu();
        }
        
    }
    return 0;
}
