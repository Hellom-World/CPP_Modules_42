#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void testShrubberyCreationFormAndExecute()
{
    //test shrubbery creation form
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    shrubbery.beSigned(bureaucrat);
    shrubbery.execute(bureaucrat);
}

void testRobotomyRequestFormAndExecute()
{
    //test robotomy request form
    RobotomyRequestForm robotomy("home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    robotomy.beSigned(bureaucrat);
    robotomy.execute(bureaucrat);
}

void testPresidentialPardonFormAndExecute()
{
    //test presidential pardon form
    PresidentialPardonForm presidential("home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    presidential.beSigned(bureaucrat);
    presidential.execute(bureaucrat);
}

int main(void)
{
    //testShrubberyCreationFormAndExecute();
    //std::cout << "---------------------" << std::endl;
    //testRobotomyRequestFormAndExecute();
    //std::cout << "---------------------" << std::endl;
    //testPresidentialPardonFormAndExecute();

    //Bureaucrat executeForm test
    std::cout << "-------------executeForm-----------------" << std::endl;
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    shrubbery.beSigned(bureaucrat);
    bureaucrat.executeForm(shrubbery);
    std::cout << "--------------------------------------" << std::endl;

    //invalid shrubbery execute high grade
    try
    {
        ShrubberyCreationForm shrubbery("home");
        Bureaucrat bureaucrat("bureaucrat", 150);
        shrubbery.beSigned(bureaucrat);
        shrubbery.execute(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    //invalid robotomy execute high grade
    try
    {
        RobotomyRequestForm robotomy("home");
        Bureaucrat bureaucrat("bureaucrat", 150);
        robotomy.beSigned(bureaucrat);
        robotomy.execute(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //invalid presidential execute high grade
    try
    {
        PresidentialPardonForm presidential("home");
        Bureaucrat bureaucrat("bureaucrat", 150);
        presidential.beSigned(bureaucrat);
        presidential.execute(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
