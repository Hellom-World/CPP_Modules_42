#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        ~Array();
        Array& operator=(const Array& copy);
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#endif
