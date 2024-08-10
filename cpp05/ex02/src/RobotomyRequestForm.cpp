#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
    _target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form( target, 72, 45)
{
    _target = target;
    std::cout << "*RobotomyRequestForm parameter constructor*" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy)
{
    _target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return *this;
    Form::operator=(copy);
    _target = copy._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
        // Check if the form is signed
    if (!getSigned())
        throw Form::UnsignedFormException();
    // Check if the executor has the right grade
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();

    std::srand(std::time(0));
    std::cout << "*drill drill drill* ";

    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}

const char *RobotomyRequestForm::FileOpenException::what() const throw()
{
    return "File open exception";
}


