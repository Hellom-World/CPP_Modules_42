#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

bool open_file(std::ifstream &file, const char *filename, int flag)
{
    if (std::string(filename).find(".csv") == std::string::npos && flag == 0)
    {
        std::cerr << "Error: file is not a .csv file." << std::endl;
        return false;
    }

    if (std::string(filename).find(".txt") == std::string::npos && flag == 1)
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

bool    valid_date_format(std::string date)
{
    if (date == "date")
        return true;
    //verificar se a data está no formato yyyy-mm-dd
    if (date.size() != 10)
    {
        std::cout << "Error: invalid date format." << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: invalid date format. 2 " << std::endl;
        return false;
    }
    for (unsigned int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]) )
        {
            std::cout << date[i] << std::endl;
            std::cout << "Error: invalid date format. 3" << std::endl;
            return false;
        }
    }
    return true;
}

bool    valid_value(std::string value)
{
    char *end;
    float number = std::strtof(value.c_str(), &end);

    //verifica o valor da primeira string
    if (value == " value")
        return true;

    //verificar se o valor é um número
    if (*end != '\0')
    {
        std::cout << "Error: invalid value." << std::endl;
        return false;
    }
    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    //verifica se o valor nao passa 1000
    if (number > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void    make_data(const char *filename, std::map<std::string, float> &data)
{
    std::string line;
    std::string date;
    float value;

   //fazer um map com a data e o valor do .csv
    std::ifstream file;
    open_file(file, filename, 0);
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

void    open_input_file(char **argv, std::ifstream &file)
{
    //Abrir o arquivo de entrada
    if (!open_file(file, argv[1], 1))
        return;

}

void    line_verify(std::string line, std::string date, std::string value, std::map<std::string, float> &data)
{
    //verificar se a linha está no formato date|value
    if (line.find("|") == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    //verificar se a data está no formato yyyy-mm-dd
    date = date.substr(0, date.size() - 1);
    if (!valid_date_format(date))
        return;
    //verificar se o valor é um número
    if (!valid_value(value))
        return;

    //verificar se a data está no map
    if (data.find(date) == data.end())
    {
        std::cout << date << " =>" << value << std::endl;
        //FAZER CONTA AQUI!
        return;
    }

    //imprimir a data e o valor se date nao for date
    if (date != "date")
        std::cout << date << " =>" << value << std::endl;

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
    std::ifstream file;
    open_input_file(argv, file);

    //Ler o arquivo de entrada
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        std::getline(ss, date,  '|');
        std::getline(ss, value, '|');

        line_verify(line, date, value, data);
    }
}
