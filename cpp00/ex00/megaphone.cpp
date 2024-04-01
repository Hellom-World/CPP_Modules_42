#include <iostream>
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; av[i]; i++) {
            for (int j = 0; av[i][j]; j++)
                std::cout << (char) std::toupper(av[i][j]); // Converte para maiúsculas
            std::cout << " ";
        }
		std::cout << std::endl; // Quebra de linha após cada frase
    }
    return 0;
}
