#include "Fixed.hpp"

int main() {

    std::cout << " __________Construtor padrao_________" << std::endl;
    Fixed a;
    std::cout << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;

    std::cout << " _________Construtor de copia________ " << std::endl;
    Fixed b(a);
    std::cout << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;

    std::cout << " _______Operador de atribuicao_______ " << std::endl;
    Fixed c;
    c = b;
    std::cout << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
