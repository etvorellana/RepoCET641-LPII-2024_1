#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>

double *alocaMatriz1d(const int n, const int m);
void dgemm1d(const int nAC, const int mAB, const int lBC, double alpha, double *A, double *B, double beta, double *C);

int main(void) {
    int La, Ca, Lb, Cb, Lc, Cc, i, j;
    double alfa, beta;
    double *matA, *matB, *matC;
    FILE *file = fopen("gemmMatrixBench.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    fread(&alfa, sizeof(double), 1, file);
    fread(&La, sizeof(int), 1, file);
    fread(&Ca, sizeof(int), 1, file);

    matA = alocaMatriz1d(La, Ca);
    fread(matA, sizeof(double), La * Ca, file);

    fread(&Lb, sizeof(int), 1, file);
    fread(&Cb, sizeof(int), 1, file);

    matB = alocaMatriz1d(Lb, Cb);
    fread(matB, sizeof(double), Lb * Cb, file);

    fread(&beta, sizeof(double), 1, file);
    fread(&Lc, sizeof(int), 1, file);
    fread(&Cc, sizeof(int), 1, file);

    matC = alocaMatriz1d(Lc, Cc);
    fread(matC, sizeof(double), Lc * Cc, file);

    fclose(file);

    // para quantificar o tempo de execução
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();

    // chamando a rotina dgemm1d
    dgemm1d(La, Ca, Cb, alfa, matA, matB, beta, matC);

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);

    // Verifica se todos os elementos da matriz resultante são iguais a 2049
    int resultadoCorreto = 1;
    for (i = 0; i < Lc; i++) {
        for (j = 0; j < Cc; j++) {
            if (matC[i * Cc + j] != 2049.0) {
                resultadoCorreto = 0;
                break;
            }
        }
        if (!resultadoCorreto) break;
    }

    if (resultadoCorreto) {
        printf("Todos os elementos da matriz resultante são iguais a 2049.\n");
    } else {
        printf("A matriz resultante não está correta.\n");
    }

    // liberando a memória alocada
    free(matA);
    free(matB);
    free(matC);

    return 0;
}

double *alocaMatriz1d(const int n, const int m) {
    double *mat = (double *)malloc(n * m * sizeof(double));
    if (mat == NULL) {
        printf("Erro ao alocar memória para a matriz\n");
        exit(1);
    }
    return mat;
}

void dgemm1d(const int n, const int m, const int l, double alpha, double *A, double *B, double beta, double *C) {
    // Usando a função cblas_dgemm para realizar a multiplicação de matrizes
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, l, m, alpha, A, m, B, l, beta, C, l);
}