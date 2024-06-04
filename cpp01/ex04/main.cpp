
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"

int  main(int argc, char **argv)
{
  
  if (argc != 4)
  {
    std::cout << RED << "Error: " << RESET << "Invalid number of arguments" << std::endl;
    return 1;
  }
  std::string value = argv[1];
  std::string from = argv[2];
  std::string to = argv[3];
  std::cout << "Value: " << value << std::endl;
  std::cout << "From: " << from << std::endl;
  std::cout << "To: " << to << std::endl;
  return 0;
}
