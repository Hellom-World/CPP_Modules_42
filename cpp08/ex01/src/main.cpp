#include "../include/Span.hpp"

int main()
{
    std::cout << "---------Teste add numbers---------" << std::endl;
    int size = 6;
    Span sp(size);
    srand(time(NULL));
    sp.printOriginalVector();
    for (int i = 0; i < size; i++)
            sp.addNumber(random() % 100);
    sp.printOriginalVector();

    std::cout << "---addNumber interator test----" << std::endl;
    Span v(5);
    v.addNumber(10);
    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(17);
    vec.push_back(9);
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    v.printOriginalVector();
    v.addNumber(vec.begin(), vec.end());
    v.printOriginalVector();

    std::cout << "---------Subject test---------" << std::endl;
    //subject test
    Span s = Span(5);
    s.addNumber(6);
    s.addNumber(3);
    s.addNumber(17);
    s.addNumber(9);
    s.addNumber(11);

    s.printOriginalVector();
    s.printSortedVector();
    std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s.longestSpan() << std::endl;
    return 0;
}
