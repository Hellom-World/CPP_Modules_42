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
    testShrubberyCreationFormAndExecute();
    std::cout << "---------------------" << std::endl;
    testRobotomyRequestFormAndExecute();
    std::cout << "---------------------" << std::endl;
    testPresidentialPardonFormAndExecute();

    return 0;
}
