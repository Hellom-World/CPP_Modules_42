#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
public:

    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    Form *makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
