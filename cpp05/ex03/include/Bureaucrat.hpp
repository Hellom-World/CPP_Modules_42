#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(bool isSigned, const AForm &form) const;

    void setGrade(int grade);

    // Nested Classes são classes que estão dentro de outras classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
