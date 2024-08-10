#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    std::string _target;

public:

    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    class FileOpenException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    void execute(Bureaucrat const &executor) const;
};

#endif
