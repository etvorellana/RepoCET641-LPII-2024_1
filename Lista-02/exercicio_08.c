/*
    Crie uma função que recebe um array bidimensional com 
    valores inteiros entre 0 e 255, dois inteiros, passados 
    por referência, contendo o número de linhas e colunas do 
    array,  
    (int maxValue(int img[ ][ ], int *lin, int *col), 
    e retorna qual o valor máximo do array e qual a primeira 
    posição em que ele aparece quando a matriz é percorrida em 
    ordem crescente do número de linhas e colunas. A posição, 
    qual a linha e a coluna do valor máximo na matriz, deve ser 
    retornada nos parâmetros lin e col. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista-02.h"


int main(void)
{
    

    int img[480][640];
    int i=480, j=640;
    randomImg(img, 480, 640);
    printf("O valor máximo da matriz é %d\n", maxValue(img, &i, &j));
    printf("O valor máximo da matriz está na linha %d e coluna %d\n", i, j);
    printf("img[%d][%d] = %d\n", i, j, img[i][j]);
    /* Exercício proposto:
        Como posso verificar se o resultado está coreto?
        Proponha uma forma de implementar esta verificação 
    */

    return 0;
}
    maxValue(    img,              &i,       &j
int maxValue(int img[ ][640], int *lin, int *col)
{
    int max = img[0][0];
    int iMax, jMax;
    iMax = jMax = 0;
    for(int i = 0; i < *lin; i++)
        for(int j = 0; j < *col; j++)
            if (img[i][j] > max) {
                max = img[i][j];
                iMax = i;
                jMax = j;
            }
    *lin = iMax;
    *col = jMax;
    return max;
}

void randomImg(int imagem[][640], int linhas, int cols)
{
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < cols; j++)
            imagem[i][j] = rand() % 256;
}