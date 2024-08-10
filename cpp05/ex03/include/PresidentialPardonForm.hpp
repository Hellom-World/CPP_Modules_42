#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:

    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

    class FileOpenException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
