#include <stdio.h>
#include <stdlib.h>
/* guarde internamente como um array unidimensional e 
retorne um ponteiro de ponteiros*/
int** alocaMatriz(int m, int n); // m linhas e n colunas
void desalocaMatriz(int **x);
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

