#include "../include/PemergeMe.hpp"

void keep_last(std::deque<int>* list, int* last) {
    *last = list->back();
    list->pop_back();
}

void MergeInsertSort(std::deque<int>* list) {
    // Se a lista for ímpar, retira o último elemento da lista e guarda em last
    int last = 0;
    if (list->size() % 2 != 0)
        keep_last(list, &last);
    
    // Cria um deque de deques para armazenar os pares de elementos
    std::deque<std::deque<int> > deq_deq;
    // Calcula e cria deques com 2 elementos em cada, a partir da lista
    size_t deq_size = list->size() / 2;
    for (size_t i = 0; i < deq_size; i++) {
        std::deque<int> deq;
        deq.push_back(list->front());
        list->pop_front();
        deq.push_back(list->front());
        list->pop_front();
        deq_deq.push_back(deq);
    }

    // Ordena os elementos de cada deque
    for (size_t i = 0; i < deq_deq.size(); i++)
        InsertSort(deq_deq[i]);

    // Reordena os pares comparando o maior número de cada deque
    for (size_t i = 0; i < deq_deq.size(); i++) {
        for (size_t j = i + 1; j < deq_deq.size(); j++) {
            if (deq_deq[i].back() > deq_deq[j].back()) {
                std::swap(deq_deq[i], deq_deq[j]);
            }
        }
    }

    // Cria um novo deque "S" com os maiores elementos de cada deque
    std::deque<int> S;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        S.push_back(deq_deq[i].back());
    }

    // Cria sequência de Jacobsthal
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (size_t i = 2; i < 14; i++) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }


    // Cria uma lista com os menores elementos de cada deque (Pend)
    std::deque<int> Pend;
    for (size_t i = 0; i < deq_deq.size(); i++) {
        Pend.push_back(deq_deq[i].front());
    }

    // Insere os elementos de Pend em S com base na sequência de Jacobsthal
    for (size_t i = 0; i < Pend.size(); i++) {
        size_t j = 0;
        std::deque<int>::iterator it = S.begin();
        // Encontrar a posição correta na sequência de Jacobsthal
        while (jacobsthal[j] < S.size()) {
            j++;
        }
        //Protetor para não acessar um índice inválido
        if (jacobsthal[j] > S.size()) {
            j--;
        }
        // Encontrar a posição correta para inserir o elemento de Pend
        while (it != S.end() && Pend[i] > *it) {
            ++it;
        }

        // Inserir o elemento de Pend na posição correta em S
        while (it != S.begin() && Pend[i] < *it) {
            --it;
        }
        // Inserir o valor de Pend na posição correta
        if (Pend[i] < *it) {
            S.insert(it, Pend[i]);
        } else {
            S.insert(it + 1, Pend[i]);
        }
    }

    // Printa a lista final S
    std::cout << "S = ";

    // Verifica se há um último elemento para reinserir
    if (last != 0) {
        //encontra a posição correta para inserir o último elemento
        std::deque<int>::iterator it = S.begin();
        while (it != S.end() && last > *it) {
            ++it;
        }
        // Inserir o elemento de Pend na posição correta em S
        S.insert(it, last);
    }
    list->clear();
    //Copiar os elementos de S para a lista original
    for (size_t i = 0; i < S.size(); i++) {
        list->push_back(S[i]);
    }
    //aux_print_list(S);
}
