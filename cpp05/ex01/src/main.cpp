#include "../include/Form.hpp"
#include <iostream>

int main(void)
{
    //Form test;

    Form *form = new Form("Form", 1, 1);
    Form *form10 = new Form("Form10", 2, 1);
    Bureaucrat *bureaucrat = new Bureaucrat("John", 1);

    std::cout << *form << std::endl;
    std::cout << *bureaucrat << std::endl;
    try
    {
        form->beSigned(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try {
        form10->beSigned(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form *form2 (form);
    std::cout << *form2 << std::endl;
    {
        Form form3("Form3", 10, 20);
        form3 = *form2;
        std::cout << form3 << std::endl;
    }


    std::cout << *form << std::endl;
    delete form;
    delete bureaucrat;
    return 0;
}
