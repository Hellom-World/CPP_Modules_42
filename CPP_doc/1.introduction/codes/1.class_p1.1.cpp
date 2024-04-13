#include <iostream> //Biblioteca padrao de C++ de entrada e saida
using namespace std;

//USO DA IOSTREAM, FUNCAO E CONCATENACAO DE SAIDA PADRAO
int multiplication(int n, int x)
{
    return (n * x);
}

int main() 
{
    int n = 0;

    //std::cout << "Entre com um inteiro: ";
    //std::cin >> n;
    cout << "Entre com um inteiro: ";
    cin >> n;
    cout << n << " x 2 = " << multiplication(n, 2) << "\n"; //Concatena varias mensagens
    return 0;
}

/*Descricao dos elementos que compoem a biblioteca <iostream>
+------------+-----------------+---------------------------------------------------------------+
| Categoria  | Elemento        | Descrição                                                     |
+------------+-----------------+---------------------------------------------------------------+
| Objetos    | cin             | Entrada padrão para dados do usuário (normalmente teclado).   |
|            | cout            | Saída padrão para exibição de dados (normalmente tela).       |
|            | cerr            | Saída padrão para mensagens de erro.                          |
|            | clog            | Saída padrão para mensagens de log.                           |
+------------+-----------------+---------------------------------------------------------------+
| Tipos      | streambuf       | Manipulação de buffers de entrada e saída.                    |
|            | istream         | Entrada de dados, associada a cin.                            |
|            | ostream         | Saída de dados, associada a cout.                             |
|            | iostream        | Combinação de istream e ostream.                              |
|            | ifstream        | Leitura de arquivos.                                          |
|            | ofstream        | Escrita em arquivos.                                          |
|            | fstream         | Leitura e escrita em arquivos.                                |
|            | istringstream  | Leitura de strings.                                           |
|            | ostringstream  | Escrita em strings.                                           |
|            | stringstream   | Combinação de istringstream e ostringstream.                  |
+------------+-----------------+---------------------------------------------------------------+
| Manipulador| endl            | Insere nova linha e limpa o buffer de saída.                  |
|            | ends            | Insere caractere nulo na saída.                               |
|            | flush           | Limpa o buffer de saída.                                     |
|            | setbase         | Define base numérica (hexadecimal, decimal, octal).           |
|            | setiosflags     | Define flags de formato.                                      |
|            | resetiosflags   | Redefine flags de formato.                                    |
|            | setw            | Define largura do campo de saída.                             |
|            | setprecision    | Define precisão de saída para números em ponto flutuante.     |
|            | setfill         | Define caractere de preenchimento.                             |
|            | setf            | Define flags de formato.                                      |
|            | unsetf          | Limpa flags de formato.                                       |
+------------+-----------------+---------------------------------------------------------------+
| Tipos de   | streambuf       | Manipulação de buffers de entrada e saída.                    |
| Fluxo      | ios             | Sistema de entrada/saída.                                     |
|            | basic_ios       | Manipulação de objetos de fluxo.                               |
|            | istream         | Entrada de dados, associada a cin.                            |
|            | ostream         | Saída de dados, associada a cout.                             |
|            | iostream        | Combinação de istream e ostream.                              |
|            | ifstream        | Leitura de arquivos.                                          |
|            | ofstream        | Escrita em arquivos.                                          |
|            | fstream         | Leitura e escrita em arquivos.                                |
|            | istringstream  | Leitura de strings.                                           |
|            | ostringstream  | Escrita em strings.                                           |
+------------+-----------------+---------------------------------------------------------------+


+----------------------+---------------------------------------------------------------+
| Conceito             | Explicação                                                    |
+----------------------+---------------------------------------------------------------+
| using namespace std; | Uma diretiva que simplifica o acesso aos identificadores da   |
|                      | biblioteca padrão (`std`) ao eliminar a necessidade de        |
|                      | especificar o namespace completo (`std::`) toda vez que você  |
|                      | deseja usar um identificador da biblioteca.                   |
|                      |                                                               |
|                      | Permite que você use diretamente os identificadores da        |
|                      | biblioteca padrão sem precisar especificar o namespace `std::`|
|                      | toda vez. Por exemplo, em vez de escrever `std::cout`, você    |
|                      | pode escrever apenas `cout`.                                  |
|                      |                                                               |
|                      | É recomendável usar com cautela, pois o uso excessivo pode    |
|                      | causar conflitos de nomes, especialmente em projetos grandes.  |
|                      | Isso ocorre porque importa todos os identificadores do        |
|                      | namespace `std` para o escopo atual, podendo resultar em      |
|                      | ambiguidades se houver identificadores com o mesmo nome em    |
|                      | outros namespaces ou no próprio código.                       |
|                      |                                                               |
|                      | Muitos desenvolvedores preferem usar a qualificação explícita|
|                      | (`std::`) para evitar conflitos de nomes e garantir a clareza |
|                      | do código, especialmente em arquivos de cabeçalho e em       |
|                      | projetos grandes.                                             |
+----------------------+---------------------------------------------------------------+*/
