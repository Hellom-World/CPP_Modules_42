#include "tempo.h"

Tempo::Tempo() {
		hora = 0;
		minuto = 0;
		segundo = 0;
}
Tempo::Tempo(int hh, int mm, int ss) {
	setTempo(hh, mm, ss);
}

void	Tempo::setTempo(int hh, int mm, int ss) {
	if (hh >= 0 && hh <= 23)
		hora = hh;
	else
		hora = 0;

	if (mm >= 0 && mm <= 59)
		minuto = mm;
	else
		minuto = 0;
	
	if (ss >= 0 && ss <= 59)
		segundo = ss;
	else
		segundo = 0;
}
void	Tempo::imprime() {
	std::cout << "{" << hora << ":" << minuto << ":" << segundo << "}";  
}

//classe = tipos definidos pelo usuario
//objeto = intancia da classe

//As classes modelam coceitos, podemos criar classes para modelar um aviao, os estados da materia ou a variacao do clima.

//As classes tem duas pricipais faces: 
        //1. A face de quem vai criar a classe. 
        //2. A face de quem vai utiliza-la