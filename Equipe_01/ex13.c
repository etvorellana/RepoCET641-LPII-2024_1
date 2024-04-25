#include <stdio.h>
#include <math.h>
#include "Biblioteca/lista_01.h"

int main(void) {
    double valores[] = {2.5, 4.5, 6.5, 8.5, 10.5};
    int N = sizeof(valores) / sizeof(valores[0]);

    double desvio = desvioPadraoG1(valores, N);

    printf("Desvio Padrão: %.2f\n", desvio);

    return 0;
}
