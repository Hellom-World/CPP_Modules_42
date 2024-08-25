#include "../include/Base.hpp"
#include <iostream>

int main() {
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();
    Base *d = new Base();
    Base *e = NULL;
    std::cout << std::endl;

    std::cout << "identify(Base *p)" << std::endl;
    std::cout << "Type from ptr: ";
    identify(a);
    std::cout << "Type from ptr: ";
    identify(b);
    std::cout << "Type from ptr: ";
    identify(c);
    std::cout << "Type from ptr: ";
    identify(d);
    std::cout << "Type from ptr: ";
    identify(e);
    std::cout << std::endl;

    std::cout << "identify(Base &p)" << std::endl;
    std::cout << "Type from ref: ";
    identify(*a);
    std::cout << "Type from ref: ";
    identify(*b);
    std::cout << "Type from ref: ";
    identify(*c);
    std::cout << "Type from ref: ";
    identify(*d);
    std::cout << "Type from ref: ";
    identify(*e);

    std::cout << std::endl;
    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}