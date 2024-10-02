#include <iostream> // for cout
#include "vector" // for vector
#include "string" // for string
#include "deque" // for deque
#include "cstdlib" // for atoi
#include "cstring" // for strlen
#include "ctime" // for clock_t
#include "fstream" // for ifstream
#include "algorithm" // for replace



void    Merge(std::deque<int>& left, std::deque<int>& right, std::deque<int>& list) {
    
    //Limpa a lista para inserir os elementos ordenados
    list.clear();
    //Enquanto as duas listas tiverem elementos, compara e insere o menor
    while (left.size() > 0 && right.size() > 0) {
        if (left.front() <= right.front()) {
            list.push_back(left.front());
            //Remove o elemento da lista para não ser comparado novamente
            left.pop_front();
        } else {
            list.push_back(right.front());
            right.pop_front();
        }
    }
    //Isso é feito quando temos lista de tamanho ímpar
    //Quando a lista da direita acabar, insere o restante da lista da esquerda
    while (left.size() > 0) {
        list.push_back(left.front());
        left.pop_front();
    }
    //Quando a lista da esquerda acabar, insere o restante da lista da direita
    while (right.size() > 0) {
        list.push_back(right.front());
        right.pop_front();
    }
}

void    MergeSort(std::deque<int>& list) {
    
    //Se a lista tiver 1 ou 0 elementos, não é necessário ordenar
    if (list.size() <= 1) {
        return;
    }
    //Divide a lista em duas partes
    std::deque<int> left;
    std::deque<int> right;
    size_t mid = list.size() / 2;

    //Preenche as duas listas
    for (size_t j = 0; j < mid; j++) {
        left.push_back(list[j]);
    }
    for (size_t j = 0; j < list.size() - mid; j++) {
        right.push_back(list[mid + j]);
    }
    //Recursão para dividir as listas
    MergeSort(left);
    MergeSort(right);

    //Quando as listas tiverem apenas 1 elemento, elas entra no merge
    Merge(left, right, list);
   
}

void    InsertSort(std::deque<int>& list) {
    //implementa o insert sort
    //https://www.geeksforgeeks.org/insertion-sort/
    for (size_t i = 1; i < list.size(); i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

void    MergeInsertSort(std::deque<int>& list) {
    //merge insert sort
    //Se a lista for impar, guardar o último elemento
    int last = 0;
    if (list.size() % 2 != 0) {
        last = list.back();
        list.pop_back();
    }
    
    std::deque<std::deque<int> > deq_deq;
    //Calcular e criar deques para ter 2 elementos em cada a partir da lista
    size_t deq_size = list.size() / 2;
    for (size_t i = 0; i < deq_size; i++) {
        std::deque<int> deq;
        deq.push_back(list.front());
        list.pop_front();
        deq.push_back(list.front());
        list.pop_front();
        deq_deq.push_back(deq);
    }
    
    //percorrer o deque de deques e printar os elementos
    std::cout << "Before Insert Sort" << std::endl;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        std::cout << " | ";
        //printa o primeiro elemento
        std::cout << deq_deq[i].front() << " , ";
        //printa o segundo elemento
        std::cout << deq_deq[i].back();
        std::cout << " | " << std::endl;
    }

    //Ordena os elementos de cada deque
    for (size_t i = 0; i < deq_deq.size(); i++) {
        InsertSort(deq_deq[i]);
    }

    //percorrer o deque de deques e printar os elementos
    std::cout << "After Insert Sort" << std::endl;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        std::cout << " | ";
        //printa o primeiro elemento
        std::cout << deq_deq[i].front() << " , ";
        //printa o segundo elemento
        std::cout << deq_deq[i].back();
        std::cout << " | " << std::endl;
    } 

    //Percorre deque e reordena os pares comparando maior numero de cada deque
    for (size_t i = 0; i < deq_deq.size(); i++) {
        for (size_t j = i + 1; j < deq_deq.size(); j++) {
            if (deq_deq[i].back() > deq_deq[j].back()) {
                std::swap(deq_deq[i], deq_deq[j]);
            }
        }
    }

    //percorrer o deque de deques e printar os elementos
    std::cout << "After Reorder" << std::endl;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        std::cout << " | ";
        //printa o primeiro elemento
        std::cout << deq_deq[i].front() << " , ";
        //printa o segundo elemento
        std::cout << deq_deq[i].back();
        std::cout << " | " << std::endl;
    }

    //Cria um novo deque de nome "S" com os maiores elementos de cada deque
    std::deque<int> S;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        S.push_back(deq_deq[i].back());
    }
    //Printar S
    std::cout << "S = ";
    for (size_t i = 0; i < S.size(); i++) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;

    //Printa os menores elementos de cada deque
    std::cout << "----pos 1----" << std::endl;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        //printa o primeiro elemento
        std::cout << deq_deq[i].front() << " ";
    }

    //Criar sequencia de jacobsthal com base no tamanho de deq_deq
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (size_t i = 2; i < deq_deq.size(); i++) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }
    //Printar jacobsthal
    std::cout << std::endl;
    std::cout << "Jacobsthal = ";
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;



    //printa o elemento retirado
    if (last != 0) {
        std::cout << "Last: " << last << std::endl;
    }
}

void verifyNumber(char* argv) {
    int flag = 0;
    
    for (size_t i = 0; i < strlen(argv); i++) {
        if (argv[i] == '+')
        {
            flag++;
            continue;
        }
        if (!isdigit(argv[i]) || flag > 1) {
            std::cerr << "Error: " << argv << " is not a valid number" << std::endl;
            exit(1);
        }
    }
}
void verifyMax(char* argv) {
    long numLong = strtol(argv, NULL, 10);
    if (numLong > 2147483647) {
        std::cerr << "Error: " << argv << " is too big" << std::endl;
        exit(1);
    }
}



void    Make_Algorithm(int argc, char* argv[], std::deque<int>& list, int type) {

    std::string str;
    
    for (int i = 1; i < argc; i++) {
            //verify that the string is a number
            verifyNumber(argv[i]);

            //convert string to long for verification
            verifyMax(argv[i]);

            //string to int with atoi
            int num = atoi(argv[i]);
            list.push_back(num);
        }
    //merge insert sort c++ 98
    //MergeInsertSort(list);
    
        // Início da medição de tempo
    std::clock_t start = std::clock();

    // Chama a função MergeSort
    if (type == 1)
    {
        MergeSort(list);
        str = "MergeSort";
    }
    if (type == 2)
    {
        MergeInsertSort(list);
        str = "MergeInsertSort";
    }

    // Fim da medição de tempo
    std::clock_t end = std::clock();

    // Calcula a duração em segundos
    double duration = (end - start) / (double)CLOCKS_PER_SEC;


    //print list c++ 98
    /*std::deque<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/

    // Imprime o tempo de execução em us
    std::cout << "Time process with " << argc - 1 << " elements: " << duration * 1000000 << "us and using std::deque with " << str << std::endl;
    std::cout << std::endl;
    list.clear();
}

void    IntNumberGeneration(int howMany) {
    for (int i = 0; i < howMany; i++) {
        std::cout << rand() % 1000 << " ";
    }
}

// Merge sort
int main(int argc, char* argv[]) {
   //make list with argv to int
    std::deque<int> list;
    int MergeSort = 1;
    int MergeInsertSort = 2;

    std::cout << std::endl;
    std::cout << "Elements: " << argc - 1 << std::endl;
    Make_Algorithm(argc, argv, list, MergeSort);
    
    Make_Algorithm(argc, argv, list, MergeInsertSort);

    //IntNumberGeneration(3000);

    // Proximas tarefas
    // 1. Refatorar main criando uma biblioteca para as funcoes auxiliares
    // 2. Implementar o algoritmo de ordenação Merge Insert Sort
    // 3. Comparar o tempo de execução dos algoritmos de ordenação
    // 4. Implementar o algoritmo de ordenação Ford-Johnson
    // 5. Refazer todas as etapas anteriores utilizando a biblioteca vector
}
