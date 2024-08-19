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

public:
    ScalarConvert(std::string input);
    ~ScalarConvert();
    void convert();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
};

#endif
