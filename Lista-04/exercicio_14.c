/*
    Exercício 14.
    Crie uma função que recebe um ponteiro de ponteiros para inteiros, contendo valores 
    entre 0 e 255, dois inteiros contendo o número de linhas e colunas do array, e 
    retorna um ponteiro de ponteiros para inteiros 
    (int** filtroMedia(int **img, int lin, int col)). O array representa uma imagem, 
    contendo lin x col pixels, e em cada posição da mesma temos a intensidade da cor do 
    pixel correspondente. A função retorna o endereço de uma nova imagem, alocado 
    dinamicamente,  gerada a partir da aplicação de um filtro de média na imagem original. 
    Isto é, cada pixel, nas coordenadas (i, j) da nova imagem, se constrói como a média das 
    intensidades das cores nos pontos (i, j), (i+1, j), (i-1, j), (i, j+1), e (i, j-1)da 
    imagem original. Para os pixels nas bordas mantemos a cor original. Implemente uma 
    aplicação que:
    a. Gere uma imagem de 640 x 480 pixels preenchidos de forma aleatória e mostre os 25 
    pixels do canto superior esquerdo (a submatriz de 5x5 do campo superior esquerdo). 
    b. Aplique o filtro de média na imagem gerada e mostre os 25 pixels do canto superior 
    esquerdo (a submatriz de 5x5 do campo superior esquerdo) da nova imagem filtrada.
    c.Libere a memória alocada para as imagens;
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int** geraImagem(int lin, int col);
void liberaImagem(int** img, int lin, int col);
int* histograma(int **img, int lin, int col);
int retangulo(int** img, int lin, int col, int x, int y, int largura, int altura, int cor);
int** filtroMedia(int **img, int lin, int col);

int main(void)
{
    int lin = 640, col = 480;
    int** imagem;
    int** novaImagem;
    imagem = geraImagem(lin, col);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", imagem[i][j]);
        }
        printf("\n");
    }
    novaImagem = filtroMedia(imagem, lin, col);
    printf("--------------------\n ");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", novaImagem[i][j]);
        }
        printf("\n");
    }
    liberaImagem(imagem, lin, col);
    liberaImagem(novaImagem, lin, col);
    return 0;
}

int** filtroMedia(int **img, int lin, int col)
{
    int** novaImg = (int**) malloc(lin * sizeof(int*));
    novaImg[0] = (int*) malloc(col * sizeof(int));
    // tratando a fronteira superior
    for(int j = 0; j < col; j++)
    {
        novaImg[0][j] = img[0][j];
    }
    for(int i = 1; i < lin-1; i++)
    {
        novaImg[i] = (int*) malloc(col * sizeof(int));
        novaImg[i][0] = img[i][0]; // tratando a fronteira esquerda
        for(int j = 1; j < col-1; j++)
        {
            int soma = 0;
            for(int k = i - 1; k <= i + 1; k++)
            {
                for(int l = j - 1; l <= j + 1; l++)
                    soma += img[k][l];
            }
            novaImg[i][j] = soma/9;
        }
        novaImg[i][col-1] = img[i][col-1]; // tratando a fronteira direita
    }
    novaImg[lin-1] = (int*) malloc(col * sizeof(int));
    // tratando a fronteira inferior
    for(int j = 0; j < col; j++)
    {
        novaImg[lin-1][j] = img[lin-1][j];
    }
    return novaImg;
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

int* histograma(int **img, int lin, int col)
{
    int* hist = (int*) calloc(256, sizeof(int));
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            hist[img[i][j]]++;
        }
    }
    return hist;
}

void liberaImagem(int** img, int lin, int col)
{
    for(int i = 0; i < lin; i++)
    {
        free(img[i]);
    }
    free(img);
}

int retangulo(int** img, int lin, int col, int x, int y, int largura, int altura, int cor)
{
    if(x < 0 || y < 0 || x + largura > lin || y + altura > col)
        return FALSE;
    for(int i = x; i < x + largura; i++)
    {
        for(int j = y; j < y + altura; j++)
        {
            img[i][j] = cor%256;
        }
    }
    return TRUE;
}