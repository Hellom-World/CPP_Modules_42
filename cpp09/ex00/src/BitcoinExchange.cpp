#include "../include/BitcoinExchange.hpp"

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

    std::cout << filename << " opened successfully." << std::endl;
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
        std::cout << "Error: invalid date format." << std::endl;
        return false;
    }
    for (unsigned int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]) )
        {
            std::cout << "Error: invalid date format." << std::endl;
            return false;
        }
    }
    //mes invalido
    if (std::atoi(date.substr(5, 2).c_str()) > 12 || std::atoi(date.substr(5, 2).c_str()) < 1)
    {
        std::cout << "Error: invalid month." << std::endl;
        return false;
    }
    //dia invalido para cada mes
    if (std::atoi(date.substr(8, 2).c_str()) > 31 || std::atoi(date.substr(8, 2).c_str()) < 1)
    {
        std::cout << "Error: invalid day." << std::endl;
        return false;
    }
    //verificar se o ano é bissexto
    //caso o resto da divisao do ano por 4 seja diferente de 0
    //o mes de fevereiro nao pode ter mais que 28 dias
    if (std::atoi(date.substr(0, 4).c_str()) % 4 != 0)
    {
        if (std::atoi(date.substr(5, 2).c_str()) == 2 && std::atoi(date.substr(8, 2).c_str()) > 28)
        {
            std::cout << "Error: invalid day. - its a leap year." << std::endl;
            return false;
        }
    }
    else
    {
        if (std::atoi(date.substr(5, 2).c_str()) == 2 && std::atoi(date.substr(8, 2).c_str()) > 29)
        {
            std::cout << "Error: invalid day. - its doesnt a leap year, but february has 29 days." << std::endl;
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
        if (date != "date")
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
    float result = 0;
    //verificar se a linha está vazia
    if (line.empty() || line.find_first_not_of(' ') == std::string::npos)
    {
        std::cout << "--------------empty line------------------" << std::endl;
        return;
    }
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

    //printar caso encontre uma data igual
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (it->first == date)
        {
            //std::cout << "-----------Data encontrada---------------------" << std::endl;
            //std::cout << it->first << " => " << it->second << std::endl;
            result = it->second;
            break;
        }
    }
    //caso nao encontre a data no map verificar o valor anterior e o valor posterior
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
    {
        //caso a data seja menor que a data do map
        if (it->first > date)
        {
            float prev = 0;
            float next = 0;
            //std::cout << "-----------Data nao encontrada---------------------" << std::endl;
            //std::cout << it->first << " => " << it->second << std::endl;
            next = it->second;
            it--;
            //std::cout << it->first << " => " << it->second << std::endl;
            prev = it->second;
            //std::cout << "--------------------------------" << std::endl;

            //ternario para verificar se o valor anterior ou o valor posterior é o menor
            //Caso o next seja maior que o prev, o result é o prev
            //Caso contrario, o result é o next
            result = next > prev ? prev : next;
            //std::cout << "next: " << next << " prev: " << prev << " result: " << result << std::endl;
            break;
        }
        //caso a data seja maior que as datas do map
        if (it == --data.end())
        {
            result = it->second;
            break;
        }
    }

    //imprimir a data e o valor se date nao for date
    if (date != "date")
    {
        int value_int = std::strtof(value.c_str(), NULL);
        result = value_int * result;
        std::cout << date << " =>" << value << " = " << result << std::endl;
    }

}
