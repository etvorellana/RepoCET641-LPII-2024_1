#include <stdio.h>
#include <stdlib.h>
int** alocaMatriz(int m, int n); // m linhas e n colunas
void desalocaMatriz(int **x, int m);
void matrizAleotorio(int **x, int m, int n);
int main(void){
    int **A;
    A = alocaMatriz(10, 10);
    matrizAleotorio(A, 10, 10);
    for(int i = 0; i < 10; i++){   
        for(int j = 0; j < 10; j++){
            printf("A[%d][%d] = %d ", i, j, A[i][j]);
        }
        printf("\n");
    }
    desalocaMatriz(A, 10);
    return 0;
}

int** alocaMatriz(int m, int n) // m linhas e n colunas
{
    int **x;
    x = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        x[i] = (int *)malloc(n * sizeof(int));
    }
    return x;


}
void desalocaMatriz(int **x, int m)
{
    for(int i = 0; i < m; i++){
        free(x[i]);
    }
    free(x);

}
void matrizAleotorio(int **x, int m, int n)
{

}