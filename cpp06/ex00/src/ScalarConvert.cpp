#include "../include/ScalarConvert.hpp"
#include <string>
#include <sstream>
#include <limits>

ScalarConvert::ScalarConvert(std::string input) : _input(input)
{

}

ScalarConvert::~ScalarConvert()
{
}

void ScalarConvert::convert()
{
    if (_input.length() == 1 && !std::isdigit(_input[0]))
    {
        _b = static_cast<int>(_input[0]);
        _c = static_cast<char>(_b);
        _i = static_cast<int>(_b);
        _f = static_cast<float>(_b);
        _d = static_cast<double>(_b);
    }
    else if (_input == "nan" || _input == "+inf" || _input == "-inf" || _input == "inf")
    {
        if (_input == "nan")
        {
            _b = 0;
            _c = 0;
            _i = 0;
            _f = std::numeric_limits<float>::quiet_NaN();
            _d = std::numeric_limits<double>::quiet_NaN();
        }
        else if (_input == "+inf" || _input == "inf")
        {
            _b = 0;
            _c = 0;
            _i = 0;
            _f = std::numeric_limits<float>::infinity();
            _d = std::numeric_limits<double>::infinity();
        }
        else if (_input == "-inf")
        {
            _b = 0;
            _c = 0;
            _i = 0;
            _f = -std::numeric_limits<float>::infinity();
            _d = -std::numeric_limits<double>::infinity();
        }
    }
    else if (_input.length() > 1 && _input[0] == '-' && std::isdigit(_input[1]))
    {
        _b = std::atoi(_input.c_str());
        _c = static_cast<unsigned char>(_b);
        _i = static_cast<int>(_b);
        _f = std::atof(_input.c_str());
        std::istringstream(_input) >> _d;
    }
    else if (std::isdigit(_input[0]))
    {
        _b = std::atoi(_input.c_str()); // atoi converte uma string para um inteiro
        _c = static_cast<char>(_b); // static_cast converte um tipo de dado para outro
        _i = static_cast<int>(_b); // static_cast converte um tipo de dado para outro
        _f = std::atof(_input.c_str()); // atof converte uma string para um float
        std::istringstream(_input) >> _d; // istringstream converte uma string para um double
    }

    printChar();
    printInt();
    printFloat();
    printDouble();
}

void ScalarConvert::printChar()
{
    try
    {
        if (_b < 0 || _b > 255)
            throw ScalarConvert::ImpossibleException();
        if (_b < 32 || _b > 126)
            throw ScalarConvert::NonDisplayableException();
        std::cout << "char: '" << static_cast<char>(_b) << "'" << std::endl;
    }
    catch (ScalarConvert::ImpossibleException &e)
    {
        std::cout << "char: impossible" << std::endl;
    }
    catch (ScalarConvert::NonDisplayableException &e)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConvert::printInt()
{
    try {
        std::cout << "int: " << _i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
}

void ScalarConvert::printFloat()
{
    try {
        std::cout << "float: " << _f;
        if (_f - _i == 0)
            std::cout << ".0"; // É preciso afinar a precisão
        std::cout << "f" << std::endl; // É preciso afinar a precisão
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
}

void ScalarConvert::printDouble()
{
    std::cout.precision(10); // Define a precisão de saída
    std::cout << "double: " << _d;
    if (_d - _i == 0)
        std::cout << ".0"; // É preciso afinar a precisão
    std::cout << std::endl;
}

const char *ScalarConvert::ImpossibleException::what() const throw()
{
    return "impossible";
}

const char *ScalarConvert::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &rhs)
{
    if (this != &rhs)
    {
        _input = rhs._input;
        _b = rhs._b;
        _c = rhs._c;
        _i = rhs._i;
        _f = rhs._f;
        _d = rhs._d;
    }
    return *this;
}

ScalarConvert::ScalarConvert(ScalarConvert const &src)
{
    *this = src;
}
