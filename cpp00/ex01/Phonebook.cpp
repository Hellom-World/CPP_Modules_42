#include "Phonebook.hpp"
#include <limits>

PhoneBook::PhoneBook() {
    this->index = 0;
		this->contactsCount = 0;
};

//---------------------------------------FORM_CONTACT--------------------------------------------------------------------------------------/
void PhoneBook::addContact() {

  std::cin.clear();  // Limpa o estado de erro de cin
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
  
  std::string firstName;
  std::cout << "Digite o primeiro nome: ";
  std::getline(std::cin, firstName);

  std::cout << "Digite o sobrenome: ";
  std::string lastName;
  std::getline(std::cin, lastName);

  std::cout << "Digite o seu Nickname: ";
  std::string nickName;
  std::getline(std::cin, nickName);

  std::cout << "Digite o seu Numero de Telefone: ";
  std::string phoneNumber;
  std::getline(std::cin, phoneNumber);

  std::cout << "Digite o seu password: ";
  std::string darkestSecret;
  std::getline(std::cin, darkestSecret);

//-------------------------------------------SET_CONTACT------------------------------------------------------------------------------------/

 // std::cout << contactsCount << std::endl;

  // Adicionar o novo contato ao vetor contacts
  if (contactsCount > 8) { // Verifica se há espaço no vetor
    std::cout << "\nNão há mais espaço para adicionar contatos." << std::endl;
  } else {
    // Criar um novo objeto Contact com as informações inseridas
    Contact newContact;
    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickName(nickName);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);

    contacts[contactsCount] = newContact;

    std::cout << "\nNome do contato salvo: " << contacts[contactsCount].getFirstName() << std::endl;
    std::cout << "Sobrenome do contato salvo: " << contacts[contactsCount].getLastName() << std::endl;
    std::cout << "Nickname do contato salvo: " << contacts[contactsCount].getNickName() << std::endl;
    std::cout << "Numero de telefone do contato salvo: " << contacts[contactsCount].getPhoneNumber() << std::endl;
    std::cout << "Password do contato salvo: " << contacts[contactsCount].getDarkestSecret() << std::endl;

    contactsCount++;
    std::cout << "\nNovo contato adicionado com sucesso!\n" << std::endl;
  }

//------------------------------------------------------------------------------------------------------------------------------------------/
}


void PhoneBook::searchContact() {

}
void PhoneBook::printContact() {
  std::cout << "--------------------TAREFAS-------------------------" << std::endl;
  std::cout << std::string(50, '-') << std::endl;
};

void PhoneBook::printContacts() {
  std::cout << "--------------------TAREFAS-------------------------" << std::endl;
  std::cout << std::string(50, '-') << std::endl;
};

int PhoneBook::getContactsCount(void) {
  return this->contactsCount;
}