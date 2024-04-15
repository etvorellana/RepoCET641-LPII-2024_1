/*
    Escrever a função double 
    vpol(int n, double c[ ], double x), 
    de forma recursiva, para calcular o valor do polinômio 
    Pn(x) = c0xn +c1xn-1++cn-1x+cn para um dado x.
*/

#include <stdio.h>
#include "lista-02.h"

int main(void)
{
    double c[] = {1, 2, 3, 4, 5};
    double x = 2;
    printf("Pn(%lf) = %lf\n", x, vpol(4, c, x));
    return 0;

}

double potenciaD(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * potenciaD(x, n - 1);
}

double vpol(int n, double c[ ], double x)
{
    if (n == 0)
    {
        return c[0];
    }
    return c[n] * potenciaD(x, n) + vpol(n - 1, c, x);

}