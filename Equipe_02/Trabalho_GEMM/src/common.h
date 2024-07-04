#ifndef _COMMON_H
#define _COMMON_H

/**
 * Aloca uma matriz n x m na forma de um array 1D
 */
double *alocaMatriz1d(const int n, const int m);

/**
 * Realiza a multiplicação GEMM com os parâmetros descritos:
 * A: n x m; B: m x l, C: n x l
 * C <- alpha * A * B + beta * C
 */
void dgemm1d(const int n, const int m, const int l, double alpha,
  double *A, double *B, double beta, double *C);

/**
 * Lê as matrizes do arquivo cujo caminho é `path`, armazenando tudo nos
 * ponteiros descritos.
 */
void lerMatrizBin1d(const char *path, int *n, int *m, int *l, double *alpha,
  double *beta, double **A, double **B, double **C);

#endif
