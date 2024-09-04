#include "../include/easyfind.hpp"
#include <map>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::map<int, int> m;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        l.push_back(i);
    }

    try
    {

        std::cout << *easyfind(v, 5) << std::endl;
        std::cout << *easyfind(l, 5) << std::endl;
        std::cout << *easyfind(m, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
}

// Necessario corrigir retorno do map, pois o retorno do easyfind para map esta retornando um pair, e nao um iterator
