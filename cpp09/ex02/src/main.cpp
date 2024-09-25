#include <iostream>
#include "vector"
#include "string"
#include "deque"
#include "cstdlib"
#include "cstring"

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
    //


    //print list c++ 98
    std::deque<int>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}