#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>

void    printStack(std::stack<int> stack) {

    std::stack<int> tempStack = stack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << std::endl;
        tempStack.pop();
    }
}

void    parserInput(char *input) {
    while (*input) {
        if (!isdigit(*input) && *input != '+' && *input != '-' && *input != '*' && *input != '/' && *input != ' ') {
            std::cerr << "Error: Invalid expression " << std::endl;
            exit(1);
        }
        input++;
    }
}

void    verifyStackSize(std::stack<int> stack) {
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid expression too elements" << std::endl;
        exit(1);
    }
}

void    verifyEmptyStack(std::stack<int> stack) {

    if (stack.empty()) {
        std::cerr << "Error: Invalid expression." << std::endl;
        exit(1);
    }
}

void    show_expression(int a, int b, char op, char **expression) {

    if (op == '+')
        std::cout << a << " " << op << " " << b << " = " << a + b << std::endl;
    if (op == '-')
        std::cout << a << " " << op << " " << b << " = " << a - b << std::endl;
    if (op == '*')
        std::cout << a << " " << op << " " << b << " = " << a * b << std::endl;
    if (op == '/')
        std::cout << a << " " << op << " " << b << " = " << a / b << std::endl;
    if (expression)
        std::cout << "Expression: "<< *expression << std::endl;
}

void    machine_calculator(std::stack<int> &numbers, char **argv, int c) {

    int a = 0;
    int b = 0;

    if (argv[1][0] == '-' || argv[1][0] == '+' || argv[1][0] == '*' || argv[1][0] == '/') {
        std::cerr << "Error: Invalid expression." << std::endl;
        exit(1);
    }
    while (*argv[1]) {


        if (isdigit(*argv[1])) {
            //std::cout << "atoi: " << atoi(argv[1]) << std::endl;
            if ((*++argv[1]) == ' ' || *argv[1] == '\0') {
                numbers.push(atoi(argv[1] - 1));
            }
        }
        if (*argv[1] == '+') {
            a = numbers.top();
            numbers.pop();
            verifyEmptyStack(numbers);
            b = numbers.top();
            numbers.pop();
            if (c)
                show_expression(a, b, '+', NULL);
            numbers.push(b + a);
        }
        if (*argv[1] == '-') {
            a = numbers.top();
            numbers.pop();
            verifyEmptyStack(numbers);
            b = numbers.top();
            numbers.pop();
            if (c)
                show_expression(a, b, '-', NULL);
            numbers.push(b - a);
        }
        if (*argv[1] == '*') {
            a = numbers.top();
            numbers.pop();
            verifyEmptyStack(numbers);
            b = numbers.top();
            numbers.pop();
            if (c)
                show_expression(a, b, '*', NULL);
            numbers.push(b * a);
        }
        if (*argv[1] == '/') {
            a = numbers.top();
            numbers.pop();
            verifyEmptyStack(numbers);
            b = numbers.top();
            numbers.pop();
            if (c)
                show_expression(a, b, '/', NULL);
            numbers.push(b / a);
        }
        argv[1]++;
    }
    verifyStackSize(numbers);
}

#endif
