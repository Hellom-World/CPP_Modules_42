#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
    _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target + "_shrubbery", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy)
{
    _target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return (*this);
    Form::operator=(copy);
    _target = copy._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed
    if (!getSigned())
        throw Form::UnsignedFormException();
    // Check if the executor has the right grade
    if (executor.getGrade() > getGradeToExecute())
        throw Form::GradeTooLowException();

    std::string tmp = _target + "_shrubbery";

    std::ofstream file(tmp.c_str());
    if (!file.is_open())
        throw ShrubberyCreationForm::FileOpenException();
    file << "      HHHHH\n"
        "    HEEEEEEEH\n"
        "   HEEOEEELOEH\n"
        "  HELOOMMMOLOEH\n"
        " HLOOOBIGMOOOLH\n"
        "  HLEOOOLLOEEH\n"
        "    HHH|HHH\n"
        "      |||\n"
        "      |||\n"
        "      |||\n"
        "     _|_|_\n";

    file.close();
    std::cout << "Shrubbery creation form executed by " << executor.getName() << std::endl;
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return ("Error: File open exception");
}

