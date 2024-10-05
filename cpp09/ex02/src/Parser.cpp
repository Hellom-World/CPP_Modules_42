#include "../include/PemergeMe.hpp"

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

void    verifyMax(char* str) {
    if (strlen(str) > 10) {
        std::cerr << "Error: " << str << " is too big" << std::endl;
        exit(1);
    }
}

void    Parser(int argc, char* argv[], std::deque<int>* list) {
    for (int i = 1; i < argc; i++) {
        //verify that the string is a number
        verifyNumber(argv[i]);

        //convert string to long for verification
        verifyMax(argv[i]);

        //string to int with atoi
        int num = atoi(argv[i]);
        list->push_back(num);
    }
}

