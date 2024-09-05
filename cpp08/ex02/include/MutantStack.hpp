#ifndef MUTANTESTACK_HPP
#define MUTANTESTACK_HPP

#include <stack>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack const &src);
    virtual ~MutantStack();

    MutantStack &operator=(MutantStack const &rhs);
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif
