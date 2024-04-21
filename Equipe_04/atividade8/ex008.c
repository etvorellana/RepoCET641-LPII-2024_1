#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../lista_01.h"

int N = 10;

double valorMedioG(double x[ ]) {
    double soma = 0.0;

    for (int i = 0; i < N; i++) {
        soma += x[i];
    }

    double valorMedio = soma / (double) N;
    return valorMedio;
}

int main() {
    double x0[N];
    srand(time(0));

    for (int i = 0; i < N; i++) {
        x0[i] = (double) rand() / RAND_MAX;
        printf("%f, ", x0[i]);
    }
    printf("\n");

    printf("O valor médio é: %f\n", valorMedioG(x0));
}