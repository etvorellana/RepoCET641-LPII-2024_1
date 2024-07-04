#include "common.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

double *alocaMatriz1d(const int n, const int m)
{
  double *mat = malloc(n * m * sizeof(double));
  if (mat == NULL) {
    printf("Falha ao alocar memória!\n");
    exit(1);
  }
  return mat;
}

void dgemm1d(const int n, const int m, const int l, double alpha,
  double *A, double *B, double beta, double *C)
{
  // algoritmo lento :pray:

  // gemm -> C = alpha * A * B + beta * C (A: n x m, B: m x l, C: n x l)

  for (int lin = 0; lin < n; lin++) {
    for (int col = 0; col < l; col++) {
      // dot product da linha de A com a coluna de B
      double sum = 0.0;
      for (int i = 0; i < m; i++) {
        sum += A[lin*m + i] * B[i*l + col];
      }
      sum *= alpha; // multiplicando por alpha (distributiva)

      C[lin*l + col] = C[lin*l + col] * beta + sum;
    }
  }
}

void lerMatrizBin1d(const char *path, int *n, int *m, int *l, double *alpha,
  double *beta, double **A, double **B, double **C)
{
  FILE *fd = fopen(path, "rb");
  int temp;

  fread(alpha, sizeof(double), 1, fd); // (double) alpha
  fread(n, sizeof(int), 1, fd); // (int) número de linhas da matriz A
  fread(m, sizeof(int), 1, fd); // (int) número de colunas da matriz A

  // todos os valores (double) da matriz A, linha por linha
  *A = alocaMatriz1d(*n, *m); // A: n x m
  fread(*A, sizeof(double), (*n)*(*m), fd);

  fread(&temp, sizeof(int), 1, fd); // (int) número de linhas da matriz B;
  if (temp != *m) exit(2);

  fread(l, sizeof(int), 1, fd); // (int) número de colunas da matriz B;

  // todos os valores (double) da matriz B, linha por linha
  *B = alocaMatriz1d(*m, *l); // B: m x l
  fread(*B, sizeof(double), (*m)*(*l), fd);

  fread(beta, sizeof(double), 1, fd); // (double) beta

  fread(&temp, sizeof(int), 1, fd); // (int) número de linhas da matriz C;
  if (temp != *n) exit(2);

  fread(&temp, sizeof(int), 1, fd); // (int) número de colunas da matriz C;
  if (temp != *l) exit(2);

  // todos os valores (double) da matriz C, linha por linha
  *C = alocaMatriz1d(*n, *l); // B: n x l
  fread(*C, sizeof(double), (*n)*(*l), fd);

  fclose(fd);
}
