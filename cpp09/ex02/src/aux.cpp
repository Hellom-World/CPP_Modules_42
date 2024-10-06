#include "../include/PemergeMe.hpp"

void    aux_print_list(std::deque<int>& list) {
    std::deque<int>::iterator it;
    std::cout << "(AXP)";
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    aux_print_pairs(std::deque<std::deque<int> >* deq_deq) {
    for (size_t i = 0; i < deq_deq->size(); i++) {
        std::cout << " | ";
        std::cout << deq_deq->at(i).front() << " , ";
        std::cout << deq_deq->at(i).back();
        std::cout << " | " << std::endl;
    }
}

void    aux_print_firsts(std::deque<std::deque<int> >* deq_deq) {
    std::cout << "Firsts in deques pair= ";
    for (size_t i = 0; i < deq_deq->size(); i++) {
        std::cout << deq_deq->at(i).front() << " ";
    }
    std::cout << std::endl;
}

void    aux_print_list_vec(std::vector<int>& list) {
    std::vector<int>::iterator it;
    std::cout << "aux_print_list_vec(): ";
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}