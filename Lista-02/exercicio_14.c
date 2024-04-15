/*
    Dado n e uma sequência de n números inteiros, fornecidos 
    pelo usuários, imprimir a sequência na ordem inversa a 
    que foi lida, sem usar um array. (spoiler: use recursividade (;-))
*/

#include <stdio.h>
#include "lista-02.h"



int main(void)
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("Digite %d valores inteiros:\n", n);
    inverte(n);
    return 0;
}

void inverte(int n)
{
    int x;
    if (n == 0)
    {
        return;
    }
    scanf("%d", &x);
    inverte(n - 1);
    printf("%d ", x);
}