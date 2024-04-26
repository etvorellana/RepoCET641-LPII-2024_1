#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "..//lista.h"

int main(int argc, char const *argv[])
{
    int tam = 0;
    int vaza = 0;
    int cont = 0;
    
    printf("*Obs: 1 a 20\n");
    printf("Qual é o tamnho do quadrado?\n: ");
    tam = verificar();

    //verifica se é maior que o limite
    while (tam < 1 || tam > 20)
    {
        printf("Tamanho não permitido.\n");
        printf("Digite apenas 1 a 20\n: ");
        tam = verificar();
        cont++;
        if (cont >= 4)
        {
            printf("XXXXXXXXXXXX\n");
            printf("Procure um adulto e volte mais tarde.\n");
            return 0;
        }
    }
    
    cont = 0;

    menu();
    printf("Qual tipo, 1 ou 2?\n: ");
    vaza = verificar();
 
    //verifica se é diferente do permitido
    while (vaza != 1 && vaza != 2)
    {
        printf("Digite 1 ou 2: ");
        vaza = verificar();
        cont++;
        if (cont >= 4)
        {
            printf("XXXXXXXXXXXX\n");
            printf("Procure um adulto e volte mais tarde.\n");
            return 0;
        }
    }

    cont = 0;

    desenhaQuadrado(tam, vaza);

    return 0;
}
