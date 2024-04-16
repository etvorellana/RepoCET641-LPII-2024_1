#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C, necessária para usar funções como printf e scanf.

int soma_array_recursiva(int arr[], int tamanho) { // Define a função soma_array_recursiva que recebe um array de inteiros e seu tamanho como argumentos e retorna um inteiro.
    if (tamanho == 0) { // Verifica se o tamanho do array é 0.
        return 0; // Se o tamanho for 0, retorna 0 (caso base).
    }
    return arr[tamanho - 1] + soma_array_recursiva(arr, tamanho - 1); // Retorna o último elemento do array somado à chamada recursiva da função com tamanho reduzido.
}

float media_array_recursiva(int arr[], int tamanho) { // Define a função media_array_recursiva que recebe um array de inteiros e seu tamanho como argumentos e retorna um float.
    if (tamanho == 0) { // Verifica se o tamanho do array é 0.
        return 0; // Se o tamanho for 0, retorna 0 (caso base).
    }
    int soma = soma_array_recursiva(arr, tamanho); // Calcula a soma dos elementos do array chamando a função soma_array_recursiva.
    return (float)soma / tamanho; // Retorna a média dos elementos do array, convertendo a soma para float antes de dividir pelo tamanho.
}

int main() { // Define a função principal main.
    int array_teste[] = {1, 2, 3, 4, 5}; // Declara e inicializa um array de teste com alguns valores.
    int tamanho = sizeof(array_teste) / sizeof(array_teste[0]); // Calcula o tamanho do array.

    printf("Array: {"); // Imprime uma mensagem indicando que o array será exibido.
    for (int i = 0; i < tamanho; ++i) { // Itera sobre os elementos do array.
        printf("%d", array_teste[i]); // Imprime o elemento atual do array.
        if (i < tamanho - 1) { // Verifica se não é o último elemento do array.
            printf(", "); // Se não for o último elemento, imprime uma vírgula e um espaço.
        }
    }
    printf("}\n"); // Imprime um fechamento de chaves para indicar o fim do array.

    printf("Média: %.2f\n", media_array_recursiva(array_teste, tamanho)); // Imprime a média dos elementos do array de teste.

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}
