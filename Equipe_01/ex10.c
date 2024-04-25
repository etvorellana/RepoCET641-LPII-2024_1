#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Biblioteca/lista_01.h"

#define TAMANHO_ARRAY 5

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
