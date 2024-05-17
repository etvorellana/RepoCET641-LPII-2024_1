#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *pch;
    int* pa;
    double *px;
    void* p;  

    // podemos alocar um bloco de memória de tamanho 8 bytes da seguintes forma:
    p = malloc(8);
    // p é um ponteiro void, que pode apontar para qualquer tipo de dado
    px = (double *)p;
    // temos 8 bytes que permite armazenar um double
    *px = 3.14;
    double x = *px;
    printf("x = %f\n", x);
    *px *= 2;
    printf("x = %f, *px = %f\n", x, *px);
    // Os mesmos 8 bytes podem ser utilizados para armazenar dois inteiros 
    pa = (int *)p;
    pa[0] = 42;
    pa[1] = 43;
    printf("pa[0] = %d, pa[1] = %d\n", pa[0], pa[1]);
    pa[0]++;
    if(pa[0] == pa[1])
        printf("pa[0] == pa[1]\n");
    else
        printf("pa[0] != pa[1]\n");
    // se tentamos acessar este endereço de memora com o ponteiro px ele ainda
    // avalia o conteúdo como um double
    printf("px = %f\n", *px);
    // Os mesmos 8 bytes podem ser utilizados para armazenar 8 char
    pch = (char *)p;
    for(int i = 0; i < 7; i++)
    {
        pch[i] = 'a' + i;
    }
    pch[7] = '\0';
    printf("pch = %s\n", pch);
    // para liberar a memória alocada usamos a função free
    free(p);
    return 0;
}