#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

int main(int argc, char const *argv[])
{
    int numero[20];
    int i = 0;
 
    printf("Obs, digite -1 para sair\n");
    printf("Digite os valores?\n: ");
    
    while (i < 20)
    {
        scanf("%d", &numero[i]);
        scanf("%*c");
        
        if (numero[i] == -1)
        {
            break;
        }
        i++;
    }

    printf ("O maior é %d\n", encontra (numero, 0, numero[0]));
    return 0;
}
