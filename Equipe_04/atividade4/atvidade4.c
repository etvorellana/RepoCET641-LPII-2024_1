#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lista_01.h"

// como usar:
// AO RODAR O CODIGO PASSE OS NUMEROS COMO PARAMENTRO NA MAIN 
// EX .\a.exe 6

int desenhaTabuleiro(int tam);

int main(int argc, char *argv[])
{

    int tam = atoi(argv[1]);

    printf("\n");

    desenhaTabuleiro(tam);

    return 0;
}


int desenhaTabuleiro(int tam)
{
    if (tam < 2 || tam > 8)
    {
        return 1;
    }

    int x = 0;
    if (tam % 2 == 0)
    {
        for (int i = 0; i < tam; i++)
        {

            for (int v = 0; v < 5; v++)
            {
                for (int h = 0; h < tam; h++)
                {

                    if (x == 0)
                    {
                        printf("     ");
                        x = 1;
                    }
                    else if (x == 1)
                    {
                        printf("*****");
                        x = 0;
                    }
                }
                printf("\n");
            }

            if (x == 0)
            {
                x = 1;
            }
            else if (x == 1)
            {
                x = 0;
            }
        }
    }
    else if (tam % 2 == 1)
    {
        for (int i = 0; i < tam; i++)
        {

            for (int v = 0; v < 5; v++)
            {
                for (int h = 0; h < tam; h++)
                {

                    if (x == 0)
                    {
                        printf("     ");
                        x = 1;
                    }
                    else if (x == 1)
                    {
                        printf("*****");
                        x = 0;
                    }
                    if (h == tam - 1)
                    {
                        if (x == 0)
                        {
                            x = 1;
                        }
                        else
                        {
                            x = 0;
                        }
                    }
                }
                printf("\n");
            }

            if (x == 0)
            {
                x = 1;
            }
            else if (x == 1)
            {
                x = 0;
            }
        }
    }

    return 0;
}