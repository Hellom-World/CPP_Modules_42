#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

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
void testInternClass()
{
    Intern intern;
    AForm *form = intern.makeForm("ShrubberyCreationForm", "home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
    std::cout << "-------------------------------------" << std::endl;
    form = intern.makeForm("RobotomyRequestForm", "home");
    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
    std::cout << "-------------------------------------" << std::endl;
    form = intern.makeForm("PresidentialPardonForm", "home");
    form->beSigned(bureaucrat);
    form->execute(bureaucrat);
    delete form;
    std::cout << "-------------------------------------" << std::endl;

}
void printDiv()
{
    std::cout << "                   |                    " << std::endl;
    std::cout << "-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-" << std::endl;
    std::cout << "                   |                    " << std::endl;
}
int main(void)
{
    /*testShrubberyCreationFormAndExecute();
    printDiv();
    testRobotomyRequestFormAndExecute();
    printDiv();
    testPresidentialPardonFormAndExecute();
    printDiv();
    testInternClass(); */

    //test invalid intern class
    try {
        Intern intern;
        AForm *form = intern.makeForm("InvalidForm", "home");
        Bureaucrat bureaucrat("bureaucrat", 1);
        form->beSigned(bureaucrat);
        form->execute(bureaucrat);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
