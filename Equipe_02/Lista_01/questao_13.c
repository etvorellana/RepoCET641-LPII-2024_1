#include <stdio.h>
#include <math.h>

#include "lista_01.h"

/* adaptado de q09.c */

int main(void) {
	double arr[4] = {1.0, 1.0, 2.0, 1.0};
	printf("Desvio padrão: %.2lf\n", desvioPadraoN(arr, 4));

	return 0;
}

double desvioPadraoN(double x[], int n) {
	double vm = valorMedioN(x, n);

	double soma = 0;
	for (int i = 0; i < n; i++)
		soma += pow(x[i] - vm, 2);

	return sqrt(soma / (double)n);
}

double valorMedioN(double x[], int n) {
	double soma = 0;
	for (int i = 0; i < n; i++)
		soma += x[i];
	return soma / (double)n;
}
