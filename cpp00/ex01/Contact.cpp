#include "Contact.hpp"

void printMenu() {
	std::cout <<"\n	**** WELCOME TO PHONEBOOK **** \n" << std::endl;
	std::cout << "ADD	- to add a new contact" << std::endl;
	std::cout << "SEARCH	- to search a contact" << std::endl;
	std::cout << "EXIT	- to exit the phonebook" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}

void Contact::setFirstName(std::string n) {
  this->firstName = n;
}
void Contact::setLastName(std::string ln) {
  this->lastName = ln;
}
void Contact::setNickName(std::string nn) {
  this->nickName = nn;
}
void Contact::setPhoneNumber(std::string pn) {
  this->phoneNumber = pn;
}
void Contact::setDarkestSecret(std::string pn) {
  this->darkestSecret = pn;
}



std::string	Contact::getFirstName(void) {
	return (this->firstName);
}
std::string	Contact::getLastName(void) {
	return (this->lastName);
}
std::string	Contact::getNickName(void) {
	return (this->nickName);
}
std::string	Contact::getPhoneNumber(void) {
	return (this->phoneNumber);
}
std::string	Contact::getDarkestSecret(void) {
	return (this->darkestSecret);
}

//Auxiliar Functions

bool validate_input(const std::string& input, int flag) {
    // Verifica se o input está vazio
    if (input.empty())
        return false;

	  if (flag == 1 || flag == 11) {
				// Verifica se o input contém apenas números
				if (flag == 11) {
					for (size_t i = 0; i < input.length(); ++i) {
						if (!std::isdigit(input[i]))
								return false;
					}
				}
				if (flag == 1){
					for (size_t i = 0; i < input.length(); ++i) {
							if (!std::isdigit(input[i]) || input.length() != 9)
									return false;
					}
				}
		}
		if (flag == 2) {
			// Verifica se o input contém apenas letras e espaços
			for (size_t i = 0; i < input.length(); ++i) {
					if (!std::isalpha(input[i]))
							return false;
			}
		}

    return true;
}

void get_valid_input(std::istream& in, std::string& input, int flag) {

	do {
		std::getline(in, input); // Obtém a linha completa, incluindo espaços
		if (!validate_input(input, flag)) {
			if (flag == 1)
				std::cout << "\nEntrada inválida, digite um número de telefone válido (9 dígitos):" << std::endl;
			else if (flag == 2)
				std::cout << "\nEntrada inválida, digite apenas letras:" << std::endl;
		}
	} while (!validate_input(input, flag)); // Repete até que o input seja válido
}