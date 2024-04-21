#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lista_01.h"

// Implemente a função 
// int desenhaQuadrado(int tamanho, int vazado)
// Esta função imprime na tela um quadrado utilizando ‘*’. O tamanho deve ser fornecido pelo usuário como primeiro parâmetro da função. O tipo de quadrado é fornecido também pelo usuário no segundo parâmetro da função.
// Se o tamanho for menor que 1 ou maior que 20 a função retorna 1 e não desenha nada, caso contrário a função desenha o quadrado do tipo e tamanho indicado e retorna 0;  
// Se o parâmetro vazado for verdadeiro deve-se desenhar apenas as bordas do quadrado, caso contrário a função desenha ele preenchido. 
// Implemente uma aplicação que demonstra a aplicação da função. 

// como usar:
// AO RODAR O CODIGO PASSE OS NUMEROS COMO PARAMENTRO NA MAIN 
// EX .\a.exe 4 0


int desenhaQuadrado(int tam, int vaz);

int main(int argc, char *argv[])
{

    int tam = atoi(argv[1]);
    int vaz = atoi(argv[2]);

desenhaQuadrado(tam,vaz);
   

    return 0;
}

int desenhaQuadrado(int tam, int vaz){
     if (tam < 1 || tam > 20)
    {
        return 1;
    }

    if (vaz == 0)
    {

        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    if (vaz == 1)
    {

        printf("\n\n\n");

        for (int i = 0; i < tam; i++)
        {
            printf("*");
        }
        printf("\n");

        for (int i = 0; i < tam - 2; i++)
        {
            printf("*");
            for (int j = 0; j < tam-2; j++)
            {
                printf(" ");
            }

            printf("*");
            printf("\n");
        }
        for (int i = 0; i < tam; i++)
        {
            printf("*");
        }
        printf("\n");
    }
};
