/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:37 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:23:41 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


PhoneBook::PhoneBook() {
    this->index = 0;
		this->contactsCount = 0;
    this->maxContacts = 8;
    this->nextIndexToReplace = 0;
}



//---------------------------------------FORM_CONTACT--------------------------------------------------------------------------------------/
void PhoneBook::addContact() {  

  std::string firstName;
  std::cout << "Enter first name: ";
  if (!get_valid_input(std::cin, firstName, 2)){
    std::cout << "Number of attempts exceeded." << std::endl;
    return;  
  }
  
  std::cout << "Enter last name: ";
  std::string lastName;
  if (!get_valid_input(std::cin, lastName, 2)){ 
    std::cout << "Number of attempts exceeded." << std::endl;
    return;  
  }

  std::cout << "Enter nickname: ";
  std::string nickName;
  if (!get_valid_input(std::cin, nickName, 4)){ 
    std::cout << "Number of attempts exceeded." << std::endl;
    return;  
  }

  std::cout << "Enter phone number: ";
  std::string phoneNumber;
  if (!get_valid_input(std::cin, phoneNumber, 1)){ 
    std::cout << "Number of attempts exceeded." << std::endl;
    return;  
  }

  std::cout << "Enter darkest secret: ";
  std::string darkestSecret;
  if (!get_valid_input(std::cin, darkestSecret, 3)){ 
    std::cout << "Number of attempts exceeded." << std::endl;
    return;  
  }
//-------------------------------------------SET_CONTACT------------------------------------------------------------------------------------/
  Contact newContact;
  newContact.setFirstName(firstName);
  newContact.setLastName(lastName);
  newContact.setNickName(nickName);
  newContact.setPhoneNumber(phoneNumber);
  newContact.setDarkestSecret(darkestSecret);

  int contactsCount = getContactsCount();
  // Adicionar o novo contato ao vetor contacts
  if (contactsCount >= getMaxContacts()) { // Verifica se há espaço no vetor
    if (getNextIndexToReplace() >= 8) {
      setNextIndexToReplace(0);
    } 
    contacts[nextIndexToReplace] = newContact;
    nextIndexToReplace = (nextIndexToReplace + 1) % 8;
  } else {
    // Criar um novo objeto Contact com as informações inseridas
    contacts[contactsCount] = newContact;
    setContactsCount(contactsCount + 1);
    std::cout << "\nNew contact added successfully!\n" << std::endl;
  }
//------------------------------------------------------------------------------------------------------------------------------------------/
}


void PhoneBook::searchContact() {
  
  printContacts();
  std::string index;
  if (getContactsCount() == 0)
    return;
  std::cout << "\nEnter the index of the contact you want to view: ";
  std::cin >> index;
  if (std::cin.eof())
  {
    std::cout << "\nNot Today!" << std::endl;
    exit(0);
  }
  int i = my_stoi(validate_input(index, 11) ? index : "-1");

  if (i < 0 || i >= getContactsCount()) {
    std::cout << "Invalid index. Try again." << std::endl;
    searchContact();
  } else {
    // Exibir as informações do contato
    std::cout << "\nFirst Name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << std::endl;
  }
}

void PhoneBook::printContacts() {
  std::cout << "\n----------------------CONTACTS-------------------------" << std::endl;
  std::cout << "|  INDEX   |  FIRST NAME  |  LAST NAME  |  NICKNAME   |" << std::endl;
  std::cout << std::string(55, '-') << std::endl;
  for (int i = 0; i < getContactsCount(); i++) {
      // Configura a largura de cada coluna para 10 caracteres e alinha à direita
      std::cout << "|    " << std::setw(5) << std::left << i << " | "
        << std::setw(12) << std::left << formatColumn(contacts[i].getFirstName()) << " | "
        << std::setw(11) << std::left << formatColumn(contacts[i].getLastName()) << " | "
        << std::setw(11) << std::left << formatColumn(contacts[i].getNickName()) << " |" << std::endl;
  }
  if (getContactsCount() == 0) {
    std::cout << "|                 No contacts saved.                  |" << std::endl;
  }
  std::cout << std::string(55, '-') << std::endl;
}

int PhoneBook::getContactsCount(void) {
  return this->contactsCount;
}

int PhoneBook::getNextIndexToReplace(void) {
  return this->nextIndexToReplace;
}

//setters  
void PhoneBook::setContactsCount(int contactsCount) {
  this->contactsCount = contactsCount;
}
void PhoneBook::setNextIndexToReplace(int Rep) {
  this->nextIndexToReplace = Rep;
}

int PhoneBook::getMaxContacts(void) {
  return this->maxContacts;
}
