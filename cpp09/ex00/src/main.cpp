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

void    valid_date_format(std::string date)
{
    //verificar se a data está no formato yyyy-mm-dd
    if (date.size() != 10)
    {
        throw std::invalid_argument("Error: invalid date format.");
        return;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        throw std::invalid_argument("Error: invalid date format.");
        return;
    }
    for (unsigned int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            throw std::invalid_argument("Error: invalid date format.");
            return;
        }
    }
}

void    valid_value(float value)
{
    //verificar se o valor é um número
    if (value < 0)
    {
        throw std::invalid_argument("Error: invalid value.");
        return;
    }
    //verifica se o valor nao passa do maximo float
    if (value > 3.40282e+38)
    {
        throw std::invalid_argument("Error: invalid value.");
        return;
    }
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

    //validar valor das chaves
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (it->first == "date")
            continue;
        try
        {
            valid_date_format(it->first);
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    std::cout << "All dates are in the correct format." << std::endl;

    //validar valor dos dados
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        try
        {
            valid_value(it->second);
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    std::cout << "All values are valid." << std::endl;

    //imprimir os dados do map
    /*for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        std::cout << it->first << " - " << it->second << std::endl;
    }*/

}
