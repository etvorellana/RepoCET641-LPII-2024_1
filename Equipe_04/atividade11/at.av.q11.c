/*
Em sala de aula analisamos uma versão recursiva para calcular a soma dos elementos de uma array. Faça uma versão recursiva da função que implementa o cálculo da média dos elementos de um array. Implemente uma aplicação que demonstra a aplicação da função.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lista_01.h"

int N = 4;

double soma_recursiva(double vetor[], int tamanho);
double calculo_media(double vetor[], int tamanho);

int main(void)
{
	double vetor[] = {2.2, 3.3, 4.2, 2.3};
	double media = calculo_media(vetor, N);
	printf("A media eh: %2.f", media);
}

double soma_recursiva(double vetor[], int tamanho)
{
	if (tamanho == 0)
	{
		return 0;
	}
	else
	{
		return vetor[tamanho - 1] + soma_recursiva(vetor, tamanho - 1);
	}
}

double calculo_media(double vetor[], int tamanho)
{
	if (tamanho == 0)
	{
		return 0;
	}
	else
	{
		double soma = soma_recursiva(vetor, tamanho);
		return soma / tamanho;
	}
}