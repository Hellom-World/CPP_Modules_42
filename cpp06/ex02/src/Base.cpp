#include "../include/Base.hpp"

#include <iostream>

Base::Base() {
    std::cout << "Base constructor" << std::endl;
}

Base::~Base() {
    std::cout << "Base destructor" << std::endl;
}

Base::Base(const Base& other) {
    (void)other;
    std::cout << "Base copy constructor" << std::endl;
}

Base& Base::operator=(const Base& other) {
    (void)other;
    std::cout << "Base copy assignment operator" << std::endl;
    return *this;
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A - *" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B - *" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C - *" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base &p) {
    if (dynamic_cast<A*>(&p)) {
        std::cout << "A - &" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << "B - &" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << "C - &" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}