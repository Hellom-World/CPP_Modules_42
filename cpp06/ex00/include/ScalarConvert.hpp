#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <cstdlib>

class ScalarConvert
{
private:
    std::string _input;
    ScalarConvert();
    ScalarConvert(ScalarConvert const &src);
    ScalarConvert &operator=(ScalarConvert const &rhs);

    int _b;
    char _c;
    int _i;
    float _f;
    double _d;

public:
    ScalarConvert(std::string input);
    ~ScalarConvert();
    void convert();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();

    class ImpossibleException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NonDisplayableException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
