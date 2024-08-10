#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

void testShrubberyCreationFormAndExecute()
{
    //test shrubbery creation form
    ShrubberyCreationForm shrubbery("home");
    Bureaucrat bureaucrat("bureaucrat", 1);
    shrubbery.beSigned(bureaucrat);
    shrubbery.execute(bureaucrat);
}

int main(void)
{
    testShrubberyCreationFormAndExecute();
    return 0;
}
