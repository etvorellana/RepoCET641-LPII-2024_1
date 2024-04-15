/*
    Faça um programa (utilizando recursividade) que peça 
    para o usuário digitar um número, em seguida, faça a 
    soma de todos os algarismos do número.
*/

#include <stdio.h>
#include "lista-02.h"

int main(void)
{
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("A soma dos algarismos de %d é %d\n", n, somaAlgarismos(n));
    return 0;
}

int somaAlgarismos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + somaAlgarismos(n / 10);
}