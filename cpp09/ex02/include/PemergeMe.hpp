#ifndef PEMERGEME_HPP
#define PEMERGEME_HPP

#include <iostream> // for cout
#include "vector" // for vector
#include "string" // for string
#include "deque" // for deque
#include "cstdlib" // for atoi
#include "cstring" // for strlen
#include "ctime" // for clock_t
#include "fstream" // for ifstream
#include "algorithm" // for replace

void    aux_print_list(std::deque<int>& list);
void    Merge(std::deque<int>* left, std::deque<int>* right, std::deque<int>* list);
void    MergeSort(std::deque<int>* list);
void    InsertSort(std::deque<int>& list);
void    MergeInsertSort(std::deque<int>* list);
void    Parser(int argc, char* argv[], std::deque<int>* list);
void    verifyNumber(char* str);
void    verifyMax(char* str);
void    aux_print_pairs(std::deque<std::deque<int> >* deq_deq);
void    aux_print_firsts(std::deque<std::deque<int> >* deq_deq);
void    keep_last(std::deque<int>* list, int* last);
void    Make_Algorithm(std::deque<int>* list, int type);
void    Order_verify_list(std::deque<int>& list);



// Vector

void    aux_print_list_vec(std::vector<int>& list);
void    Merge_vec(std::vector<int>* left, std::vector<int>* right, std::vector<int>* list);
void    MergeSort_vec(std::vector<int>* list);
void    InsertSort_vec(std::vector<int>& list);
void    MergeInsertSort_vec(std::vector<int>* list);
void    Parser_vec(int argc, char* argv[], std::vector<int>* list);
void    keep_last_vec(std::vector<int>* list, int* last);
void    Make_Algorithm_vec(std::vector<int>* list, int type);
void    Order_verify_list_vec(std::vector<int>& list);

#endif