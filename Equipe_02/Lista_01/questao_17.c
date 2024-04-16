#include <stdio.h>
#include "lista_01.h"

int main()
{
    int arr[5] = { 1001, 24 ,369 , 44, 55};

    int maior = maiorNumero(arr, 5);
    printf("Maior: %d",maior);

    return 0;
}

int maiorNumero(int arr[], int n)
{
    if( n == 1)
        return arr[0]; //caso o array tenha uma posição

    int maior = maiorNumero(arr, n-1); // primeiro executa esse varias vezes
    return (arr[n-1] > maior) ? arr[n - 1] : maior; // por ultimo depois de execultar a recursividade ele compara
}
