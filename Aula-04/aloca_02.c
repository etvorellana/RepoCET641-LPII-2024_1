#include <stdio.h>
#include <stdlib.h>

#define N 2048

void gemm(int m, int n, int k, double alpha, 
            double **A, double **B, double beta, double **C);



int main(void)
{
    double **matA, **matB, **matC;
    double *x;

    x = (double *) malloc(N * sizeof(double));

    matA = (double **) malloc(N * sizeof(double *));
    matB = (double **) malloc(N * sizeof(double *));
    matC = (double **) malloc(N * sizeof(double *));
    for(int i = 0; i < N; i++)
    {
        matA[i] = (double *) malloc(N * sizeof(double));
        matB[i] = (double *) malloc(N * sizeof(double));
        matC[i] = (double *) malloc(N * sizeof(double));
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matA[i][j] = 1.0;
            matB[i][j] = 0.5;
            matC[i][j] = 0.0;
        }
    }

    double alpha = 1.0;
    double beta = 0.0;

    gemm(N, N, N, alpha, matA, matB, beta, matC);

    printf("matC[0][0] = %f\n", matC[0][0]);
    printf("matC[0][N-1] = %f\n", matC[0][N-1]);
    printf("matC[N-1][0] = %f\n", matC[N-1][0]);
    printf("matC[N-1][N-1] = %f\n", matC[N-1][N-1]);

    free(x);
    for(int i = 0; i < N; i++)
    {
        free(matA[i]);
        free(matB[i]);
        free(matC[i]);
    }
    free(matA);
    free(matB);
    free(matC);

    return 0;
}

void gemm(int m, int n, int k, double alpha, 
            double **A, double **B, double beta, double **C)
{
    int i, j, l;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            double soma = 0;
            for (l = 0; l < k; l++)
            {
                soma += A[i][l] * B[l][j];
            }
            C[i][j] = alpha * soma + beta * C[i][j];
        }
    }
    
}