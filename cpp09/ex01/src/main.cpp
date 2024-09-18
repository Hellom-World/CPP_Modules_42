#include "../include/RPN.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    int debug = 0; //habilita printar a expressao

    //print the expression
    if (debug)
        show_expression(0, 0, 0, &argv[1]);

    //criar uma stack para os numeros
    std::stack<int> numbers;

    //faz o tratamento do input
    parserInput(argv[1]);



    //faz o calculo
    machine_calculator(numbers, argv, debug);

    //verifica se a stack tem um unico elemento
    verifyStackSize(numbers);
    //print a stack
    printStack(numbers);

    return 0;
}
