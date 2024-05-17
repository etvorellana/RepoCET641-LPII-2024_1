#include <stdio.h>

#define N 595

//void gemm(int m, int n, int k, double alpha, 
//            double **A, double **B, double beta, double **C);

void gemm(int m, int n, int k, double alpha, double A[N][N], double B[N][N], double beta, double C[N][N]);

int main(void)
{
    double matA[N][N];
    double matB[N][N];
    double matC[N][N];

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

    return 0;
}

void gemm(int m, int n, int k, double alpha, double A[N][N], double B[N][N], double beta, double C[N][N])
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