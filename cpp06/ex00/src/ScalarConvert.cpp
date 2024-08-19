#include "../include/ScalarConvert.hpp"

ScalarConvert::ScalarConvert(std::string input) : _input(input)
{
}

ScalarConvert::~ScalarConvert()
{
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &rhs)
{
    if (this != &rhs)
    {
        this->_input = rhs._input;
    }
    return *this;
}

void ScalarConvert::convert()
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}

void ScalarConvert::printChar()
{
    try
    {
        char c = static_cast<char>(std::atoi(_input));
        if (c < 32 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConvert::printInt()
{
    try
    {
        int i = std::atoi(_input);
        std::cout << "int: " << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConvert::printFloat()
{
    try
    {
        float f = static_cast<float>(std::atof(_input.c_str()));
        std::cout << "float: " << f << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConvert::printDouble()
{
    try
    {
        double d = std::atod(_input.c_str());
        std::cout << "double: " << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "double: impossible" << std::endl;
    }


}

// int main(int argc, char **argv)




