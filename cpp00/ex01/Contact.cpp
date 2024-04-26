/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:01 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:23:05 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (flag == 4) {
			// Verifica se o input contém apenas letras e espaços
			for (size_t i = 0; i < input.length(); ++i) {
					if (std::isspace(input[i]))
							return false;
			}
		}

    return true;
}

bool get_valid_input(std::istream& in, std::string& input, int flag) {

	int count = -1;
	do {
		std::getline(in, input); // Obtém a linha completa, incluindo espaços

  	if (std::cin.eof())
		{
			std::cout << "\nNot Today!" << std::endl;
			exit(0);
		}
		if (!validate_input(input, flag)) {
			
			if (flag == 1)
				std::cout << "\nInvalid entry, please enter a valid phone number (9 digits):" << std::endl;
			else if (flag == 2)
				std::cout << "\nInvalid entry, enter letters only:" << std::endl;
			else if (flag == 3)
				std::cout << "\nEntry cannot be empty:" << std::endl;
			else if (flag == 4)
				std::cout << "\nInvalid entry, space not allowed:" << std::endl;
			if (count == 2) {
				return false;
			}
		}
	} while (!validate_input(input, flag) && ++count < 3); // Repete até que o input seja válido
	return true;
}

// Função para formatar uma coluna para ter 10 caracteres de largura e truncar o texto se for maior
std::string formatColumn(const std::string& text) {
    if (text.length() <= 10) {
        return text;
    } else {
        return text.substr(0, 9) + ".";
    }
}

int my_stoi(const std::string& s) {
		int result = 0;
		for (size_t i = 0; i < s.length(); ++i) {
				result = result * 10 + s[i] - '0';
		}
		return result;
}
