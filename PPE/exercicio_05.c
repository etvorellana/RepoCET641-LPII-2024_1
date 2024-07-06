#include <stdio.h>

int quantParesR(int x[], int n);
int quantPares(int x[], int n);

int main(void)
{
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    printf("Quantidade de pares: %d\n", quantParesR(x, n));
    printf("Quantidade de pares: %d\n", quantPares(x, n));
    return 0;

}

int quantParesR(int x[], int n)
{
    if(n == 0)
        return 0;
    if(x[n-1] % 2 == 0)
        return 1 + quantParesR(x, n-1);
    return quantParesR(x, n-1);
}

int quantPares(int x[], int n)
{
    int cont = 0;
    for(int i = 0; i < n; i++)
        if(x[i] % 2 == 0)
            cont++;
    return cont;
}
