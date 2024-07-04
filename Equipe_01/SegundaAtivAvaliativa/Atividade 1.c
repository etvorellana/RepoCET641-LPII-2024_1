#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *alocaMatriz1d(const int n, const int m) {

    double *mat = (double *)malloc(n * m * sizeof(double));
    return mat;
}

void dgemm1d(const int nAC, const int mAB, const int lBC, double alpha,
             double *A, double *B, double beta, double *C) {

    for (int i = 0; i < nAC; ++i) {
        for (int j = 0; j < lBC; ++j) {
            double temp = 0.0;
            for (int k = 0; k < mAB; ++k) {
                temp += A[i * mAB + k] * B[k * lBC + j];
            }
            C[i * lBC + j] = alpha * temp + beta * C[i * lBC + j];
        }
    }
}


int main(void) {
    int n,m,l;
    double alpha, beta;
    double *matA, *matB, *matC;
    clock_t start_t, end_t;
    double total_t;

    FILE *arquivo = fopen("gemmMatrixBench.bin", "rb");

    fread(&alpha, sizeof(double), 1, arquivo);

    fread(&n, sizeof(int), 1, arquivo);
    fread(&m, sizeof(int), 1, arquivo);

    matA = alocaMatriz1d(n, m);
    fread(matA, sizeof(double), n * m, arquivo);

    fread(&m, sizeof(int), 1, arquivo);
    fread(&l, sizeof(int), 1, arquivo);

    matB = alocaMatriz1d(m, l);
    fread(matB, sizeof(double), m * l, arquivo);

    fread(&beta, sizeof(double), 1, arquivo);

    fread(&n, sizeof(int), 1, arquivo);
    fread(&l, sizeof(int), 1, arquivo);
 
    matC = alocaMatriz1d(n, l);
    fread(matC, sizeof(double), n * l, arquivo);

    fclose(arquivo);

    start_t = clock();
    dgemm1d(n, m, l, alpha, matA, matB, beta, matC);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo total de execução: %f segundos.\n", total_t);

    int todosIguais = 1; 
      for (int i = 0; i < n * l; ++i) {
          if (matC[i] != 2049.0) {
              todosIguais = 0; 
              break;
          }
      }
    if (todosIguais) {
      printf("Todos os elementos da matriz C são iguais a 2049.\n");
    } else {
      printf("A matriz C não contém todos os elementos iguais a 2049.\n");
    }

    free(matA);
    free(matB);
    free(matC);

    return 0;
}