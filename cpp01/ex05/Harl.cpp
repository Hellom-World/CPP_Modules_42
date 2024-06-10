#include "Harl.hpp"

Harl::Harl(void) {
  std::cout << "Harl constructor called" << std::endl;
  return ;
}

Harl::~Harl(void) {
  std::cout << "Harl destructor called" << std::endl;
  return ;
}

void Harl::debug(void) {
  std::cout << BLUE << "[DEBUG]\t- I love having extra bacon for my";
	std::cout << "\n7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << RESET << std::endl;
}

void Harl::info(void) {
  std::cout << GREEN << "[INFO]\t- I cannot believe adding extra bacon cost more money.\n";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did I wouldn't be asking for more!"
		<< RESET << std::endl;
}

void Harl::warning(void) {
  std::cout << YELLOW << "[WARNING]\t- I think I deserve to have some extra bacon for free.\n";
  std::cout << "I think I deserve to have some extra bacon for free.";
  std::cout << " I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void Harl::error(void) {
  std::cout << RED << "[ERROR]\t- This is unacceptable, I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(std::string level) {
  //convertendo a string para maiúsculas
  for (size_t i = 0; i < level.length(); i++) {
    level[i] = toupper(level[i]);
  }

  //Cria um array de strings para comparar com o nível de reclamação
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  //Cria um array de ponteiros para funções membro da classe Harl
  void (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  
  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*complaints[i])();
      return ;
    }
  }
}
