#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;
class Intern
{
private:
    std::string _formTypes[3];
public:

    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    AForm *makeForm(std::string forName, std::string target);

    AForm *createShrubberyCreationForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createPresidentialPardonForm(std::string target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
