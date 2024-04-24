/*
Modifique a função do Exercício 10 para que, agora, receba o tamanho do array como um parâmetro passado por valor. A nova função deve ter o seguinte cabeçalho:
	void normaliza(double x_inout[ ], int n);
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lista_01.h"


void preencherLR(double x[], int n);
double valorMedioG(double x[], int n);
void normaliza(double x_inout[], int n);

int main()
{
	int n;

	printf("\nEscolha o tamanho do Array: ");
	scanf("%i", &n);

	double Arr[n];

	printf("\nArray:");
	preencherLR(Arr, n);
	double media = valorMedioG(Arr, n);
	printf("\nO valor medio do Array = %f", media);

	printf("\n\nArray Normalizado:");
	normaliza(Arr, n);
}

void preencherLR(double x[], int n)
{
	if (n == 0)
		return;
	x[0] = (double)rand() / RAND_MAX * 100.0;
	printf("  %f", x[0]);
	preencherLR(&x[1], n - 1);
}

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

void normaliza(double x_inout[], int n)
{
	double media = valorMedioG(x_inout, n);
	for (int i = 0; i < n; i++)
	{
		x_inout[i] = x_inout[i] - media;
		printf("  %f", x_inout[i]);
	}
	double mediaNormal = valorMedioG(x_inout, n);
	printf("\nO valor medio do Array Normalizada = %f\n\n", mediaNormal);
}