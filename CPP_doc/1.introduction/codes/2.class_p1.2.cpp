#include <iostream> //Biblioteca padrao de C++ de entrada e saida
using namespace std;

//UTILIZACAO DE OPERADOR FOR E RANGE-FOR
int main() 
{
    //C++98 version
    //int vetor[] = {1,2,3,4,5,6,7,8,9,10};
    
    //C++11 version
    int vetor[] {1,2,3,4,5,6,7,8,9,10};
    
    cout << "Percorrendo o vetor de maneira normal(C++98): \n";
    for(int i = 0; i < 10; i++)
        cout << vetor[i] << " - ";

    cout << "\n\nPercorrendo o vetor com range-for(C++11): \n";
    for(int x : vetor)
        cout << x << " - ";
    return 0;
}
