#include <stdio.h>

int abaixoDaMedia(double x[], int n);

int main(void)
{
    double x[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Abaixo da média: %d\n", abaixoDaMedia(x, n));
    return 0;
}

double media(double x[], int n)
{
    double average = 0;
    for (int i = 0; i < n; i++)
    {
        average += x[i];
    }
    average /= n;
    return average;
}

int abaixoDaMedia(double x[], int n)
{
    double average = media(x, n);
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

int abaixoDaMediaLong(double x[], int n)
{
    int cont = 0;
    double media = 0;
    for (int i = 0; i < n; i++)
        media += x[i];
    media /= n;
    for(int i = 0; i < n; i++)
        if(x[i] < media)
            cont++;
    return cont;
}