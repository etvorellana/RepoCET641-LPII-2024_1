/*
    Crie uma função que recebe um array bidimensional com valores 
    inteiros entre 0 e 255, dois inteiros contendo o número de 
    linhas e colunas do array, e um array de inteiros 
    (void histograma(int img[ ][ ], int lin, int col,int hist[ ])) 
    e retorna, no array de inteiros, quantas vezes aparece na 
    matriz cada uma dos 256 possíveis valores. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista-02.h"



int main() {
    int img[480][640], hist[256] = {0};
    randomImg(img, 480, 640);
    histograma(img, 480, 640, hist);
    for(int i = 0; i < 256; i++)
        printf("O valor %d aparece %d vezes\n", i, hist[i]);

    /* Exercício proposto:
        Como posso verificar que o histograma está coreto?
        Proponha uma função para fazer esta verificação.
    */
    return 0;
}


/*
    Em C, você pode passar um array 2D para uma função de duas maneiras: 
    * passando o array inteiro como argumento: Especificar o tamanho da 
    segunda dimensão, deixando a primeira dimensão sem especificar. 
    * passando o array como um ponteiro dinâmico  Usar um ponteiro dinâmico 
    e é adequado para matrizes 2D alocadas dinamicamente. 
    O segundo método será abordado mais adiante no curso
*/
void randomImg(int imagem[][640], int linhas, int cols)
{
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < cols; j++)
            imagem[i][j] = rand() % 256;
}

void histograma(int img[ ][640], int lin, int col,int hist[ ])
{
    for(int i = 0; i < lin; i++)
        for(int j = 0; j < col; j++)
            if (img[i][j] >= 0 && img[i][j] <= 255)
                hist[img[i][j]]++;           
}