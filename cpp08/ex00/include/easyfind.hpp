#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <map>


//versao para tipos de container que nao sao armazenados por chave

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

//versao para maps que sao armazenados por chave
template <typename Key, typename T>
typename std::map<Key, T>::iterator easyfind(std::map<Key, T>& container, int value) {
    // Busca a chave diretamente
    typename std::map<Key, T>::iterator it = container.find(value);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif
