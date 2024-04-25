#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <string.h> // Inclui a biblioteca para manipulação de strings

// Declaração da função contarCaractereARecursivo
int contarCaractereARecursivo(char str[], int index) {
    // Caso base: se chegarmos ao final da string, retorne 0
    if (str[index] == '\0' || str[index] == '\n') { // Verifica se o caractere atual é o nulo de terminação ou nova linha
        return 0; // Retorna 0 se chegou ao final da string
    }

    // Verifica se o caractere atual é 'a' ou 'A' e incrementa o contador
    int contador = (str[index] == 'a' || str[index] == 'A') ? 1 : 0;

    // Chamada recursiva para verificar o restante da string
    return contador + contarCaractereARecursivo(str, index + 1);
}

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
