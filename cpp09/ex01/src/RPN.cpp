#include "../include/RPN.hpp"

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
        if ((*input == '+' || *input == '-' || *input == '*' || *input == '/') && (*(input - 1) == '+' || *(input - 1) == '-' || *(input - 1) == '*' || *(input - 1) == '/')) {
            std::cerr << "Error: Invalid expression " << std::endl;
            exit(1);
        }
        if (isdigit(*input) && isdigit(*(input + 1))) {
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

void    operation_aux(int a, int b, int c, std::stack<int> &numbers, char op) {
    

    a = numbers.top();
    numbers.pop();
    verifyEmptyStack(numbers);
    b = numbers.top();
    numbers.pop();
    if (c)
        show_expression(a, b, op, NULL);
    switch (op)
    {
        case '+':
            numbers.push(b + a);
            break;
        case '-':
            numbers.push(b - a);
            break;
        case '/':
            if (a == 0) {
                std::cerr << "Error: Division by zero." << std::endl;
                exit(1);
            }
            numbers.push(b / a);
            break;
        case '*':
            numbers.push(b * a);
            break;
        default:
            break;
    }

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
            if ((*++argv[1]) == ' ' || *argv[1] == '\0') {
                numbers.push(atoi(argv[1] - 1));
            }
        }
        //identifica o operador e faz a operacao
        if (*argv[1] == '+')
            operation_aux(a, b, c, numbers, '+');
        if (*argv[1] == '-')
            operation_aux(a, b, c, numbers, '-');
        if (*argv[1] == '*')
            operation_aux(a, b, c, numbers, '*');
        if (*argv[1] == '/')
            operation_aux(a, b, c, numbers, '/');
        argv[1]++;
    }
    verifyStackSize(numbers);
}

