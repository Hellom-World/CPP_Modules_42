#include "../include/Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this == &copy)
        return *this;
    delete [] _array;
    _array = new T[copy._size];
    _size = copy._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
