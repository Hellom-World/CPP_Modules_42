#include "../include/PemergeMe.hpp"



// Merge sort
int main(int argc, char* argv[]) {
   //make list with argv to int
    std::deque<int> list;
    std::vector<int> list_vector;
    
   {
        // Início da medição de tempo
        std::clock_t start = std::clock();

        Parser(argc, argv, &list);
        std::cout << "Before sorting: ";
        aux_print_list(list);
        Make_Algorithm(&list, 2);
        std::cout << "After sorting: ";
        aux_print_list(list);

        // Fim da medição de tempo
        std::clock_t end = std::clock();
        // Calcula a duração em segundos
        double duration = (end - start) / (double)CLOCKS_PER_SEC;
        // Imprime o tempo de execução em us
        std::cout << "Time process with " << list.size() << " elements: " << duration * 1000000 << "us and using std::deque with MergeInsertSort" << std::endl;
        std::cout << std::endl;

   }

   {
        // Início da medição de tempo
        std::clock_t start = std::clock();

        Parser_vec(argc, argv, &list_vector);
        std::cout << "Before sorting: ";
        aux_print_list_vec(list_vector);
        Make_Algorithm_vec(&list_vector, 2);
        std::cout << "After sorting: ";
        aux_print_list_vec(list_vector);

        // Fim da medição de tempo
        std::clock_t end = std::clock();
        // Calcula a duração em segundos
        double duration = (end - start) / (double)CLOCKS_PER_SEC;
        // Imprime o tempo de execução em us
        std::cout << "Time process with " << list_vector.size() << " elements: " << duration * 1000000 << "us and using std::vector with MergeInsertSort" << std::endl;
   }


}
