# include <string>
# include <iostream>

int  main(void){
  
  std::string string = "HI THIS IS BRAIN";
  //Cria ponteiro para a string.
  std::string *stringPTR = &string;
  //Cria uma referência para a string.
  std::string &stringREF = string;

  //O endereço de memoria da variável string.
  std::cout << "\033[1;31m" << "String" << "\033[0m" << "\t   " << "memory address: " << "\033[1;32m" << &string << "\033[0m" << std::endl;    
  //O endereço de memoria armazenado por stringPTR.
  std::cout << "\033[1;31m" << "StringPTR " << "\033[0m" << " memory address: " << "\033[1;32m" << &stringPTR << "\033[0m" << std::endl;
  //O endereço de memoria armazenado por stringREF.
  std::cout << "\033[1;31m" << "StringREF " << "\033[0m" << " memory address: " << "\033[1;32m" << &stringREF << "\033[0m" << std::endl;


  //Entao:
  //O valor da variavel string.
  std::cout << "\n\033[1;31m" << "String " << "\033[0m" << "\t   variable value: "<< "\033[1;32m" << string << "\033[0m" << std::endl;
  //O valor apontado por stringPTR.
  std::cout << "\033[1;31m" << "StringPTR " << "\033[0m" << " variable value: "<< "\033[1;32m" << *stringPTR << "\033[0m" << std::endl;
  //O valor referenciado por stringREF.
  std::cout << "\033[1;31m" << "StringREF " << "\033[0m" << " variable value: "<< "\033[1;32m" << stringREF << "\033[0m" << std::endl;

  return 0;
}
