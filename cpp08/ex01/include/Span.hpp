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
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int shortestSpan();
    int longestSpan();

    std::vector<int> getVector() const;
    unsigned int size() const;
    void printOriginalVector();
    void printSortedVector();
};

#endif
