// vim: sw=2 et

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

int main(void)
{
  int n, m, l;
  double alpha, beta;
  double *matA, *matB, *matC;
  lerMatrizBin1d("gemmMatrixBench.bin", &n, &m, &l, &alpha,
    &beta, &matA, &matB, &matC);

  // para quantificar o tempo de execução
  clock_t start_t, end_t;
  double total_t;
  start_t = clock();
  dgemm1d(n, m, n, alpha, matA, matB, beta, matC);
  end_t = clock();
  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Total time taken by CPU: %f\n", total_t);

  // escrever matriz resultante num arquivo para inspecção
  FILE *fd_w = fopen("benchMatrix.log", "w");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      fprintf(fd_w, "%.2lf ", matC[i * l + j]);
    }
    fprintf(fd_w, "\n");
  }
  fclose(fd_w);

  free(matC);
  free(matB);
  free(matA);

  return 0;
}
