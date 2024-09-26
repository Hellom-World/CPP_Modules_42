#include <iostream>
#include "vector"
#include "string"
#include "deque"
#include "cstdlib"
#include "cstring"



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

// Merge sort
int main(int argc, char* argv[]) {
   //make list with argv to int
    std::deque<int> list;

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
    MergeInsertSort(list);
    
    //MergeSort(list);


    //print list c++ 98
    std::deque<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}