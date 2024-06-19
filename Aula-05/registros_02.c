#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double* x;
    int n;
}tArrayD;

tArrayD createArrayD(int n)
{
    tArrayD array;
    array.x = (double*)malloc(n*sizeof(double));
    array.n = n;
    return array;
}

//void geraTemperaturas(double* x, int n)
void geraTemperaturas(tArrayD x)
{
    for(int i = 0; i < x.n; i++)
        x.x[i] = 10.0 + rand()%20;
    x.n = 0;

}

void desalocaArray(double* x, int* n)
{
    free(x);
    x = NULL;
    *n = 0;
}

void desalocaArrayD(tArrayD* x)
{
    free(x->x);
    x->x = NULL;
    x->n = 0;
}

int main(void)
{
    tArrayD temp = createArrayD(10);
    geraTemperaturas(temp);
    //geraTemperaturas(temp.x, temp.n);
    for(int i = 0; i < temp.n; i++)
        printf("Temperatura %d: %.2lf\n", i, temp.x[i]);
    desalocaArrayD(&temp);
    //desalocaArray(temp.x, &temp.n)
    return 0;
}