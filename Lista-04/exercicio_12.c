/*
    Exercício 12
    Crie uma função para liberar o espaço de memória ocupado por uma imagem 
    matriz de inteiros. A função recebe um ponteiro de ponteiros para 
    inteiros, contendo valores entre 0 e 255, dois inteiros contendo o 
    número de linhas e colunas do array 
    (void liberaImagem(int** img, int lin, int col)).Implemente uma aplicação 
    que:
    a. Gere uma imagem de 640 x 480 pixels preenchidos de forma aleatória e 
    mostre os 25 pixels do canto superior esquerdo (a submatriz de 5x5 do 
    campo superior esquerdo).
    b. Libere a memória alocada para a imagem;

*/

#include <stdio.h>
#include <stdlib.h>

int** geraImagem(int lin, int col);
void liberaImagem(int** img, int lin, int col);


int main(void)
{
    int lin = 640, col = 480;
    int** imagem;
    imagem = geraImagem(lin, col);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", imagem[i][j]);
        }
        printf("\n");
    }
    liberaImagem(imagem, lin, col);
    return 0;
}

int** geraImagem(int lin, int col)
{
    int** imagem = (int**) malloc(lin * sizeof(int*));
    for(int i = 0; i < lin; i++)
    {
        imagem[i] = (int*) malloc(col * sizeof(int));
        for(int j = 0; j < col; j++)
        {
            imagem[i][j] = rand() % 256;
        }
    }
    return imagem;
}

void liberaImagem(int** img, int lin, int col)
{
    for(int i = 0; i < lin; i++)
    {
        free(img[i]);
    }
    free(img);
}