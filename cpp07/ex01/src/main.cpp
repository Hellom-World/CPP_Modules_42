#include "../include/iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    //Confirmar se o valor de size pode ser colocado maior que o tamanho do array
    std::cout << "Int array:" << std::endl;
    iter(intArray, 5, print);
    std::cout << "Float array:" << std::endl;
    iter(floatArray, 5, print);
    std::cout << "Double array:" << std::endl;
    iter(doubleArray, 5, print);
    std::cout << "Char array:" << std::endl;
    iter(charArray, 5, print);
    std::cout << "String array:" << std::endl;
    iter(stringArray, 5, print);
    return 0;
}
