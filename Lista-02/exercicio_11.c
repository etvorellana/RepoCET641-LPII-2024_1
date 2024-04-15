/*
    Pode-se calcular o resto da divisão, MOD, de x por y, de dois 
    números inteiros, usando-se a seguinte definição:
    MOD(|x|−|y|,|y|), se|x|>|y| 
    | x | se | x | < | y |  
    0 se | x | = | y |
    Então, crie uma função recursiva para descrever tal definição. 
    Crie também um algoritmo que leia os dois valores inteiros e 
    utilize a função criada para calcular o resto da divisão de x 
    por y, e imprima o valor computado.
*/

#include <stdio.h>
#include "lista-02.h"

int main(void)
{
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    printf("MOD(%d, %d) = %d\n", x, y, mod(x, y));
    return 0;
}

int mod(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else if (x == y)
    {
        return 0;
    }
    else
    {
        return mod(x - y, y);
    }
}