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
        m.insert(std::pair<int, int>(i, 10 * i));
    }

    try
    {

        std::cout << *easyfind(v, 5) << std::endl;
        std::cout << *easyfind(l, 5) << std::endl;
        std::cout << "m[first] = Second \t- Onde First: " << easyfind(m, 5)->first << std::endl;
        std::cout << "m[first] = Second \t- Onde Second: " << easyfind(m, 5)->second << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
}
