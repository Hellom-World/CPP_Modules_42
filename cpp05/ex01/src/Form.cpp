#include "../include/Form.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form &Form::operator=(const Form &copy)
{
    if (this == &copy)
        return *this;
    //_gradeToSign = copy._gradeToSign;
    //_gradeToExecute = copy._gradeToExecute;
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    std::cout << bureaucrat.getGrade() << std::endl;
    std::cout << this->_gradeToSign << std::endl;
    if (bureaucrat.getGrade() < _gradeToSign)
    {
        bureaucrat.signForm(false, *this);
        throw Form::GradeTooLowException();
    }
    bureaucrat.signForm(true, *this);
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return out;
}


