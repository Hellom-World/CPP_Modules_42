//Arquivo de cabecalo (header)
#ifndef DATE_H
# define DATE_H

#include <iostream>

class Date {
	//membros privados
private:
	int d, m, y;
	mutable int count;
	static int howmany;

public:
	Date(int = 1, int = 1, int = 1972); //Para iniciar o construtor com um valor ja definido
	~Date();
	int	get_count() const {return count;}
	int	get_day() const {return d;}
	int get_month() const {return m;}
	int	get_year() const {return y;}
	void	print() const;
	static int how_many_instances() {return howmany;}

	void	set_day(int);
	void	set_month(int);
	void	set_year(int);
};

# endif