#include <stdio.h>
#include <stdlib.h>

int* alocaArray(int n);
void desaloca(int *x);
void arrayAleotorio(int *x, int n);

int main(void)
{
    int *x;
    x = alocaArray(10);
    arrayAleotorio(x, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }
    desaloca(x);
    return 0;
}

void alocaArray2(int **x, int n)
{
    *x = (int*) malloc(n * sizeof(int));
}

int* alocaArray(int n)
{
    int *x;
    x = (int*) malloc(n * sizeof(int));
    return x;
    // return (int*) malloc(n * sizeof(int));
}

void desaloca(int *x)
{
    free(x);
}

void arrayAleotorio(int *x, int n)
{
    for(int i = 0; i < n; i++)
    {
        x[i] = rand() % 100;
    }
}