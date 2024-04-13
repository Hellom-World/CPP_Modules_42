#include <iostream> //Biblioteca padrao de C++ de entrada e saida
using namespace std;

//Exemplo de funcao errada
void soma(int x, int y, int z)
{
    z = x + y;
}

//Exemplo de funcao que utiliza ponteiros
void soma2(int *x, int *y, int *z)
{
    *z = *x + *y;
}

//Exemplo de funcao que utiliza referencias
void soma3(int &x, int &y, int &z)
{
    z = x + y;
}

int main() 
{
    int  a = 10, b = 20, c = 0;
    soma(a, b, c);
    cout << "Valor de c (por valor): " << c << "\n";
    soma2(&a, &b, &c);
    cout << "Valor de c (por ref pont): " << c << "\n";
    soma3(a, b, c);
    cout << "Valor de c (por ref ref): " << c << "\n";
    return 0;
}

