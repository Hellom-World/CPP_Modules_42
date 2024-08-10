#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
    _target = target;
    std::cout << "*PresidentialPardonForm parameter constructor*" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy)
{
    _target = copy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return *this;
    Form::operator=(copy);
    _target = copy._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed
    if (!getSigned())
        throw Form::UnsignedFormException();
    // Check if the executor has the right grade
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::FileOpenException::what() const throw()
{
    return "File open exception";
}
