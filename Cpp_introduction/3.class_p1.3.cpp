#include <iostream> 
#include <string> //Biblioteca criada com o objetivo de manipuilar alocacao de memoria de forma mais simples
using namespace std;


//UTILIZACAO DA BIBLIOTECA STRING E EXEMPLO DE CONCATENACAO DE FUNCAO
int main() 
{
    string nome = "";
    string sobre = "";
    string nome_completo = "";

    cout << "Entre com seu nome: ";
    //cin >> nome; (USAR cin AQUI EH ERRADO POIS ELE SOH PEGA A PRIMEIRA PALAVRA)
    getline(cin, nome); //funcao da biblioteca <iostream> que pega a linha inteira
 
    cout << "Agora entre com seu sobrenome: ";
    cin >> sobre;

    nome_completo = nome + " " + sobre; //Concatena as strings

    cout << "Seja Bem VINDO, " << nome_completo << "!!\n";

    return 0;
}

/*+-------------+------------------------------------------------------------+
| Objeto      | Descrição                                                  |
+-------------+------------------------------------------------------------+
| std::string | Classe para representar strings como objetos.               |
|             |                                                              |
|             | Oferece uma interface conveniente para manipulação de       |
|             | strings, incluindo construção, cópia, concatenação,         |
|             | comparação, busca, substituição, extração de substrings,    |
|             | entre outras operações.                                    |
+-------------+------------------------------------------------------------+
| std::wstring| Similar a std::string, mas para strings largas (wide        |
|             | strings).                                                   |
|             |                                                              |
|             | Usa wide characters (wchar_t) em vez de caracteres         |
|             | estreitos (char).                                           |
+-------------+------------------------------------------------------------+
*/