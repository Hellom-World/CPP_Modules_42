
#include <iostream>
#include <string>
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[30m"

int validate_strings(std::string &filename, std::string &substituivel, std::string &substituta)
{
  if (filename.empty() || substituivel.empty() || substituta.empty())
    return 1;
  if (substituivel == substituta)
    return 1;
  return 0;
}

void ft_replace(std::string &line, std::string &substituivel, std::string &substituta)
{
  size_t pos = 0;
  size_t found_pos = line.find(substituivel, pos);
  
  //Verificar se a string substituivel existe na linha
  while (found_pos != std::string::npos)
  {
    // refaz a linha com a substituicao
    line = line.substr(0, found_pos) + substituta + line.substr(found_pos + substituivel.size());

    // Atualiza a posicao para a proxima ocorrencia   
    pos = found_pos + substituta.size();
    // Procura a proxima ocorrencia
    found_pos = line.find(substituivel, pos);
  }
}

int  main(int argc, char **argv)
{
  
  if (argc != 4)
  {
    std::cout << RED << "Error: " << RESET;
    std::cout << GREEN << "Need " << RESET;
    std::cout << YELLOW "./convert <FILENAME> ";
    std::cout << "<string_to_be_replaced> <string_to_replace>" << RESET << std::endl;
    return 1;
  }
  std::string filename = argv[1];
  std::string substituivel = argv[2];
  std::string substituta = argv[3];

  try {
    // Validate input
    if (validate_strings(filename, substituivel, substituta))
      throw std::runtime_error("Filename or strings are invalid");
    
    // Open file
    std::ifstream input_file(filename.c_str());
    
    if (!input_file.is_open())
      throw std::runtime_error("File + " + filename + " not found");

    // Create output file
    std::string output_filename = filename + ".replace";
    std::ofstream output_file(output_filename.c_str());
    if (!output_file.is_open())
      throw std::runtime_error("Could not create file " + output_filename);

    // Read file
    std::string line;
    while (std::getline(input_file, line))
    {
      // substituir a string modificavel pela string substituta
      ft_replace(line, substituivel, substituta);
      // Verificar se a linha atual é a ultima linha
      if (!input_file.eof())
        output_file << line << std::endl;
      else
        output_file << line;
    }

    // Close files
    std::cout << GREEN << "File: " << filename;
    std::cout << GREEN << " was successfully converted to ";
    std::cout << output_filename << RESET << std::endl;
    input_file.close();
    output_file.close();
  }
  catch (std::exception &e)
  {
    std::cout << RED << "Error: " << RESET << e.what() << std::endl;
    return 1;
  }
  
  return 0;
}
