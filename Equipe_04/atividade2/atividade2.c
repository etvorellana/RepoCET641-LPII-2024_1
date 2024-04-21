#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../lista_01.h"

// como usar:
// AO RODAR O CODIGO PASSE OS NUMEROS COMO PARAMENTRO NA MAIN 
// EX .\a.exe 10 2

int desenhaTriangulo(int tam, int tipo);

int main(int argc, char *argv[])
{

    int tam = atoi(argv[1]);
    int tipo = atoi(argv[2]);
desenhaTriangulo( tam,  tipo);
    // printf("%d, %d", tam, tipo);

   


    return 0;
}


int desenhaTriangulo(int tam, int tipo){
 if (tam < 1 || tam > 20)
    {
        return 1;
    }

    if (tipo == 2)
    {
        printf("\n\n");

        for (int i = tam; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (tipo == 1)
    {

        printf("\n\n");

        for (int i = 0; i <= tam; i++)
        {
            for (int j = i; j > 0; j--)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (tipo == 3)
    {

        printf("\n\n");

        for (int i = tam; i > 0; i--)
        {
               for (int j = 0; j < tam-i; j++)
            {
                printf(" ");
            }
            for (int w = i; w > 0 ; w--)
            {
                printf("*");
            }
            printf("\n");
         
            
        }
        
    }
    else if (tipo == 4)
    {

        printf("\n\n");

        for (int i = tam; i > 0; i--)
        {

            for (int w = i-1; w > 0 ; w--)
            {
                printf(" ");
            }
            for (int j = 0; j < tam-i+1; j++)
            {
                printf("*");
            }

            printf("\n");
            
            
        }
        
    }else{
        return 1;
    }
};