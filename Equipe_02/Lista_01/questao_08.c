#include <stdio.h>

#include "lista_01.h"

int N = 4;

int main(void) {
	double arr[] = {1.0, 1.0, 2.0, 1.0};
	printf("Valor médio: %.2lf\n", valorMedio(arr));

	return 0;
}

double valorMedio(double x[]) {
	double soma = 0;
	for (int i = 0; i < N; i++)
		soma += x[i];
	return soma / (double)N;
}
