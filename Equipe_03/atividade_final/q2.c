#include <stdio.h>    
#include <stdlib.h>
#include <time.h>     

double *alocaMatriz1d(const int n, const int m);
void dgemm1d(const int n, const int m, const int l, double alpha, double *A, double *B, double beta, double *C);

int main(void) {
    int La, Ca, Lb, Cb, Lc, Cc;  // Variáveis para as dimensões das matrizes
    double alfa, beta;           // Variáveis para os fatores de escala
    double *matA, *matB, *matC;  // Ponteiros para as matrizes
    FILE *file = fopen("gemmMatrixEq3.bin", "rb");  // Abre o arquivo binário para leitura
    if (file == NULL) {  // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê o valor de alfa do arquivo
    fread(&alfa, sizeof(double), 1, file);
    // Lê as dimensões da matriz A
    fread(&La, sizeof(int), 1, file);
    fread(&Ca, sizeof(int), 1, file);

    // Aloca memória para a matriz A
    matA = alocaMatriz1d(La, Ca);
    // Lê os elementos da matriz A do arquivo
    fread(matA, sizeof(double), La * Ca, file);

    // Lê as dimensões da matriz B
    fread(&Lb, sizeof(int), 1, file);
    fread(&Cb, sizeof(int), 1, file);

    // Aloca memória para a matriz B
    matB = alocaMatriz1d(Lb, Cb);
    // Lê os elementos da matriz B do arquivo
    fread(matB, sizeof(double), Lb * Cb, file);

    // Lê o valor de beta do arquivo
    fread(&beta, sizeof(double), 1, file);
    // Lê as dimensões da matriz C
    fread(&Lc, sizeof(int), 1, file);
    fread(&Cc, sizeof(int), 1, file);

    // Aloca memória para a matriz C
    matC = alocaMatriz1d(Lc, Cc);
    // Lê os elementos da matriz C do arquivo
    fread(matC, sizeof(double), Lc * Cc, file);

    // Fecha o arquivo
    fclose(file);

    // Medir o tempo de execução
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();  // Inicia a contagem do tempo

    // Chama a rotina dgemm1d para multiplicação de matrizes
    dgemm1d(La, Ca, Cb, alfa, matA, matB, beta, matC);

    end_t = clock();  // Finaliza a contagem do tempo
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t);  // Imprime o tempo de execução

    // Determina os valores específicos da matriz C conforme requerido
    double C_0_m_8 = matC[0 * Cc + (Cc - 8)];
    double C_0_m_1 = matC[0 * Cc + (Cc - 1)];
    double C_7_m_8 = matC[7 * Cc + (Cc - 8)];
    double C_7_m_1 = matC[7 * Cc + (Cc - 1)];

    // Determina o maior valor da primeira linha da matriz C
    double maior_valor_linha = matC[0];
    for (int j = 1; j < Cc; j++) {
        if (matC[0 * Cc + j] > maior_valor_linha) {
            maior_valor_linha = matC[0 * Cc + j];
        }
    }

    // Abre o arquivo de saída para escrita
    FILE *arquivo_saida = fopen("saida.log", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    // Escreve os resultados no arquivo de saída
    fprintf(arquivo_saida, "C[0][m-8] = %f\n", C_0_m_8);
    fprintf(arquivo_saida, "C[0][m-1] = %f\n", C_0_m_1);
    fprintf(arquivo_saida, "C[7][m-8] = %f\n", C_7_m_8);
    fprintf(arquivo_saida, "C[7][m-1] = %f\n", C_7_m_1);
    fprintf(arquivo_saida, "Maior valor da primeira linha: %f\n", maior_valor_linha);

    // Fecha o arquivo de saída
    fclose(arquivo_saida);

    // Libera a memória alocada para as matrizes
    free(matA);
    free(matB);
    free(matC);

    return 0;
}

// Função para alocar uma matriz 1D de dimensão n x m
double *alocaMatriz1d(const int n, const int m) {
    double *mat = (double *)malloc(n * m * sizeof(double));  // Aloca memória para a matriz
    if (mat == NULL) {  // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a matriz\n");
        exit(1);  // Encerra o programa em caso de erro
    }
    return mat;  // Retorna o ponteiro para a matriz alocada
}

// Função para realizar a multiplicação de matrizes sem usar BLAS
void dgemm1d(const int n, const int m, const int l, double alpha, double *A, double *B, double beta, double *C) {
    int i, j, k;

    // Primeiro, multiplica cada elemento de C por beta
    for (i = 0; i < n; i++) {
        for (j = 0; j < l; j++) {
            C[i * l + j] *= beta;
        }
    }

    // Em seguida, realiza a multiplicação das matrizes A e B, multiplicando o resultado por alpha e adicionando a C
    for (i = 0; i < n; i++) {
        for (k = 0; k < m; k++) {
            double temp = alpha * A[i * m + k];
            for (j = 0; j < l; j++) {
                C[i * l + j] += temp * B[k * l + j];
            }
        }
    }
}