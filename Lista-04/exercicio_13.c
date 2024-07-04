/*
    Exercício 13.
     Crie uma função que recebe um ponteiro de ponteiros para inteiros, contendo 
     valores entre 0 e 255, dois inteiros contendo o número de linhas e colunas 
     do array, e retorna um ponteiro para inteiros 
     (int* histograma(int **img, int lin, int col)). O array representa uma 
     imagem, contendo lin x col pixels, e em cada posição da mesma temos a 
     intensidade da cor do pixel correspondente. A função retorna o endereço 
     de uma array de inteiros, alocado dinamicamente,  contendo o histograma 
     da imagem. Isto é, o array conte quantas vezes aparece na matriz cada uma 
     dos 256 possíveis valores. Este exercício já foi feito anteriormente 
    sem alocação dinâmica de memória. Implemente uma aplicação que:
    a. Gere uma imagem de 640 x 480 pixels preenchidos de forma aleatória. 
    b. Determine o histograma da imagem e imprima os 10 primeiros valores, 
    os 10 últimos e 10 valores centrais do mesmo.
    c. Modifique a imagem para que a mesma contenha um fundo branco (cor 255) 
    com um retângulo de 300 x 200 pixels no meio de cor 125 e, dentro dele, 
    outro retângulo de 100 por 100 de cor preta (0).
    d. Determine o histograma da imagem e imprima os 10 primeiros valores, 
    os 10 últimos e 10 valores centrais do mesmo.
    e. Libere de liberar a memória alocada para a imagem e para o histograma;
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int** geraImagem(int lin, int col);
void liberaImagem(int** img, int lin, int col);
int* histograma(int **img, int lin, int col);
int retangulo(int** img, int lin, int col, int x, int y, int largura, int altura, int cor);

int main(void)
{
    int lin = 640, col = 480;
    int** imagem;
    int* hist;
    imagem = geraImagem(lin, col);
    hist = histograma(imagem, lin, col);
    printf("10 primeiros valores do histograma: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n10 valores centrais do histograma: ");
    for(int i = 123; i < 133; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n10 últimos valores do histograma: ");
    for(int i = 246; i < 256; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n");
    retangulo(imagem, lin, col, 0, 0, 640, 480, 255);
    retangulo(imagem, lin, col, 170, 140, 300, 200, 125);
    retangulo(imagem, lin, col, 270, 240, 100, 100, 0);
    free(hist);
    hist = histograma(imagem, lin, col);
    printf("10 primeiros valores do histograma: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n10 valores centrais do histograma: ");
    for(int i = 123; i < 133; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n10 últimos valores do histograma: ");
    for(int i = 246; i < 256; i++)
    {
        printf("%d - %d ", i, hist[i]);
    }
    printf("\n");
    printf("Verificando o resultado: \n");
    printf("Total de pixels na imagem: %d\n", lin*col);
    printf("Total de pixels brancos: %d\n", hist[255]);
    printf("Total de pixels cinza: %d\n", hist[125]);
    printf("Total de pixels pretos: %d\n", hist[0]);
    printf("Total de pixels nas tres cores: %d\n", hist[255] + hist[125] + hist[0]);
    free(hist);
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