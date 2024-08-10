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
    return 0;
}
