/*
    Implemente uma função recursiva que, dados dois números 
    inteiros x e n, calcula o valor de x^n.
*/

#include <stdio.h>
#include "lista-02.h"

int main(void)
{
    int x, n;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("%d^%d = %d\n", x, n, potencia(x, n));
    return 0;
}

int potencia(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * potencia(x, n - 1);
}