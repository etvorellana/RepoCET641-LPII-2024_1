#include <stdio.h>

#include "lista_01.h"

/* adaptado de q08.c */

int main(void) {
	double arr[4] = {1.0, 1.0, 2.0, 1.0};
	printf("Valor médio: %.2lf\n", valorMedioN(arr, 4));

	return 0;
}

double valorMedioN(double x[], int n) {
	double soma = 0;
	for (int i = 0; i < n; i++)
		soma += x[i];
	return soma / (double)n;
}
