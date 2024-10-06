#include "../include/BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: coult not open file." << std::endl;
        return 1;
    }

    //Criar um map de dados
    std::map<std::string, float> data;
    make_data("input.csv", data);

    //Abrir o arquivo de entrada input.txt
    std::ifstream file;
    open_input_file(argv, file);

    //Tratamento do arquivo de entrada input.txt
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string value;
        std::getline(ss, date,  '|');
        std::getline(ss, value, '|');

        //Verifica cada linha do arquivo de entrada
        line_verify(line, date, value, data);
    }
}
