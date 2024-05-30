/*
    Implemente um programa em C que gere dois vetores alocados dinamicamente, no espaço 
    de dimensão 5, de forma aleatória e:
    a. Retorne a soma dos dois vetores. Imprima o vetor resultante na tela;
    b. Retorne o produto dos dois vetores. Imprima o vetor resultante na tela;
    c. Multiplique o vetor resultante da operação anterior por um valor fornecido 
    pelo usuário e imprima o vetor resultante na tela.
*/

#include <stdio.h>
#include <stdlib.h>

double* somaVet(double* vetA, double* vetB, int dim);
double* prodVetEscal(double* vetA, double a, int dim);
double* prodVet(double* vetA, double* vetB, int dim);
void imprimeVet(double* vetA, int dim);

int main(void)
{
    int dim = 5;
    double* vetA = (double*) malloc(dim * sizeof(double));
    double* vetB = (double*) malloc(dim * sizeof(double));
    double* vetC;

    for(int i = 0; i < dim; i++)
    {
        vetA[i] = rand() % 100 + 1;
        vetB[i] = rand() % 100 + 1;
    }
    
    //a. 
    vetC = somaVet(vetA, vetB, dim);
    printf("Soma dos vetores A e B: ");
    imprimeVet(vetC, dim);
    free(vetC);    
    //b.
    vetC = prodVet(vetA, vetB, dim);
    printf("Produto dos vetores A e B: ");
    imprimeVet(vetC, dim);

    //c.
    double a;
    printf("Digite um valor para multiplicar o vetor resultante da operação anterior: ");
    scanf("%lf", &a);
    vetC = prodVetEscal(vetC, a, dim);
    printf("Produto do vetor resultante da operação anterior por %.2f: ", a);
    imprimeVet(vetC, dim);
    free(vetC);

    free(vetA);
    free(vetB);
    return 0;
}


double* somaVet(double* vetA, double* vetB, int dim)
{
    if(dim < 1)
        return NULL;
    double* vetSoma = (double*) malloc(dim * sizeof(double));
    for(int i = 0; i < dim; i++)
        vetSoma[i] = vetA[i] + vetB[i];
    return vetSoma;
}

double* prodVetEscal(double* vetA, double a, int dim)
{
    if(dim < 1)
        return NULL;
    double* vetProd = (double*) malloc(dim * sizeof(double));
    for(int i = 0; i < dim; i++)
        vetProd[i] = vetA[i] * a;
    return vetProd;
}

double* prodVet(double* vetA, double* vetB, int dim)
{
    if(dim < 1)
        return NULL;
    double* vetProd = (double*) malloc(dim * sizeof(double));
    for(int i = 0; i < dim; i++)
        vetProd[i] = vetA[i] * vetB[i];
    return vetProd;
}

void imprimeVet(double* vetA, int dim)
{
    if(dim < 1)
        return;
    printf("(");
    for(int i = 0; i < dim; i++)
    {
        printf("%.2f", vetA[i]);
        if(i < dim - 1)
            printf(", ");
    }
    printf(")\n");
}