#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>


void    printStack(std::stack<int> stack) {

    std::stack<int> tempStack = stack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << std::endl;
        tempStack.pop();
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN [expression]" << std::endl;
        return 1;
    }
    //print the expression
    std::cout << "Expression: " << argv[1] << std::endl;

    //criar uma stack para os numeros
    std::stack<int> numbers;

    //percorrer a string
    int a = 0;
    int b = 0;
    while (*argv[1]) {
        //std::cout << "Char: " << *argv[1] << std::endl;
        if (isdigit(*argv[1])) {
            std::cout << "Char: " << *argv[1] << std::endl;
            numbers.push(atoi(argv[1]));
        }
        if (*argv[1] == '+') {
            std::cout << "Operator: " << *argv[1];
            //Retirar os dois numeros do topo da stack e guardar numa variavel
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            //Somar os dois numeros e guardar na stack
            std::cout << "result: " << a + b << std::endl;
            numbers.push(a + b);
        }
        if (*argv[1] == '-') {
            std::cout << "Operator: " << *argv[1];
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            std::cout << "result: " << a - b << std::endl;
            numbers.push(a - b);
        }
        if (*argv[1] == '*') {
            std::cout << "Operator: " << *argv[1];

            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            std::cout << "result: " << a * b << std::endl;
            numbers.push(a * b);
        }
        if (*argv[1] == '/') {
            std::cout << "Operator: " << *argv[1];
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            std::cout << "result: " << a / b << std::endl;
            numbers.push(a / b);
        }
        argv[1]++;
    }

    //print a stack
    printStack(numbers);

    return 0;
}
