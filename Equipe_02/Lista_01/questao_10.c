#include <stdio.h>

#include "lista_01.h"

int N = 4;

int main(void) {
	double arr[] = {1.0, 1.0, 2.0, 1.0};

	printf("Original: ");
	for (int i = 0; i < N; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");

	normaliza(arr);
	printf("Normalizado: ");
	for (int i = 0; i < N; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");

	printf("Média: %.2lf\n", valorMedio(arr));

	return 0;
}

void normaliza(double x_inout[]) {
	double vm = valorMedio(x_inout);

	for (int i = 0; i < N; i++)
		x_inout[i] = (x_inout[i] - vm);
}

double valorMedio(double x[]) {
	double soma = 0;
	for (int i = 0; i < N; i++)
		soma += x[i];
	return soma / (double)N;
}
