#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

// Função recursiva para encontrar o maior valor em um array
int encontrarMaiorRecursivo(int array[], int tamanho) {
    // Caso base: Se o tamanho do array for 1, retorne o único elemento
    if (tamanho == 1) {
        return array[0]; // Retorna o único elemento do array
    }

    // Chamada recursiva: Encontra o maior valor entre o primeiro elemento e o restante do array
    int max_resto = encontrarMaiorRecursivo(array + 1, tamanho - 1);

    // Comparar o maior valor do restante do array com o primeiro elemento
    if (array[0] > max_resto) {
        return array[0]; // Retorna o primeiro elemento se for maior que o máximo do restante
    } else {
        return max_resto; // Retorna o máximo do restante se for maior ou igual ao primeiro elemento
    }
}

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
