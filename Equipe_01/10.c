#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAMANHO_ARRAY 5

int N;

// Função para calcular o valor médio de um array
double valorMedioG(double x[]) {
    double soma = 0.0;

    // Percorre todos os valores na array e os soma
    for (int i = 0; i < N; i++)
        soma += x[i];

    // Calcula a média
    double media = soma / N;

    return media;
}

// Função para normalizar os valores de um array para que tenham média zero
void normaliza(double x_inout[]) {
    double media = valorMedioG(x_inout); // Calcula a média dos valores do array
    for (int i = 0; i < N; i++) {
        x_inout[i] -= media; // Subtrai a média de cada elemento do array
    }
}

int main() {
    double array[TAMANHO_ARRAY];
    srand(time(NULL));

    // Preenche o array com valores aleatórios entre 0 e 4
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        array[i] = rand() % 5;
    }

    N = TAMANHO_ARRAY; // Define o tamanho do array na variável global

    printf("Valores aleatórios:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.1f ", array[i]);
    }
    printf("\n");

    // Normaliza o array para ter média zero
    normaliza(array);

    printf("Valores normalizados (média zero):\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}
