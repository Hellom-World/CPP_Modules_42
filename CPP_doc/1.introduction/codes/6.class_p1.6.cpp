#include <iostream> //Biblioteca padrao de C++ de entrada e saida
#include <cstdlib>
#define SIZE 50

using namespace std;

//ALOCAO COM C++
int main() 
{
    int *vet = NULL;
    vet = new int[SIZE];

    for(int i = 0; i < SIZE; i++)
        vet[i] = rand()%10; //rand adiciona um numero aleatorio de 0 a 9

    cout << "Vetor dinamico criado: " << endl;
    for(int i = 0; i < SIZE; i++)
        cout << vet[i] << " - ";

    delete[] vet;

    return 0;
}

/*
A linha delete[] vet; é responsável por liberar a memória alocada dinamicamente para o array vet. Em C++, quando você aloca memória dinamicamente usando o operador new[], é necessário liberar essa memória manualmente quando não for mais necessária. Isso é feito usando o operador delete[].
A diferença entre delete e delete[] é que o delete é usado para liberar a memória alocada para um único objeto, enquanto o delete[] é usado para liberar a memória alocada para arrays.
Portanto, a linha delete[] vet; libera a memória alocada para o array vet.
Essa funcionalidade é possibilitada pela biblioteca padrão do C++, <new>, que define os operadores new e delete para alocação e liberação de memória dinâmica.
*/

/*+----------------------+---------------------------------------------------------------------------------------+
| Função               | Descrição                                                                             |
+----------------------+---------------------------------------------------------------------------------------+
| int atoi(const char* nptr)          | Converte uma string representando um número em uma variável do tipo int.                    |
| long atol(const char* nptr)         | Converte uma string representando um número em uma variável do tipo long int.                |
| long long atoll(const char* nptr)   | Converte uma string representando um número em uma variável do tipo long long int.           |
| double atof(const char* nptr)       | Converte uma string representando um número em uma variável do tipo double.                  |
| int rand()                          | Retorna um número pseudo-aleatório no intervalo de [0, RAND_MAX].                            |
| void srand(unsigned int seed)       | Define a semente para a geração de números aleatórios pela função rand().                   |
| void exit(int status)               | Encerra a execução do programa com o status de saída especificado.                           |
| void abort()                        | Encerra abruptamente a execução do programa.                                                 |
| void* malloc(size_t size)           | Aloca uma quantidade de memória especificada pelo parâmetro size, retornando um ponteiro     |
|                                    | para a memória alocada.                                                                      |
| void* calloc(size_t nmemb, size_t size) | Aloca e inicializa um bloco de memória para armazenar um array de elementos, onde           |
|                                    | cada elemento é inicializado com zero.                                                       |
| void* realloc(void* ptr, size_t size)  | Altera o tamanho do bloco de memória previamente alocado apontado por ptr, para o          |
|                                    | novo tamanho especificado por size.                                                          |
| void free(void* ptr)                | Libera o bloco de memória previamente alocado apontado por ptr.                              |
| char* getenv(const char* name)      | Obtém o valor de uma variável de ambiente específica.                                         |
| int system(const char* command)     | Executa um comando do sistema operacional especificado pela string command.                   |
+----------------------+---------------------------------------------------------------------------------------+
*/