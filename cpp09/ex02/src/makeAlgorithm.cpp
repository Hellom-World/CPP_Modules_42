#include "../include/PemergeMe.hpp"

void    Order_verify_list_vec(std::vector<int>& list) {
    //Se encontrar algum elemento fora de ordem, imprime o elemento e a posição
    for (size_t i = 0; i < list.size() - 1; i++) {
        if (list[i] > list[i + 1])
        {
            std::cerr << "Error: " << list[i] << " is bigger than " << list[i + 1] << std::endl;
            exit(1);
        }
        
    }
}

void    Order_verify_list(std::deque<int>& list) {
    //Se encontrar algum elemento fora de ordem, imprime o elemento e a posição
    for (size_t i = 0; i < list.size() - 1; i++) {
        if (list[i] > list[i + 1])
        {
            std::cerr << "Error: " << list[i] << " is bigger than " << list[i + 1] << std::endl;
            exit(1);
        }
        
    }
}

void    Make_Algorithm(std::deque<int>* list, int type) {

    std::string str;
    
    
    //merge insert sort c++ 98
    //MergeInsertSort(list);
    


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
   
    
    // Verifica se a lista está ordenada
    Order_verify_list(*list);
}

void    Make_Algorithm_vec(std::vector<int>* list, int type) {

    std::string str;
    
    
    //merge insert sort c++ 98
    //MergeInsertSort(list);
    


    // Chama a função MergeSort
    if (type == 1)
    {
        MergeSort_vec(list);
        str = "MergeSort";
    }
    if (type == 2)
    {
        MergeInsertSort_vec(list);
        str = "MergeInsertSort";
    }
   
    
    // Verifica se a lista está ordenada
    Order_verify_list_vec(*list);
}