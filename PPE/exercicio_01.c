#include <stdio.h>

void troca_1(int *a, int *b);
void troca_2(int a, int b);
void troca_3(int *a, int *b);
void troca_4(int x[]);
int troca_5(int a, int*b);


int main(void)
{
    int a, b;
    printf("Entre com o valor de a: ");
    scanf("%d", &a);
    printf("Entre com o valor de b: ");
    scanf("%d", &b);
    // troca os valores de a e b
    //troca_1(&a, &b); //Ok
    troca_2(a, b); //Não ok
    //troca_3(&a, &b); //Não ok
    //int x[] = {a, b}; 
    //troca_4(x); //Ok
    //a = x[0];
    //b = x[1];
    // = troca_5(a, &b); //Ok
    printf("Trocando os valores de a e b\n");
    printf("a = %d, b = %d\n", a, b);
    

    return 0;
}

void troca_1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void troca_2(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void troca_3(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void troca_4(int x[])
{
    int temp = x[0];
    x[0] = x[1];
    x[1] = temp;
}

int troca_5(int a, int*b)
{
    int temp = a;
    a = *b;
    *b = temp;
    return a;
}


