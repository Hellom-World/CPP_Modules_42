#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _v;

public:
    Span(unsigned int n);
    Span(const Span &span);
    Span &operator=(const Span &span);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    unsigned int size() const;
    void printOriginalVector();
    void printSortedVector();
};

#endif