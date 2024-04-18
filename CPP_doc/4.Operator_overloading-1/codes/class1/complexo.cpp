#include "complexo.h"


    Complexo::Complexo(float r, float i) {
        real = r;
        imag = i;
    }

	//interface
	void Complexo::print() {
		std::cout << real << " + (" << imag << ")i" << std::endl;
	}

	Complexo Complexo::add(Complexo& par) {
		float x = this->real + par.real;
		float y = this->imag + par.imag;
		return Complexo(x, y);
	}

	Complexo Complexo::sub(Complexo& par) {
		float x = this->real - par.real;
		float y = this->imag - par.imag;
		return Complexo(x, y);
	}


