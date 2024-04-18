#include "complexo.h"

int main() {
    Complexo n1{10, 20};
    Complexo n2{5, 15};

    std::cout << "n1 = ";
    n1.print();
    std::cout << "n2 = ";
    n2.print();
    return 0;
}

