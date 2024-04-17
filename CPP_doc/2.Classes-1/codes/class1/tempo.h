//Arquivo de cabecalo (header)
#ifndef TEMPO_H
# define TEMPO_H

#include <iostream>

class Tempo {
    //membros privados
private:
    int hora, minuto, segundo;

public:
    Tempo(); //construtor -inicializador
    Tempo(int, int, int); //Para iniciar o construtor com um valor ja definido

    void	setTempo(int, int, int); //para criar um
		void	imprime(); //para imprimir a hora

		~Tempo() { }; //destrutor - para destruir a classe e limpar a memoria.
};

# endif