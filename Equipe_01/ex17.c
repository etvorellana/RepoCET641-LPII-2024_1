#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include "Biblioteca/lista_01.h"

// Função principal do programa
int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho); // Lê o tamanho do array fornecido pelo usuário

    int array[tamanho]; // Declaração de um array de inteiros com o tamanho fornecido

    printf("Digite os valores do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &array[i]); // Preenche o array com valores fornecidos pelo usuário
    }

    int maior_valor = encontrarMaiorRecursivo(array, tamanho); // Encontra o maior valor do array

    printf("O maior valor do array é: %d\n", maior_valor); // Imprime o maior valor encontrado

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
