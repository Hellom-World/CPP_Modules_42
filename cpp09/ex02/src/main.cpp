#include <iostream>
#include "vector"
#include "string"
#include "deque"

// Merge sort
int main(int argc, char* argv[]) {
   //make list with argv
    std::deque<std::string> list;
    for (int i = 1; i < argc; i++) {
        list.push_back(argv[i]);
    }
    //validate list only numbers c++ 98
    


    //print list c++ 98
    std::deque<std::string>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}