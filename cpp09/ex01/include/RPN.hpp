#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>

void    printStack(std::stack<int> stack);
void    parserInput(char *input);
void    verifyStackSize(std::stack<int> stack);
void    verifyEmptyStack(std::stack<int> stack);
void    show_expression(int a, int b, char op, char **expression);
void    operation_aux(int a, int b, int c, std::stack<int> &numbers, char op);
void    machine_calculator(std::stack<int> &numbers, char **argv, int debug);

#endif
