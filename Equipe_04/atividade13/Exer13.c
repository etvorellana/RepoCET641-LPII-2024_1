/*
Modifique a função do Exercício 9 para que, agora, receba o tamanho do array como um parâmetro passado por valor. A nova função deve ter o seguinte cabeçalho:
	double desvioPadrao(double x[ ], int n);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lista_01.h"


void preencherLR(double lista[], int n);
double valorMedioG(double x[], int n);
double desvioPadraoG(double x[], int n);

int main()
{

	int n;

	printf("\nEscolha o tamanho do Array: ");
	scanf("%i", &n);

	double Arr[n];

	printf("\nArray:");
	preencherLR(Arr, n);

	double DesvioP = desvioPadraoG(Arr, n);
	printf("\n\nO desvio padrao do Array = %f\n\n", DesvioP);
}

void preencherLR(double lista[], int n)
{
	if (n == 0)
		return;
	lista[0] = (double)rand() / RAND_MAX * 100.0;
	printf("  %f", lista[0]);
	preencherLR(&lista[1], n - 1);
};

double valorMedioG(double x[], int n)
{
	double soma = 0.0;

	for (int i = 0; i < n; i++)
	{
		soma += x[i];
	}

	double valorMedio = soma / (double)n;
	return valorMedio;
}

double desvioPadraoG(double x[], int n)
{
	double media = valorMedioG(x, n);
	double dp = 0.0;

	for (int i = 0; i < n; i++)
	{
		dp += pow(x[i] - media, 2);
	}

	dp = sqrt(dp / n);
	return dp;
}