#include <stdio.h>
#include "lista_01.h"

int main()
{
    int N = 4;
    double valores[4]= {7,7,7,7};

    double media = valorMedioArr(valores, N);
    printf("Media = %.2f\n",media);
    return 0;
}

double valorMedioArr(double x[], int N)
{
    if(N == 0)
        return 0.0;

    return (x[N - 1] + valorMedioArr(x, N - 1) * (N - 1)) / N;
}
