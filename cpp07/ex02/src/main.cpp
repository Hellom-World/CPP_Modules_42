#include "../include/Array.hpp"

int    main()
{
    //Testa construtor sem parametro
    Array<int> empty;
    std::cout << "Array<int> empty;" << std::endl;
    std::cout << "------------Create Array a--------------------" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    std::cout << "<Add values to Array a>" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
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


    //Testa exceção
    std::cout << "-------Exception test--------" << std::endl;
    try
    {
        std::cout << "<TRY Add a[-1] = 0;>" << std::endl;
        a[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERR0R: out of range" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try
    {
        std::cout << "<TRY Add a[5] = 0;>" << std::endl;
        a[5] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERR0R: out of range" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    //Testa array.size()
    std::cout << "Array<int> c;" << std::endl;
    Array<int> c;
    std::cout << "c.size() = " << c.size() << std::endl;
    std::cout << "Array<int> d(10);" << std::endl;
    Array<int> d(10);
    for (unsigned int i = 0; i < d.size(); i++)
    {
        d[i] = i;
        std::cout << "d[" << i << "] = ";
        std::cout << d[i] << std::endl;
    }
    std::cout << "d.size() = " << d.size() << std::endl;
    for (unsigned int i = 0; i < d.size(); i++)
    {
        std::cout << "d[" << i << "] = ";
        std::cout << d[i] << std::endl;
    }



    return 0;
}
