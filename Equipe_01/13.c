#include <stdio.h>
#include <math.h>

double valorMedioG(double x[], int n) {
    double soma = 0.0;

    for (int i = 0; i < n; i++)
        soma += x[i];

    double media = soma / n;

    return media;
}

double desvioPadraoG(double x[], int n) {
    double media = valorMedioG(x, n);
    double somadosquad = 0.0;

    for (int i = 0; i < n; i++)
        somadosquad += pow(x[i] - media, 2);

    double var = somadosquad / n;
    double desvioPadrao = sqrt(var);

    return desvioPadrao;
}

int main(void) {
    double valores[] = {2.5, 4.5, 6.5, 8.5, 10.5};
    int N = sizeof(valores) / sizeof(valores[0]);

    double desvio = desvioPadraoG(valores, N);

    printf("Desvio Padrão: %.2f\n", desvio);

    return 0;
}
