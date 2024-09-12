#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

bool open_file(std::ifstream &file, const char *filename)
{
    if (std::string(filename).find(".csv") == std::string::npos)
    {
        std::cerr << "Error: file is not a .txt file." << std::endl;
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
        std::cout << line << std::endl;
    file.clear();
    file.seekg(0, std::ios::beg);

    std::cout << "-------------------" << std::endl;
}

void    valid_date_format(std::string date)
{
    if (date == "date")
        return;
    //verificar se a data está no formato yyyy-mm-dd
    if (date.size() != 10)
    {
        std::cout << "Error: invalid date format." << std::endl;
        return;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: invalid date format. 2 " << std::endl;
        return;
    }
    for (unsigned int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]) )
        {
            std::cout << date[i] << std::endl;
            std::cout << "Error: invalid date format. 3" << std::endl;
            return;
        }
    }

    std::cout << date << std::endl;
}

void    valid_value(float value)
{
    //verificar se o valor é um número
    if (value < 0)
    {
        std::cout << "Error: invalid value." << std::endl;
        return;
    }
    //verifica se o valor nao passa do maximo float
    if (value > 3.40282e+38)
    {
        std::cout << "Error: invalid value." << std::endl;
        return;
    }
}

void    make_data(const char *filename, std::map<std::string, float> &data)
{
    std::string line;
    std::string date;
    float value;

   //fazer um map com a data e o valor do .csv
    std::ifstream file;
    open_file(file, filename);
    //print_file(file);

    //criar um map com a data e o valor
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, line, ',');
        value = std::strtof(line.c_str(), NULL);
        data[date] = value;
    }
}

void    print_map(std::map<std::string, float> &data)
{
    //printar o map
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
        std::cout << it->first << " => " << it->second << std::endl;
}

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: coult not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> data;
    make_data("data.csv", data);
    //print_map(data);

    //Abrir o arquivo de entrada
    std::ifstream file;
    file.open(argv[1], std::ifstream::in);
    if (!file.is_open())
    {
        std::cerr << "Error: coult not open file." << std::endl;
        return 1;
    }

    //Ler o arquivo de entrada
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        std::getline(ss, date,  '|');
        std::getline(ss, value, '|');
        date = date.substr(0, date.size() - 1);

        valid_date_format(date);
        //valid_value(std::strtof(value.c_str(), NULL));
    }
}
