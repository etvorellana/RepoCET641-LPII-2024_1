#include <stdio.h>
#include <stdlib.h>

int *alocaArray(int n);
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