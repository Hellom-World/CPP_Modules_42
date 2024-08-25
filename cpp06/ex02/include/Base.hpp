#ifndef BASE_HPP
#define BASE_HPP

class Base {
    public:
        Base();
        virtual ~Base();
        Base(const Base& other);
        Base& operator=(const Base& other);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base *p);
void identify(Base &p);

#endif