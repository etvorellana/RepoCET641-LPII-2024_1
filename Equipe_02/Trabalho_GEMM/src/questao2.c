#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#include "common.h"

/**
 * Escreve os resultados especificados em um arquivo de texto, tendo em base a
 * matriz C: n x m
 */
void escreverResultados(const char *nomeArquivo, double *C, int n, int m);

int main(void)
{
  int n, m, l;
  double alpha, beta;
  double *matA, *matB, *matC;
  lerMatrizBin1d("gemmMatrixEq2.bin", &n, &m, &l, &alpha,
    &beta, &matA, &matB, &matC);

	// para quantificar o tempo de execução
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();
	dgemm1d(n, m, l, alpha, matA, matB, beta, matC);
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %f\n", total_t);

	// Escrever os resultados especificados no arquivo saida.log
	escreverResultados("saida.log", matC, n, l);

	free(matC);
	free(matB);
	free(matA);

	return 0;
}

void escreverResultados(const char *nomeArquivo, double *C, int n, int m)
{
	FILE *fd_w = fopen(nomeArquivo, "w");

	int coords[4][2] = {
		{0, 0},
		{0, 7},
		{7, 0},
		{7, 7},
	};

	for (int i = 0; i < 4; i++) {
		int y = coords[i][0], x = coords[i][1];
		fprintf(fd_w, "C[%d][%d] = %f\n", y, x, C[y * m + x]);
	}

	double menor_valor = DBL_MAX;
	int linha_menor = 0, coluna_menor = 0;

	// Encontrar C[0][0], C[0][7], C[7][0], C[7][7] e o menor valor
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (C[i * m + j] < menor_valor) {
				menor_valor = C[i * m + j];
				linha_menor = i;
				coluna_menor = j;
			}
		}
	}

	fprintf(fd_w, "Menor valor da matriz C é C[%d][%d]: %f\n", linha_menor, coluna_menor, menor_valor);

	fclose(fd_w);
}
