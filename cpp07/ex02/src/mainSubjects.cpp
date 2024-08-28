#include <iostream>
#include "../include/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    //Aqui temos 2 arrays
    //O primeiro é um array de inteiros chamado numbers feito com a classe Array
    //O segundo é um array de inteiros chamado mirror feito com new mas não com a classe Array
    //Os 2 arrays são preenchidos com valores aleatórios
    //O primeiro array é copiado para um novo array chamado test
    //O primeiro array é preenchido com novos valores aleatórios
    //O segundo array é deletado
    //Se o primeiro array não tiver os mesmos valores que o segundo array, um erro é printado

    //O objetivo é testar se a classe Array é capaz de copiar um array para outro e se ela é capaz de deletar o array corretamente
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
