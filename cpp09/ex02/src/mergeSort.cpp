#include "../include/PemergeMe.hpp"

void    Merge_vec(std::vector<int>* left, std::vector<int>* right, std::vector<int>* list) {
    
    //Limpa a lista para inserir os elementos ordenados
    list->clear();
    //Enquanto as duas listas tiverem elementos, compara e insere o menor
    while (left->size() > 0 && right->size() > 0) {
        if (left->front() <= right->front()) {
            list->push_back(left->front());
            //Remove o elemento da lista para não ser comparado novamente
            left->erase(left->begin());
        } else {
            list->push_back(right->front());
            right->erase(right->begin());
        }
    }
    //Isso é feito quando temos lista de tamanho ímpar
    //Quando a lista da direita acabar, insere o restante da lista da esquerda
    while (left->size() > 0) {
        list->push_back(left->front());
        left->erase(left->begin());
    }
    //Quando a lista da esquerda acabar, insere o restante da lista da direita
    while (right->size() > 0) {
        list->push_back(right->front());
        right->erase(right->begin());
    }
}

void    Merge(std::deque<int>* left, std::deque<int>* right, std::deque<int>* list) {
    
    //Limpa a lista para inserir os elementos ordenados
    list->clear();
    //Enquanto as duas listas tiverem elementos, compara e insere o menor
    while (left->size() > 0 && right->size() > 0) {
        if (left->front() <= right->front()) {
            list->push_back(left->front());
            //Remove o elemento da lista para não ser comparado novamente
            left->pop_front();
        } else {
            list->push_back(right->front());
            right->pop_front();
        }
    }
    //Isso é feito quando temos lista de tamanho ímpar
    //Quando a lista da direita acabar, insere o restante da lista da esquerda
    while (left->size() > 0) {
        list->push_back(left->front());
        left->pop_front();
    }
    //Quando a lista da esquerda acabar, insere o restante da lista da direita
    while (right->size() > 0) {
        list->push_back(right->front());
        right->pop_front();
    }
}

void    MergeSort(std::deque<int>* list) {
    
    //Se a lista tiver 1 ou 0 elementos, não é necessário ordenar
    if (list->size() <= 1) {
        return;
    }
    //Divide a lista em duas partes
    std::deque<int> left;
    std::deque<int> right;
    size_t mid = list->size() / 2;

    //Preenche as duas listas
    for (size_t j = 0; j < mid; j++) {
        left.push_back(list->at(j));
    }
    for (size_t j = 0; j < list->size() - mid; j++) {
        right.push_back(list->at(j + mid));
    }
    //Recursão para dividir as listas
    MergeSort(&left);
    MergeSort(&right);

    //Quando as listas tiverem apenas 1 elemento, elas entra no merge
    Merge(&left, &right, list);
   
}

void    MergeSort_vec(std::vector<int>* list) {
    
    //Se a lista tiver 1 ou 0 elementos, não é necessário ordenar
    if (list->size() <= 1) {
        return;
    }
    //Divide a lista em duas partes
    std::vector<int> left;
    std::vector<int> right;
    size_t mid = list->size() / 2;

    //Preenche as duas listas
    for (size_t j = 0; j < mid; j++) {
        left.push_back(list->at(j));
    }
    for (size_t j = 0; j < list->size() - mid; j++) {
        right.push_back(list->at(j + mid));
    }
    //Recursão para dividir as listas
    MergeSort_vec(&left);
    MergeSort_vec(&right);

    //Quando as listas tiverem apenas 1 elemento, elas entra no merge
    Merge_vec(&left, &right, list);
   
}