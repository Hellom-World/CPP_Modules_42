#include "../include/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
    {
    }
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor" << std::endl;
}

Form *Intern::makeForm(std::string formName, std::string target)
{
    Form *form = NULL;



    return form;
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
