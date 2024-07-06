/*
    Implemente as funções com o seguintes cabeçalhos:
    a. double* somaVet(double* vetA, double* vetB, int dim), que recebe dois vetores 
    do espaço de dimensão dim e retorna um vetor da mesma dimensão com a soma, 
    componente a componente, dos dois vetores;
    b. double* prodVetEscal(double* vetA, double a, int dim), que recebe um vetor 
    do espaço de dimensão dim e um escalar (um valor numérico), e retorna um vetor 
    da mesma dimensão com o produto de cada elemento do vetor com o escalar;
    c. double* prodVet(double* vetA, double* vetB, int dim), que recebe dois vetores 
    do espaço de dimensão dim, e retorna um vetor da mesma dimensão com o produto, 
    componente a componente, dos dois vetores;
    d. void imprimeVet(double* vetA, int dim), que imprime todos os componentes de 
    um vetor de espaço de dimensão dim, um do lado do outro, separados por vírgula 
    e delimitado por parênteses. 
*/

#include <stdio.h>
#include <stdlib.h>

double* somaVet(double* vetA, double* vetB, int dim);
double* prodVetEscal(double* vetA, double a, int dim);
double* prodVet(double* vetA, double* vetB, int dim);
void imprimeVet(double* vetA, int dim);
int menuDeTestes(void);

int main(void)
{
    double* vetA = (double*) malloc(3 * sizeof(double));
    double* vetB = (double*) malloc(3 * sizeof(double));
    double* vetC;
    int opcao;
    for(int i = 0; i < 3; i++)
    {
        vetA[i] = rand() % 100 + 1;
        vetB[i] = 1;
    }
    printf("Vetor A: ");
    imprimeVet(vetA, 3);
    printf("Vetor B: ");
    imprimeVet(vetB, 3);
    do
    {
        opcao = menuDeTestes();
        switch (opcao)
        {
            case 1:
                printf("Soma de vetores.\n");
                vetC = somaVet(vetA, vetB, 3);
                imprimeVet(vetC, 3);
                free(vetC);
                break;
            case 2:
                printf("Produto de vetor por escalar.\n");
                vetC = prodVetEscal(vetB, 2, 3);
                imprimeVet(vetC, 3);
                free(vetC);
                break;
            case 3:
                printf("Produto de vetores.\n");
                vetC = prodVet(vetA, vetB, 3);
                imprimeVet(vetC, 3);
                free(vetC);
                break;
            case 4:
                printf("Imprimindo vetores.\n");
                printf("Vetor A: ");
                imprimeVet(vetA, 3);
                printf("Vetor B: ");
                imprimeVet(vetB, 3);
                break;
            case 5:
                printf("Saindo...\n");
                break;
        }
    } while (opcao != 5);
    free(vetA);
    free(vetB);
    return 0;
}

int menuDeTestes()
{
    int opcao;
    printf("Escolha uma opção:\n");
    printf("1 - Soma de vetores.\n");
    printf("2 - Produto de vetor por escalar.\n");
    printf("3 - Produto de vetores.\n");
    printf("4 - Imprimir vetor.\n");
    printf("5 - Sair.\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 5)
    {
        printf("Opção inválida. Digite novamente.\n");
        scanf("%d", &opcao);
    }
    
    return opcao;
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
