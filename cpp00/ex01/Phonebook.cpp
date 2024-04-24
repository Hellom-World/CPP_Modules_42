#include "Phonebook.hpp"


PhoneBook::PhoneBook() {
    this->index = 0;
		this->contactsCount = 0;
};

int PhoneBook::nextIndexToReplace = 0;

//---------------------------------------FORM_CONTACT--------------------------------------------------------------------------------------/
void PhoneBook::addContact() {

  std::cin.clear();  // Limpa o estado de erro de cin
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
  
  std::string firstName;
  std::cout << "Digite o primeiro nome: ";
  get_valid_input(std::cin, firstName, 2); // Função para validar o input (verificar se contém apenas letras e espaços
  
  std::cout << "Digite o sobrenome: ";
  std::string lastName;
  get_valid_input(std::cin, lastName, 2); // Função para validar o input (verificar se contém apenas letras e espaços

  std::cout << "Digite o seu Nickname: ";
  std::string nickName;
  std::getline(std::cin, nickName);

  std::cout << "Digite o seu Numero de Telefone: ";
  std::string phoneNumber;
  get_valid_input(std::cin, phoneNumber, 1); // Função para validar o input (verificar se contém apenas letras e espaços

  std::cout << "Digite o seu password: ";
  std::string darkestSecret;
  std::getline(std::cin, darkestSecret);

//-------------------------------------------SET_CONTACT------------------------------------------------------------------------------------/

 // std::cout << contactsCount << std::endl;
    Contact newContact;
    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickName(nickName);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);

  // Adicionar o novo contato ao vetor contacts
  if (contactsCount >= 8) { // Verifica se há espaço no vetor
    if (nextIndexToReplace >= 8) {
      nextIndexToReplace = 0;
    } 
    std::cout << "\nContato substituído:\n" << std::endl;
    std::cout << "Nome do contato substituído: " << contacts[nextIndexToReplace].getFirstName() << std::endl;
    std::cout << "Sobrenome do contato substituído: " << contacts[nextIndexToReplace].getLastName() << std::endl;
    std::cout << "Nickname do contato substituído: " << contacts[nextIndexToReplace].getNickName() << std::endl;
    std::cout << "Numero de telefone do contato substituído: " << contacts[nextIndexToReplace].getPhoneNumber() << std::endl;
    std::cout << "Password do contato substituído: " << contacts[nextIndexToReplace].getDarkestSecret() << std::endl;
    contacts[nextIndexToReplace] = newContact;
    nextIndexToReplace = (nextIndexToReplace + 1) % 8;
  } else {
    // Criar um novo objeto Contact com as informações inseridas

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
  printContacts();
  std::string index;
  std::cout << "\nDigite o index do contato que deseja visualizar: ";
  std::cin >> index;
  int i = std::stoi(validate_input(index, 11) ? index : "-1");

  if (i < 0 || i >= contactsCount) {
    std::cout << "Index inválido. Tente novamente." << std::endl;
    searchContact();
  } else {
    std::cout << "\nPrimeiro nome: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Sobrenome: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickName() << std::endl;
    std::cout << "Numero de telefone: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Password: " << contacts[i].getDarkestSecret() << std::endl;
  }

}
void PhoneBook::printContact() {
  std::cout << "--------------------TAREFAS-------------------------" << std::endl;
  std::cout << std::string(50, '-') << std::endl;
};

void PhoneBook::printContacts() {
  std::cout << "--------------------CONTATOS-------------------------" << std::endl;
  std::cout << "|  INDEX  |  FIRST NAME  |  LAST NAME  |  NICKNAME  |" << std::endl;
  std::cout << std::string(50, '-') << std::endl;
  for (int i = 0; i < contactsCount; i++) {
      // Configura a largura de cada coluna para 10 caracteres e alinha à direita
      std::cout << "| " << std::setw(8) << std::right << i << " | "
                << std::setw(12) << std::right << formatColumn(contacts[i].getFirstName()) << " | "
                << std::setw(11) << std::right << formatColumn(contacts[i].getLastName()) << " | "
                << std::setw(11) << std::right << formatColumn(contacts[i].getNickName()) << " |" << std::endl;
  }
  std::cout << std::string(50, '-') << std::endl;


  /*std::cout << "--------------------TAREFAS-------------------------" << std::endl;
  std::cout << "Mostrar lista de contato." << std::endl;
  std::cout << "Pedir o usuario para inserir um  index." << std::endl;
  std::cout << "Mostrar as informacoes do contato cujo o index foi inserido." << std::endl;
  std::cout << "Mostrar apenas " << std::endl;
  std::cout << std::string(50, '-') << std::endl; */
};

// Função para formatar uma coluna para ter 10 caracteres de largura e truncar o texto se for maior
std::string formatColumn(const std::string& text) {
    if (text.length() <= 10) {
        return text;
    } else {
        return text.substr(0, 9) + ".";
    }
}

int PhoneBook::getContactsCount(void) {
  return this->contactsCount;
}