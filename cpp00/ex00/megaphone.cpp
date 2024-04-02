#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; argv[i] != NULL; i++) {
            for (int j = 0; argv[i][j] != '\0'; j++) {
                char c = argv[i][j];
                c = (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c; // Converte para maiúsculas se for uma letra minúscula
                std::cout << c;
            }
            std::cout << (argv[i + 1] != NULL ? " " : ""); // Adiciona espaço apenas se houver outra palavra
        }
    }
    std::cout << std::endl; // Quebra de linha após cada frase 
    return 0;
}