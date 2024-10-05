#include "../include/PemergeMe.hpp"

void    Order_verify_list(std::deque<int>& list) {
    //Se encontrar algum elemento fora de ordem, imprime o elemento e a posição
    for (size_t i = 0; i < list.size() - 1; i++) {
        if (list[i] > list[i + 1])
        {
            std::cerr << "Error: " << list[i] << " is bigger than " << list[i + 1] << std::endl;
            exit(1);
        }
        
    }
    std::cout << "Lista ordenada corretamente" << std::endl;
}

void    Make_Algorithm(std::deque<int>* list, int type) {

    std::string str;
    
    
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
    // Imprime o tempo de execução em us
    std::cout << "Time process with " << list->size() << " elements: " << duration * 1000000 << "us and using std::deque with " << str << std::endl;
    
    // Verifica se a lista está ordenada
    Order_verify_list(*list);
}


// Merge sort
int main(int argc, char* argv[]) {
   //make list with argv to int
    
    
    std::deque<int> list;
    std::deque<int> list2;
    int MergeSort = 1;
    int MergeInsertSort = 2;

    std::cout << "argc: " << argc << std::endl;

    Parser(argc, argv, &list);
    list2 = list;
    Make_Algorithm(&list, MergeSort);
    Make_Algorithm(&list2, MergeInsertSort);

    // Proximas tarefas
    // 1. Refatorar main criando uma biblioteca para as funcoes auxiliares
    // 2. Implementar o algoritmo de ordenação Merge Insert Sort
    // 3. Comparar o tempo de execução dos algoritmos de ordenação
    // 4. Implementar o algoritmo de ordenação Ford-Johnson
    // 5. Refazer todas as etapas anteriores utilizando a biblioteca vector
}
