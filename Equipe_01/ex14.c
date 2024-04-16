#include <stdio.h>
#include <math.h>
#include "Biblioteca/lista_01.h"

int main() {
    double array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Valores originais:\n");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", array[i]);
    }
    printf("\n");

    // Normaliza o array para ter média zero
    normaliza1(array, n);

    printf("Valores normalizados (média zero):\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}

