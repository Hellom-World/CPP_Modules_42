#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

bool open_file(std::ifstream &file, char *filename)
{
    if (std::string(filename).find(".csv") == std::string::npos)
    {
        std::cerr << "Error: file is not a .csv file." << std::endl;
        return false;
    }

    file.open(filename, std::ifstream::in);
    if (!file.is_open())
    {
        std::cerr << "Error: coult not open file." << std::endl;
        return false;
    }
    std::cout << "File opened successfully." << std::endl;
    return true;
}

void print_file(std::ifstream &file)
{
    //Sem modificar o ponteiro de leitura do arquivo, imprima o conteúdo do arquivo.

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.clear();
    file.seekg(0, std::ios::beg);

    std::cout << "-------------------" << std::endl;

}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: coult not open file." << std::endl;
        return 1;
    }
    //exemplo do conteudo do arquivo .csv
    /*date,exchange_rate
    2009-01-02,0
    2009-01-05,0
    2009-01-08,0
    2009-01-11,0
    2009-01-14,0 */

    //abrir o arquivo
    std::ifstream file;
    open_file(file, argv[1]);
    //print_file(file);

    //criar um map para armazenar os dados
    std::map<std::string, float> data;
    std::string line;
    std::string date;

    //ler o arquivo e armazenar os dados no map
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        date = token;
        std::getline(ss, token, ',');
        data[date] = std::strtof(token.c_str(), NULL);
    }

    //imprimir os dados do map
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        std::cout << it->first << " - " << it->second << std::endl;
    }

}
