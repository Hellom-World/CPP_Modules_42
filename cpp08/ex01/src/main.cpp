#include "../include/Span.hpp"

int main()
{
    
    Span s(5);
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        s.addNumber(random() % 100);

    s.printOriginalVector();
    s.printSortedVector();
    std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s.longestSpan() << std::endl;
    return 0;
}