/*
Modifique a função do Exercício 8 para que, agora, receba o tamanho do array como um parâmetro passado por valor. A nova função deve ter o seguinte cabeçalho:
    double valorMedio(double x[ ], int n);
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../lista_01.h"


double valorMedio(double x[], int n);

int main()
{

    int n;

    printf("\nEscolha o tamanho do Array: ");
    scanf("%i", &n);

    double x0[n];
    srand(time(0));

    printf("\nArray:");
    for (int i = 0; i < n; i++)
    {
        x0[i] = (double)rand() / RAND_MAX * 100;
        printf("  %f", x0[i]);
    }

    printf("\n\nO valor medio do Array: %f\n", valorMedio(x0, n));
}

double valorMedio(double x[], int n)
{
    double soma = 0.0;

    for (int i = 0; i < n; i++)
    {
        soma += x[i];
    }

    double valorMedio = soma / n;
    return valorMedio;
}