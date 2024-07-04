/*
    Exercício 15.
    Uma matriz bidimensional pode ser substituída por um array unidimensional. Com esta 
    finalidade precisa ser definida uma estratégia para mapear as coordenadas da matriz 
    em índices do array. Uma forma de se fazer isto é: Dada uma matriz de tamanho 
    lin x col, podemos ordenar os elementos da matriz linha por linha no array de forma 
    que o elemento na posição (i, j) da matriz será mapeado para as posição de índice 
    (col*i + j) do array.  Utilizando como base este mapeamento:
    a. Implemente uma nova versão da função do exercício 11  
    (int* geraImagem(int lin, int col)) para que ela agora retorne uma imagem armazenada 
    em um array;
    b. Crie uma função que retorna a cor de um pixel específico de uma imagem armazenada 
    como um array (int getColor(int* img, int col, int i, int j));
    c. Implemente uma nova versão da função do exercício 12  
    (int* histograma(int *img, int lin, int col)) .
    d. Implemente uma nova versão da função do exercício 13 
    (int* filtroMedia(int *img, int lin, int col)).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraImagem(int lin, int col);
int getColor(int* img, int col, int i, int j);
int* histograma(int *img, int lin, int col);
int* filtroMedia(int *img, int lin, int col);

int main(void)
{
    int lin = 640, col = 480;
    int* imagem;
    int* novaImagem;
    imagem = geraImagem(lin, col);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", getColor(imagem, col, i, j));
        }
        printf("\n");
    }
    novaImagem = filtroMedia(imagem, lin, col);
    printf("--------------------\n ");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t", getColor(novaImagem, col, i, j));
        }
        printf("\n");
    }
    free(imagem);
    free(novaImagem);
    return 0;
}

int* geraImagem(int lin, int col)
{
    int* imagem = (int*) malloc(lin * col * sizeof(int));
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            imagem[col*i + j] = rand() % 256;
        }
    }
    return imagem;
}

int getColor(int* img, int col, int i, int j)
{
    return img[col*i + j];
}

int* histograma(int *img, int lin, int col)
{
    int* hist = (int*) calloc(256, sizeof(int));
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            hist[img[col*i + j]]++;
        }
    }
    return hist;
}

// ou

int* histogramaLin(int *img, int lin, int col)
{
    int* hist = (int*) calloc(256, sizeof(int));
    for(int i = 0; i < lin*col; i++)
    {
        hist[img[i]]++;
    }
    return hist;
}

int* filtroMedia(int *img, int lin, int col)
{
    int* novaImg = (int*) malloc(lin * col * sizeof(int));
    novaImg[0] = img[0];
    // tratando a fronteira superior
    for(int j = 0; j < col; j++)
    {
        novaImg[j] = img[j];
    }
    for(int i = 1; i < lin-1; i++)
    {
        novaImg[col*i] = img[col*i]; // tratando a fronteira esquerda
        for(int j = 1; j < col-1; j++)
        {
            int soma = 0;
            for(int k = i - 1; k <= i + 1; k++)
            {
                for(int l = j - 1; l <= j + 1; l++)
                    soma += img[col*k + l];
            }
            novaImg[col*i + j] = soma/9;
        }
        novaImg[col*i + col-1] = img[col*i + col-1]; // tratando a fronteira direita
    }
    // tratando a fronteira inferior
    for(int j = 0; j < col; j++)
    {
        novaImg[col*(lin-1) + j] = img[col*(lin-1) + j];
    }
    return novaImg;
}