#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <string.h> // Inclui a biblioteca para manipulação de strings
#include "Biblioteca/lista_01.h"

// Função principal do programa
int main() {
    char string[100]; // Declaração de um array de caracteres para armazenar a string

    printf("Digite uma string: "); // Solicita ao usuário que digite uma string
    fgets(string, sizeof(string), stdin); // Lê uma linha de texto digitada pelo usuário

    // Remover o caractere de nova linha, se houver
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    // Chamada da função contarCaractereARecursivo com a string digitada e índice inicial 0
    int quantidade = contarCaractereARecursivo(string, 0);

    // Imprime a quantidade de caracteres 'a' ou 'A' na string
    printf("A quantidade de caracteres 'a' ou 'A' na string é: %d\n", quantidade);

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
