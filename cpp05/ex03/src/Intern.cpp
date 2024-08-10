#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
    _formTypes[0] = "ShrubberyCreationForm";
    _formTypes[1] = "RobotomyRequestForm";
    _formTypes[2] = "PresidentialPardonForm";
}
Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 3; i++)
            _formTypes[i] = copy._formTypes[i];
    }
    return (*this);
}

Intern::~Intern()
{
    for (int i = 0; i < 3; i++)
        _formTypes[i].clear();
    std::cout << "Intern destructor" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    std::cout << _formTypes[0] << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (formName == _formTypes[i])
        {
            switch (i)
            {
            case 0:
                form = createShrubberyCreationForm(target);
                break;
            case 1:
                form = createRobotomyRequestForm(target);
                break;
            case 2:
                form = createPresidentialPardonForm(target);
                break;
            }
        };
    }
    if (form == NULL)
        throw FormNotFoundException();
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "ERROR: Form not found";
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{

    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

