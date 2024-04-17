#include "date.h"


int Date::howmany = 0;

//construtor
Date::Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy}{
	count = 0;
	howmany++;
}
Date::~Date() { howmany--; };
//imprime a data e conta a quantidade de chamadas
void	Date::print() const {
	std::cout << d << "/" << m << "/" << y;
	count++;
}

void	Date::set_day(int value) {
	if (value > 0 && value <= 31)
		d = value;
}

void	Date::set_month(int value) {
	if (value > 0 && value <= 12)
		m = value;
}
void	Date::set_year(int value) {
	if (value >= 0)
		y = value;
};
