/*
    Exercício 11.
    Crie uma função, para gerar uma imagem, que recebe dois inteiros contendo 
    o número de linhas e colunas da mesma. A função retorna um ponteiro de 
    ponteiros para inteiros (int** geraImagem(int lin, int col)). A matriz 
    gerada representa uma imagem, contendo lin x col pixels, e em cada posição 
    da mesma temos a intensidade da cor do pixel correspondente, preenchidos 
    de forma aleatória, com valores entre 0 e 255.
*/

#include <stdio.h>
#include <stdlib.h>

int** geraImagem(int lin, int col);

int main(void)
{
    int lin, col;
    int** imagem;
    printf("Digite o número de linhas e colunas da imagem: ");
    scanf("%d %d", &lin, &col);
    imagem = geraImagem(lin, col);
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d\t", imagem[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < lin; i++)
    {
        free(imagem[i]);
    }
    free(imagem);
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