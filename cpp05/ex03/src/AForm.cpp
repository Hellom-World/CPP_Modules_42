#include "../include/AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this == &copy)
        return *this;
    //_gradeToSign = copy._gradeToSign;
    //_gradeToExecute = copy._gradeToExecute;
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        bureaucrat.signForm(false, *this);
        throw AForm::GradeTooLowException();
    }
    bureaucrat.signForm(true, *this);
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::UnsignedFormException::what() const throw()
{
    return "Form is unsigned";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
    return out;
}


