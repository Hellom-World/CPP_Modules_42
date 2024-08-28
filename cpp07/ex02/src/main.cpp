#include "../include/Array.hpp"

int    main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
    std::cout << "----------------" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    std::cout << "Array<int> b = a;" << std::endl;
    Array<int> b = a;
    std::cout << "-----Print Array b-----------" << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "<Add outher values to Array b>" << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i + 42;
    std::cout << "-----Print Array b-----------" << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "------print Array a----------" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    return 0;
}
