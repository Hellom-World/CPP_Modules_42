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
    char **end = new char*;


    _d = std::strtod(_input.c_str(), end);
    std::cout << "double: " << _d << std::endl;
    std::cout << "char: " << *end << std::endl;
    _c = static_cast<unsigned char>(_d);
    _b = static_cast<int>(_d);
    _i = static_cast<int>(_d);
    _f = static_cast<float>(_d);

    printChar();
    printInt();
    printFloat();
    printDouble();
    delete end;
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
        if (_i < -2147483647 || _i > 2147483647)
            throw ScalarConvert::ImpossibleException();
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
