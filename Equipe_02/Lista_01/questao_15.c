#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_01.h"
#define MAX_SIZE 10

int main()
{
    double valores[MAX_SIZE];
    int N;

    srand(time(NULL));
    N = rand() % MAX_SIZE;

    for(int i = 0; i < N; i++)
        valores[i] = rand() % MAX_SIZE;

    for(int i = 0; i < N; i++)
        printf("valores = %.2lf\n",valores[i]);

    inversor(valores,N);

    for(int i = 0; i < N; i++)
        printf("inversos = %.2lf\n",valores[i]);
    return 0;
}

void inversor(double arr[ ], int n)
{
    if( n == 0)
        return;
    arr[n-1] = pow(arr[n-1],-1); // 1 / arr[n - 1];

  return inversor(arr, n-1);
}


