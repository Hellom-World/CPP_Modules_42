# include <string>
# include <iostream>

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"

int  main(void){
  
  std::string string = "HI THIS IS BRAIN";
  //Cria ponteiro para a string.
  std::string *stringPTR = &string;
  //Cria uma referência para a string.
  std::string &stringREF = string;

  //O endereço de memoria da variável string.
  std::cout << RED << "String" << RESET << "\t  " << "memory address: " << GREEN << &string << RESET << std::endl;
  //O endereço de memoria armazenado por stringPTR.
  std::cout << RED << "StringPTR" << RESET << " memory address: " << GREEN << &stringPTR << RESET << std::endl;
  //O endereço de memoria armazenado por stringREF.
  std::cout << RED << "StringREF" << RESET << " memory address: " << GREEN << &stringREF << RESET << std::endl;

  //O valor da variavel string.
  std::cout << RED << "\nString" << RESET << "\t  variable value: " << GREEN << string << RESET << std::endl;
  //O valor apontado por stringPTR.
  std::cout << RED << "StringPTR" << RESET << " variable value: " << GREEN << *stringPTR << RESET << std::endl;
  //O valor referenciado por stringREF.
  std::cout << RED << "StringREF" << RESET << " variable value: " << GREEN << stringREF << RESET << std::endl;
  return 0;
}
