/*
Implemente uma função para calcular o desvio padrão de um conjunto de valores armazenados em um array de valores de tipo double. O cabeçalho da função deve ser:
    double desvioPadraoG(double x[ ]);
A quantidade de elementos no array é armazenada na variável global, N, declarada como sendo de tipo int. Esta função deve utilizar, internamente, a função definida no exercício anterior para calcular o valor médio. Implemente uma aplicação que demonstra a aplicação da função.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lista_01.h"

int N = 5;

void preencherLR(double lista[], int n);
double valorMedioG(double x[]);
double desvioPadraoG(double x[]);

int main()
{

    double Arr[N];

    printf("\nArray:");
    preencherLR(Arr, N);

    double DesvioP = desvioPadraoG(Arr);
    printf("\n\nO desvio padrao do Array = %f\n\n", DesvioP);
}

void preencherLR(double lista[], int n)
{
    if (n == 0)
        return;
    lista[0] = (double)rand() / RAND_MAX * 100.0;
    printf("  %f", lista[0]);
    preencherLR(&lista[1], n - 1);
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

double desvioPadraoG(double x[])
{
    double media = valorMedioG(x);
    double dp = 0.0;

    for (int i = 0; i < N; i++)
    {
        dp += pow(x[i] - media, 2);
    }

    dp = sqrt(dp / N);
    return dp;
}