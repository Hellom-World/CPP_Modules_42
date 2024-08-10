#include "../include/Form.hpp"
#include <iostream>

void testValidBureaucrat()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        std::cout << bureaucrat;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return;
}
void testValidForm()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Form form("plan", 1, 1);
        std::cout << form;
        form.beSigned(bureaucrat);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return;
}
void testInvalidBureucratGradeToForm()
{
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 150);
        Form form("plan", 1, 1);
        std::cout << form;
        form.beSigned(bureaucrat);
        std::cout << form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return;
}
int main(void)
{

    //testValidBureaucrat();
    //std::cout << "------------------------------------------" << std::endl;
    //testValidForm();
    //std::cout << "------------------------------------------" << std::endl;
    //testInvalidBureucratGradeToForm();
    //std::cout << "------------------------------------------" << std::endl;

    //invalid createform high grade
    try
    {
        Form form("plan", 0, 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid create form low grade
    try
    {
        Form form("plan", 151, 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid creat bureaucrat high grade
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid create bureaucrat low grade
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid sign form high grade
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        Form form("plan", 0, 1);
        form.beSigned(bureaucrat);
        form.beSigned(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid sign form low grade
    try
    {
        Bureaucrat bureaucrat("Bureaucrat", 150);
        Form form("plan", 1, 1);
        form.beSigned(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
