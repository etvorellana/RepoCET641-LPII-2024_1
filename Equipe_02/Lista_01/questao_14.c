#include <stdio.h>

#include "lista_01.h"

/* adaptado de q10.c */

int main(void) {
	double arr[4] = {1.0, 1.0, 2.0, 1.0};

	printf("Original: ");
	for (int i = 0; i < 4; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");

	normalizaN(arr, 4);
	printf("Normalizado: ");
	for (int i = 0; i < 4; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");

	printf("Média: %.2lf\n", valorMedioN(arr, 4));

	return 0;
}

void normalizaN(double x_inout[], int n) {
	double vm = valorMedioN(x_inout, n);

	for (int i = 0; i < n; i++)
		x_inout[i] = (x_inout[i] - vm);
}

double valorMedioN(double x[], int n) {
	double soma = 0;
	for (int i = 0; i < n; i++)
		soma += x[i];
	return soma / (double)n;
}
