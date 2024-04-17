#include "circle.h"

int main () {
    Circle c1; // {0.0, 0, 0};
    Circle c2(15.7, 8.9, -5.1);
    Circle c3{7.7}; // {0, 0}; 

    std::cout << "\nCircle c1: ";
    c1.print();
    c1.set_radius(10.0);
    c1.set_origin(5, 7);
    std::cout << "\nCircle c1 modificado: ";
    c1.print();
    std::cout << "\nArea = " << c1.area() << std::endl;
    std::cout << "Diametro = " << c1.diameter() << std::endl;



    std::cout << "\nCircle c2: ";
    c2.print();
    std::cout << "\nCircle c3: ";
    c3.print();

    return 0;
}