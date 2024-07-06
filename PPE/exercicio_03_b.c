#include <stdio.h>

int abaixoDaMedia(double x[]);

int main(void)
{
    double x[] = {1, 2, 3, 4, 5,0};
    printf("Abaixo da média: %d\n", abaixoDaMedia(x));
    return 0;
}

double media(double x[], int *n)
{
    double average = 0;
    int i = 0;
    while(x[i] > 0)
    {
        average += x[i];
        i++;
    }
    average /= i;
    *n = i;
    return average;
}

int abaixoDaMedia(double x[])
{
    int n;
    double average = media(x, &n);
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < average)
        {
            cont++;
        }
    }
    return cont;
}

int abaixoDaMediaLong(double x[])
{
    double media = 0;
    int n = 0, cont = 0;
    while(x[n] > 0)
    {
        media += x[n];
        n++;
    }
    media /= n;
    for(int i = 0; i < n; i++)
        if(x[i] < media)
            cont++;
    return cont;
}