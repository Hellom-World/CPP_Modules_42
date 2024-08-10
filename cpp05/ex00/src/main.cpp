#include "../include/Bureaucrat.hpp"

int main(void)
{

    Bureaucrat *b1 = new Bureaucrat("John", 3);
    std::cout << "---------------------" << std::endl;

    // should throw low grade exception
    try
    {
        Bureaucrat b2("Obama", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    // should throw high grade exception
    try
    {
        Bureaucrat b3("Trump", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;
    std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
    std::cout << "---------------------" << std::endl;

    b1->setGrade(1);
    std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
    std::cout << "---------------------" << std::endl;

    // should throw incrementGrade exception
    try
    {
        b1->incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
    b1->decrementGrade();
    std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
    b1->setGrade(150);
    std::cout << b1->getName() << " " << b1->getGrade() << std::endl;
    std::cout << "---------------------" << std::endl;

    // should throw decrementGrade exception
    try
    {
        b1->decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // should throw high setGrade exception
    try
    {
        b1->setGrade(151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // should throw low setGrade exception
    try
    {
        b1->setGrade(0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    std::cout << *b1 << std::endl;
    delete b1;
    return 0;
}
