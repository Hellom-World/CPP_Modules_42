#include "../include/Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &span)
{
    *this = span;
}

Span &Span::operator=(const Span &span)
{
    _n = span._n;
    _v = span._v;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_v.size() < _n)
        _v.push_back(n);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw std::exception();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 2; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw std::exception();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int max = 0;
    
    // Percorre o vetor e compara o valor atual com o próximo
    for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; ++it)
    {
        int diff = *(it + 1) - *it;  // Calcula a diferença entre o atual e o próximo
        if (diff > max)  // Se a diferença for maior que a anterior, atualiza
            max = diff;
    }
    return max;
}

unsigned int Span::size() const
{
    return _n;
}

void Span::printOriginalVector()
{
    std::cout << "Original vector: ";
    for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Span::printSortedVector()
{
    std::cout << "Sorted vector: ";
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


