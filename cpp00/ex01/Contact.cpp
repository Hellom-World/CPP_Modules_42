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