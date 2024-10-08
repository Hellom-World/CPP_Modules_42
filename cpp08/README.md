# BIBLIOTECA DE MODELO PADRAO C++ (STL)

A C++ standard template libray (STL) é uma colecao de arquivos de cabecalho que fornecem varias estruturas de dados, algoritmos e funcoes para simplificar sua experiencia de codificacao c++.
O objetivo principal da STL é economizar tempo e aumentar a eficiencia, fornecendo um conjunto pronto para uso de ferramentas uteis. Os recursos mais comumente usados da STL podem ser divididos em 3 categorias principais:

	1. Conteineres
	2. Algoritmos
	3. Iteradores


### Recipientes

Conteiners sao as estruturas de dados usadas para armazenamento e manipulacao de dados em c++. Eles sao classificados em quatro tipos:

	1. Sequencia containers
	2. Associative containers
	3. Unordered associative containers
	4. Container adptors


#### Conteiners de sequencia (sequence containers):

Sao estruturas de dados lineares de armazenam alementos de forma sequencial. Exemplos incluem:

	std::vector - Uma matriz dinamica que cresce e diminui em tempo de execucao
	std::vector<int> my_vector

	std::list - Uma lista duplamente encadeada
	std::list<int> my_list;

	std::deque - Uma fina de duas extremidades que permite insercao e exclusao em ambas as extremidades
	std::deque<int> my_deque;


#### Conteineres associativos (Associative Conteiners)

Esse containers armazenam dados de forma ordenada com chaves exclusivas. Exemplos incluem:

	std::set<int> - Uma colecao de elementos exclusivos classificados por chaves
	std::set<int> my_set;

	std::map - Uma colecao de pares chave-valor classificados por chaves.
	std::map<std::string, int> my_map;

#### Conteiners associativos nao ordenadors (Unordered associative conteiners):

Esses conteiners armazenam dados de forma nao ordenada usando tabelas hash. Exemplos incluem:

	std::unordered_set - Uma colecao de elementos unicos sem uma ordem especific
	std::unordered_set<int> my_unordered_set;

	std::unordered_map - Uma colecao de pares chave-valor sem ordem especifica
        std::unordered_map<std::string, int> my_unordered_map;

### Adpatadores de conteiners (Conteiners adaptors)

Sao conteiners baseados em outros containers existentes. Exemplos incluem:

	std::stack - Uma estrutura de dados LIFO baseada em deque ou lista
	std::stack<int> my_stack;

	std::queue - Uma estutura de dadoos FIFO baseada em deque ou lista
	std::queue<int> my_queue;

	std::priority_queue - Uma fila classificada com base em vector ou deque
	std::priority_queue<int> mt_priority_queue;


#### ALGORITIMOS

O STL fornece varios algoritmos genericos que podem ser usados para exevutar varias operacoes nos dados armazenados em conteiners. Eles sao divididos em cinco categorias:
	1. Algoritmos de sequencia nao modificadores
	2. Algoritmos de sequencia modificadores
	3. Algoritmos de classificacao
	4. Algoritmos de intervalo classificado
	5. Algoritmos numericos

Alguns exemplos incluem: std::find, std::replace, std::sort, e std::binary_search

Para classifica um vetor voce pode usar, por exemplo:

	std::vector<int> my_vec = {4, 2, 5, 1, 3};
	std::sort(my_vec.begin(), my_vec.end());

ITERADORES

Iteradores sao um conceito fundametnal no STL, pois fornecem uma maneira unificada de acessar elementos em conteinres. Iteradores podem ser pensados como uma forma avancada de ponteiros.

Cada conteiner tem seu proprio tipo de iterador, que pode ser usado para percorrer elementos e modificar valores. As operacoes de iterdor mais comuns sao begin() e end() para obter iteradores apontando para o primeiro e um apos o ultimo elemento de um conteiner, respectivamente.

Por exemplo, para iterar por um vetor e imprimir seus elementos voce pode usar o seguinte codigo

	std::vector<int> my_vec = {1, 2, 3, 4, 5};
	for(auto it = my_vec.begin(); it != my_vec.end(); ++it) {
    		std::cout << *it << " ";
	}

Esta é apenas uma breve visao geral da c++ Standard Template Library. Há muitos outros recursos e funcoes disponiveis na STL, e familiarizar-se com eles é crucial para uma programacao em c++ eficiente.


# Conteineres C++
## Vetor
Vetores sao arrays dinamicos que podem se redimensionar conforme necessario. Eles armazenamento elementos em um local de memoria contíguo, permitindo acesso aleatorio rápido usando índices.

### Exemplo

	#include <iostream>
	#include <vector>

	int main() {
		std::vector<int> vec = {1, 2, 3, 4, 5};

		vec.push_back(6); // Add an element to the end

		std::cout << "Vector contains:";
		for (int x : vec) {
			std::cout << ' ' << x;
		}
		std::cout << std::endl;
	}

## Lista
Uma lista é uma lista duplamente encadeada que permite que elementos sejam inseridos ou removidos de qualquer posicao em tempo constante. Ela nao suporta acesso aleatorio. ***Listas sao melhores do que vetores para cenarios onde voce precisa inserir ou remover elementos no meio com frequencia.***

### Exemplo

	#include <iostream>
	#include <list>

	int main() {
		std::list<int> lst = {1, 2, 3, 4, 5};

		lst.push_back(6); // Add an element to the end

		std::cout << "List contains:";
		for (int x : lst) {
			std::cout << ' ' << x;
		}
		std::cout << std::endl;
	}
## Mapa
Um mapa é um container associativo que armazena pares de chave-valor. Ele suporta a recuperacao de valores com base em suas chaves. As chaves sao classificadas em ordem crescente por padrao.

### Exemplo

	#include <iostream>
	#include <map>

	int main() {
		std::map<std::string, int> m;

		m["one"] = 1;
		m["two"] = 2;

		std::cout << "Map contains:" << std::endl;
		for (const auto &pair : m) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}

## Mapa nao ordenado

Semelhante a um mapa, um mapa nao ordenado armazena pares de chave-valor, mas é implementado usando uma tabela hash. Isso significa que unordered_map tem desempenho de caso medio mais rapido em comparacao a map, pois nao mentem a dordem classificada. No entando, o desempenho do pior caso pode ser pior que o map.

### Exemplo

	#include <iostream>
	#include <map>

	int main() {
		std::map<std::string, int> m;

		m["one"] = 1;
		m["two"] = 2;

		std::cout << "Map contains:" << std::endl;
		for (const auto &pair : m) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}

Outros tipos que vale a pena pesquisar sao: **set**, **multiset**, **deque**, **stack**, **queue**, e **priority_queue**.

# Iteradores
Iteradores sao objetos na Biblioteca Padrao C++(STL) que nos ajudam a atravessar conteiners como arrays, listas, vetores. Essencialmente, eles agem como uma ponte dentre classes de conteiner e algoritmos. Iteradores se comportam de forma semelhante a ponteiros, mas fornencem uma maneira mais generalizada e asbtrata de acessar elementos em um conteiner.

Existem diferentes tipos de iteradores que voce encontrara dependendo de seus casos de uso:

*	**Input Iterator** : Usado para ler elementos em um conteiner apenas uma vez, em uma direcao para frente. Eles nao podem modificar elementos.
### Exemplo:
	std::vector<int> nums = {1, 2, 3, 4};
	std::istream_iterator<int> input(std::cin);
	std::copy(input, std::istream_iterator<int>(), std::back_inserter(nums));

*	**Output Iterator** : Usado para escrever elementos em um conteiner apenas uma vez, em uma direcao para frente. Eles nao podem reescrever elementos.

### Exemplo:
	std::vector<int> nums = {1, 2, 3, 4};
	std::ostream_iterator<int> output(std::cout, ", ");
	std::copy(nums.begin(), nums.end(), output);

*	**Iterador Bidirecional** : Esse iteradores oferecem a habilidade de mover para frente e para tras em um conteiner. Conteineres de lista e conjunto tem iteradores bidirecionais.

### Exemplo:
	std::list<int> nums = {1, 2, 3, 4};
	std::list<int>::iterator itr;
	for (itr = nums.begin(); itr != nums.end(); ++itr) {
		std::cout << *itr << " ";
	}
	for (--itr; itr != nums.begin(); --itr) {
		std::cout << *itr << " ";
	}

# Algoritmos STL

A Standart Template Library (STL) em C++ fornece uma colecao de algoritmos genericos que sao projetados para trabalhar com varias classes de conteiner. Esse algoritmos sao implementados como funcaoes e podem ser aplicados a diferentes estruturas de dados, como arrays, vetores, listas e outros. O arquivo de cabecalho primario para algoritmos é "algorithm".

## Conceitos-chave

A Classificacao se refere a organizar uma sequencia de elementos em uma ordem especifica. O STL fornece varios algoritmos de classificacao, como std::sort, std::stable_sort, e std::partial_sort.

### std::sort (Sorting)
std::sort é usado para classificar um intervalo de elementos (primeiro, ultimo) em ordem nao decrescente (por padrao). Voce tambem pode usar funcoes de comparacao personalizadas ou expressoes lambda para alterar a odem de classificacao

### Exemplo:

	#include <algorithm>
	#include <vector>
	#include <iostream>

	int main() {
		std::vector<int> nums = {10, 9, 8, 7, 6, 5};
		std::sort(nums.begin(), nums.end());

		for (int num : nums) {
			std::cout << num << ' ';
		}
		// Output: 5 6 7 8 9 10
	}

## Procurando (Searching)
Sorting se refere a descobrir se um elemento em particular esta presente dentro de um dado intervalo de elememtos. O STL fornece varios algoritmos de pesquisa, como std::find, std::binary_search, e std::find_if.

### std::find
std::find é usado para encontrar o iterador da primeira ocorrencia de um determiinado valor dentro do intervalo (primeiro, ultimo).

### Exemplo

	#include <algorithm>
	#include <vector>
	#include <iostream>

	int main() {
		std::vector<int> nums = {5, 6, 7, 8, 9, 10};
		auto it = std::find(nums.begin(), nums.end(), 9);

		if (it != nums.end()) {
			std::cout << "Found 9 at position: " << (it - nums.begin());
		} else {
			std::cout << "9 not found";
		}
		// Output: Found 9 at position: 4
	}

## Modificando sequencias
O STL tambem fornece algoritmos para modificar sequencias, como std::remoce, std::replace, e std::unique.

### std::remove
std::remove é usado para remover todas as instancias de um valor de um conteiner dentro do intervalo fornecido (primeiro, ultimo). ***Observe que a funcao nao redimensiona o conteiner apos remover elementos***

### Exemplo:
	#include <algorithm>
	#include <vector>
	#include <iostream>

	int main() {
		std::vector<int> nums = {5, 6, 7, 6, 8, 6, 9, 6, 10};
		nums.erase(std::remove(nums.begin(), nums.end(), 6), nums.end());

		for (int num : nums) {
			std::cout << num << ' ';
		}
		// Output: 5 7 8 9 10
	}
No exemplo, a função erase do std::vector é usada para remover elementos de um intervalo do vetor. Para entender completamente como funciona, é importante destacar como std::remove e std::vector::erase interagem juntas.

### Passo a passo:

A função std::remove não remove os elementos do container diretamente. Em vez disso, ela "reorganiza" o vetor, movendo todos os elementos que não satisfazem a condição para o início do intervalo e "deixando" os elementos a serem removidos no final do vetor.

O retorno de std::remove é um iterador que aponta para o novo "fim" do vetor, onde começam os elementos "invalidados" (aqueles que devem ser removidos).

Logo,

	std::remove(nums.begin(), nums.end(), 6);
move todos os elementos diferentes de 6 para o início do vetor. O retorno desta função é um iterador que aponta para a posição logo após o último elemento válido. O vetor, após o std::remove, ficará assim:

	{5, 7, 8, 9, 10, 6, 6, 6, 6}

Note que o tamanho do vetor não foi alterado ainda. Apenas os elementos 6 foram movidos para o final.

Após o std::remove, a função erase é chamada para realmente remover os elementos. O intervalo fornecido para erase começa no iterador retornado por std::remove (onde os elementos 6 começam a aparecer) e vai até o fim do vetor (nums.end()).

	nums.erase(std::remove(nums.begin(), nums.end(), 6), nums.end());
remove os elementos do intervalo especificado (no caso, todos os 6 que foram movidos para o final).

O vetor final será:

	{5, 7, 8, 9, 10}

NOTA: Caso tenha algum exercicio nesse modulo que seja necessario usar data e tempo eu volto aqui para falar sobre o uso do mesmo.
