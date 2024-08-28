#ifndef TEMP_HPP
#define TEMP_HPP

#include <iostream>
#include <string>

template <typename T>

T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T>
//swap sem return
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif
