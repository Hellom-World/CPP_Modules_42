#include "../include/ScalarConvert.hpp"
#include <cstring>
#include <sstream>

ScalarConvert::ScalarConvert(std::string input) : _input(input)
{
    char **end = new char*;
    _d = std::strtod(input.c_str(), end);

    /*std::cout << "input: " << input << std::endl;
    std::cout << "end: " << *end << std::endl;
    std::cout << "input size: " << input.size() << std::endl;
    std::cout << "_c: " << strlen(*end) << std::endl;
    std::cout << "_d: " << _d << std::endl;*/

    if ((strlen(*end) != 0))
    {
        if (strlen(*end) == 1 && **end != 'f' && _d == 0)
        {
            _c = static_cast<char>(**end);
            _i = static_cast<int>(_c);
            _f = static_cast<float>(_c);    
            delete end;
            return;
        }
        if (strlen(*end) == 1 && **end == 'f')
        {
            if (_input.size() == 1)
            {
                _i = static_cast<int>(_input[0]);
                _d = static_cast<double>(_i); 
                _c = _input[0];
                _f = static_cast<float>(_d);
                delete end;
                return;
            }
            _c = static_cast<char>(_d);
            _i = static_cast<int>(_d);
            _f = static_cast<float>(_d);
            delete end;
            return;
        }
        //if ((strlen(*end) == 2))

        delete end;
        throw std::exception();
    }
    _c = static_cast<char>(_d);
    _i = static_cast<int>(_d);
    _f = static_cast<float>(_d);

    delete end;
}

ScalarConvert::~ScalarConvert()
{
}

void ScalarConvert::convert(std::string input)
{
    //double _d;
    try {
        ScalarConvert sc(input);
        sc.printChar();
        sc.printInt();
        sc.printFloat();
        sc.printDouble();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: invalid input" << std::endl;
        return;
    }

}

void ScalarConvert::printChar()
{  
    std::cout << "char: ";
    try {
        if ((_c >= 0 && _c < 32) || _c == 127)
            throw ScalarConvert::NonDisplayableException();
        else if (_c >= 32 && _c <= 126)
            std::cout << "'" << _c << "'" << std::endl;
        else
            throw ScalarConvert::ImpossibleException();
    }
    catch (std::exception &e)
    {
        std::cout << "char: " << e.what() << std::endl;
        return;
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
        std::cout << "int: " << e.what() << std::endl;
        return;
    }
}

void ScalarConvert::printFloat()
{
    try {
        std::cout << "float: " << _f;
        if (_f - _i == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
}

void ScalarConvert::printDouble()
{
    std::cout.precision(10);
    std::cout << "double: " << _d;
    if (_d - _i == 0)
        std::cout << ".0";
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
