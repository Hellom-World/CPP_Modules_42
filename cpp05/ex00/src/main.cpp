#include "../include/Bureaucrat.hpp"

int main(void)
{

    Bureaucrat *bureaucrat = new Bureaucrat("John", 150);
    Bureaucrat b2("Obama", 0);



    std::cout << *bureaucrat << std::endl;
    std::cout << b2 << std::endl;
    try
    {
        bureaucrat->decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    bureaucrat->setGrade(1);
    std::cout << *bureaucrat << std::endl;
    try
    {
        bureaucrat->setGrade(0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    std::cout << *bureaucrat << std::endl;
    delete bureaucrat;
    return 0;
}
