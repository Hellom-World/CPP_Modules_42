//Arquivo de cabecalo (header)
#ifndef COMPLEXO_H
# define COMPLEXO_H

#include <iostream>

class Complexo {
	private:
		float real, imag;
	public:
		Complexo(float=0.0, float=0.0);	//construtor;
		~Complexo() {}	//destrutor;

		//interface
		void print();
		Complexo add(Complexo&);
		Complexo sub(Complexo&);
};

#endif
