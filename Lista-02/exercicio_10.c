/*
    O máximo divisor comum (MDC) de dois números inteiros 
    x e y pode ser calculado usando-se uma definição recursiva:
    MDC(x, y) = MDC(x − y, y), se x > y . 
    Além disso, sabe-se que:
    MDC(x, y) = MDC( y, x) 
    MDC(x, x) = x

    Crie uma função recursiva para descrever tal definição. 
    Crie, também, um algoritmo que leia os dois valores inteiros 
    e utilize a função criada para calcular o MDC de x e y, e 
    imprima o valor computado.
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
    printf("MDC(%d, %d) = %d\n", x, y, mdc(x, y));
    return 0;
}

int mdc(int x, int y)
{
    if (x == y)
    {
        return x;
    }
    else if (x > y)
    {
        return mdc(x - y, y);
    }
    else
    {
        return mdc(y, x);
    }
}