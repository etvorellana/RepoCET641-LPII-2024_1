/*
Implemente uma função para normalizar um conjunto de valores armazenados em um array de tipo double, para que eles passem a ter média zero. O cabeçalho da função deve ser:
    void normaliza(double x_inout[ ]);
A quantidade de elementos no array é armazenada na variável global, N, declarada como sendo de tipo int. Esta função deve utilizar, internamente, a função definida no exercício anterior (8) para calcular o valor médio. Implemente uma aplicação que demonstra a aplicação da função.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lista_01.h"

int N = 10;

void preencherLR(double x[], int n);
double valorMedioG(double x[]);
void normaliza(double x_inout[]);

int main()
{
    double Arr[N];

    printf("\nArray:");
    preencherLR(Arr, N);
    double media = valorMedioG(Arr);
    printf("\nO valor medio do Array = %f", media);

    printf("\n\nArray Normalizado:");
    normaliza(Arr);
}

void preencherLR(double x[], int n)
{
    if (n == 0)
        return;
    x[0] = (double)rand() / RAND_MAX * 100.0;
    printf("  %f", x[0]);
    preencherLR(&x[1], n - 1);
}

double valorMedioG(double x[])
{
    double soma = 0.0;

    for (int i = 0; i < N; i++)
    {
        soma += x[i];
    }

    double valorMedio = soma / (double)N;
    return valorMedio;
}

void normaliza(double x_inout[])
{
    double media = valorMedioG(x_inout);
    for (int i = 0; i < N; i++)
    {
        x_inout[i] = x_inout[i] - media;
        printf("  %f", x_inout[i]);
    }
    double mediaNormal = valorMedioG(x_inout);
    printf("\nO valor medio do Array Normalizada = %f\n\n", mediaNormal);
}