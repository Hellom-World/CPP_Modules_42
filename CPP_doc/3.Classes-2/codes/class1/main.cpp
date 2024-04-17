#include "date.h"

int main() {

	const Date aniversario {7, 11, 1985};
    std::cout << "Aniversario do professor: ";
    aniversario.print();
    std::cout << "\nMes do aniversario: " << aniversario.get_month();
    std::cout << "\nVezes que foi imprimido: " << aniversario.get_count() << std::endl;

    Date today {31, 8, 2020};
    std::cout << "\nHoje: ";
    today.print();
    std::cout << "\nInstancias: " << Date::how_many_instances() << std::endl;
    return 0;
}