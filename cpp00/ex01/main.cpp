#include <iostream>
#include <string>
#include <cctype>

class Contact {
    // Atributos
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        // Construtores e Destrutores
        Contact();
        ~Contact();
        // Métodos
        void addContact();
        void searchContact();
        void printContact();
};

void Contact::addContact() {
    std::cout << "Adicionando contato...\n";
}

class PhoneBook {
    // Atributos
    private:
        Contact contacts[8];
    public:
        // Construtores e Destrutores
        PhoneBook();
        ~PhoneBook();
        // Métodos
        void addContact();
        void searchContact();
        void printContact();
        void printContacts();
};

void printMenu() {
	std::cout <<"\n	**** WELCOME TO PHONEBOOK **** \n" << std::endl;
	std::cout << "ADD	- to add a new contact" << std::endl;
	std::cout << "SEARCH	- to search a contact" << std::endl;
	std::cout << "EXIT	- to exit the phonebook" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}

int main() {
    std::string comando;

    printMenu();
    while (true) {
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
