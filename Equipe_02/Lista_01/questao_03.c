#include <stdio.h>
#include "lista_01.h"

int main()
{
    int tamanho=0, tipo;

    printf("Digite o Tamanho do Piramide(1 e 20):");
    scanf("%d", &tamanho);

    printf("Tipo De Piramide  Cima(1) Baixo(2):");
    scanf("%d", &tipo);

    desenhaPiramide(tamanho,tipo);
    return 0;
}

int desenhaPiramide(int tamanho, int tipo)
{
    if(tamanho < 0 || tamanho > 20)
            return 1;
    else{
        switch (tipo)
            {
            case 1:
                for(int i = 0; i < tamanho; i++)
                {
                    for(int j = 0; j < tamanho - i; j++)
                        printf(" ");

                    for(int j = 0; j <= i; j++)
                        printf("*");

                    for(int j = 0; j <= i; j++)
                        printf("*");
                    printf("\n");
                }
                break;
            default:
                for(int i = tamanho; i > 0 ; i--)
                {
                    for(int j = tamanho - i; j > 0; j--)
                        printf(" ");

                    for(int j = i; j > 0; j--)
                        printf("*");

                    for(int j = i; j > 0; j--)
                        printf("*");
                    printf("\n");
                }
                break;
            }

    }
    return 0;
}
