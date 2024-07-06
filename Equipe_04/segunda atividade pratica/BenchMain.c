//----------------------------------------------------------------------------//
// Notes//

// Ao Compilar, usar o comando abaixo no terminal:
// gcc -fopenmp BenchMain.c
// Abrir o executável gerado na mesma pasta
// O arquivo gemmMatrixBench.bin deve estar na mesma página do executável

//----------------------------------------------------------------------------//
// Librays//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

//----------------------------------------------------------------------------//
// Functions//

double *alocaMatriz1d(int nl, int nc);
void dgemm1d(int m, int n, int k, double alpha, double *matA, double *matB, double beta, double *matC);
void printMatriz(const char *desc, int m, int n, double *mat);

//----------------------------------------------------------------------------//
// Main//

int main(void)
{

    FILE *fp = fopen("gemmMatrixBench.bin", "rb");

    if (fp == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    double alpha, beta;
    int nla, nlb, nlc, nca, ncb, ncc;
    double *matA, *matB, *matC;

    // Alpha
    fread(&alpha, sizeof(double), 1, fp);
    printf("\nAlpha: %.1lf\n\n", alpha);

    // Matrix A
    fread(&nla, sizeof(int), 1, fp);
    fread(&nca, sizeof(int), 1, fp);
    printf("Dimensions Matriz A : %d x %d\n", nla, nca);

    matA = alocaMatriz1d(nla, nca);
    fread(matA, sizeof(double), nla * nca, fp);

    // Matrix B
    fread(&nlb, sizeof(int), 1, fp);
    fread(&ncb, sizeof(int), 1, fp);
    printf("Dimensions Matriz B : %d x %d\n\n", nlb, ncb);

    matB = alocaMatriz1d(nlb, ncb);
    fread(matB, sizeof(double), nlb * ncb, fp);

    // Beta
    fread(&beta, sizeof(double), 1, fp);
    printf("Beta: %.1lf\n\n", beta);

    // Matrix C
    fread(&nlc, sizeof(int), 1, fp);
    fread(&ncc, sizeof(int), 1, fp);
    printf("Dimensions Matriz C : %d x %d\n\n", nlc, ncc);

    matC = alocaMatriz1d(nlc, ncc);
    fread(matC, sizeof(double), nlc * ncc, fp);

    // Teste
    clock_t start_t,
        end_t;
    double total_t;
    start_t = clock();

    dgemm1d(nla, ncb, nlc, alpha, matA, matB, beta, matC);

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n\n", total_t);

    system("pause");

    printMatriz("Matriz Resultante C:", nlc, ncc, matC);

    system("pause");

    fclose(fp);

    free(matA);
    free(matB);
    free(matC);
    return 0;
}

//----------------------------------------------------------------------------//
// Declared Functions//

double *alocaMatriz1d(const int n, const int m)
{
    double *mat;
    mat = (double *)malloc(n * m * sizeof(double));
    return mat;
}

void dgemm1d(int m, int n, int k, double alpha, double *matA, double *matB, double beta, double *matC)
{
    int blockSize = 64;

#pragma omp parallel for
    for (int ii = 0; ii < m; ii += blockSize)
    {
        for (int jj = 0; jj < n; jj += blockSize)
        {
            for (int kk = 0; kk < k; kk += blockSize)
            {
                for (int i = ii; i < ii + blockSize && i < m; i++)
                {
                    for (int j = jj; j < jj + blockSize && j < n; j++)
                    {
                        if (kk == 0)
                        {
                            matC[i * n + j] *= beta;
                        }

                        double cij = 0.0;
                        for (int p = kk; p < kk + blockSize && p < k; p++)
                        {
                            cij += matA[i * k + p] * matB[p * n + j];
                        }

                        matC[i * n + j] += alpha * cij;
                    }
                }
            }
        }
    }
}

void printMatriz(const char *desc, int m, int n, double *mat)
{
    printf("\n%s \n", desc);
    m = 10;
    n = 10;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %.2f", mat[i * n + j]);
        }
        printf("\n\n");
    }
}