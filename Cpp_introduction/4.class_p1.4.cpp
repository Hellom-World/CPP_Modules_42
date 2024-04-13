#include <iostream> 
using namespace std;

int main() 
{
    int a = 50;
    cout << "Valor de a: " << a << "\n";
    cout << "Endereco de a: " << &a << "\n";

   // int *ptr_a = NULL; Versao C++98
    int *ptr_a = nullptr; //Versao C++11

    ptr_a = &a;
    cout << "Valor do ptr_a: " << ptr_a << "\n";
    cout << "Valor apontado por ptr_a: " << *ptr_a << "\n";
    
    int &refa = a;
    cout << "Valor apontado por refa: " << refa << "\n";
    return 0;
}