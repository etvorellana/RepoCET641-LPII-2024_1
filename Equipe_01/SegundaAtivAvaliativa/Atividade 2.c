#include <stdio.h>
#include <stdlib.h>

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
    int n, m, l;
    double alpha, beta;
    double *matA, *matB, *matC;

    FILE *arquivo = fopen("gemmMatrixEq1.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

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

    dgemm1d(n, m, l, alpha, matA, matB, beta, matC);

    FILE *saida = fopen("saida.log", "w");
    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    fprintf(saida, "Equipe 1:\n");
    fprintf(saida, "C[0][0] = %.2f\n", matC[0]);
    fprintf(saida, "C[0][l-1] = %.2f\n", matC[l - 1]);
    fprintf(saida, "C[n-1][0] = %.2f\n", matC[(n - 1) * l]);
    fprintf(saida, "C[n-1][l-1] = %.2f\n", matC[(n - 1) * l + (l - 1)]);

    double maiorValor = matC[0];
    for (int i = 0; i < n * l; ++i) {
        if (matC[i] > maiorValor) {
            maiorValor = matC[i];
        }
    }
    fprintf(saida, "O maior valor da matriz C = %.2f\n", maiorValor);

    fclose(saida);

    free(matA);
    free(matB);
    free(matC);

    return 0;
}