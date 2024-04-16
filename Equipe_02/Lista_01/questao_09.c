#include <stdio.h>
#include <math.h>

#include "lista_01.h"

int N = 4;

int main(void) {
	double arr[] = {1.0, 1.0, 2.0, 1.0};
	printf("Desvio padrão: %.2lf\n", desvioPadraoG(arr));

	return 0;
}

double desvioPadraoG(double x[]) {
	double vm = valorMedio(x);

	double soma = 0;
	for (int i = 0; i < N; i++)
		soma += pow(x[i] - vm, 2);

	return sqrt(soma / (double)N);
}

double valorMedio(double x[]) {
	double soma = 0;
	for (int i = 0; i < N; i++)
		soma += x[i];
	return soma / (double)N;
}
