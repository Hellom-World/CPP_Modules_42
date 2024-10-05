#include  "../include/PemergeMe.hpp"

void    InsertSort(std::deque<int>& list) {
    //implementa o insert sort
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