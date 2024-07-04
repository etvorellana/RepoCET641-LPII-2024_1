/*
Exercício 1
Implemente as seguintes funções que alocam arrays unidimensionais de inteiros:
a. int* alocaVetInt(int a): Esta função aloca um array inteiros de tamanho a, ou 
seja, cria um bloco de memória para armazenar a inteiros. Cada inteiros ocupa, 
normalmente 4 bytes, mas o operador sizeof retorna o tamanho de qualquer tipo 
de dado em C. Desta forma é mais seguro utilizá-lo na hora de especificar a 
quantidade de bytes a serem alocados. A função retorna o endereço de memória 
inicial do bloco alocado.
b. int* alocaVetIntZero(int a): Esta função aloca um array inteiros de tamanho a, 
e inicializa ele com o valor 0. A função retorna o endereço de memória inicial do 
bloco alocado.
c. int* alocaVetIntUm(int a): Esta função aloca um array inteiros de tamanho a, 
e inicializa ele com o valor 1. A função retorna o endereço de memória inicial 
do bloco alocado.
d. int* alocaVetIntCheio(int a, int val): Esta função aloca um array inteiros 
de tamanho a, e inicializa ele com o valor val. A função retorna o endereço de 
memória inicial do bloco alocado.

Exercício 2
A função calloc é uma alternativa ao uso da função malloc para alocação dinâmica 
de memória. Pesquise quais as diferenças no uso destas duas funções e indique em 
qual caso do exercício anterior o calloc pode ser utilizado de forma a 
simplificar a implementação.
void* calloc(size_t count, size_t size)
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int* alocaVetInt(int a);
int* alocaVetIntZero_1(int a);
int* alocaVetIntZero_2(int a);
int* alocaVetIntZero_3(int a); 
int* alocaVetIntZero_4(int a); 
int* alocaVetIntUm_1(int a);   
int* alocaVetIntUm_2(int a);   
int* alocaVetIntUm_3(int a);   
int* alocaVetIntCheio_1(int a, int val);
int* alocaVetIntCheio_2(int a, int val);
int menuDeTestes(void);


int main(void)
{
    int* vet;
    int opcao;
    do
    {
        opcao = menuDeTestes();
        switch (opcao)
        {
            case 1:
                printf("Alocando vetor de inteiros.\n");
                vet = alocaVetInt(10);
                printf("Inicializando vetor com valores aleatórios entre 1 e 6.\n");
                for(int i = 0; i < 10; i++)
                    vet[i] = rand() % 6 + 1;
                break;
            case 2:
                printf("Alocando vetor de inteiros com zeros.\n");
                printf("\tImplementação _all inclusive_ (;-)\n");
                vet = alocaVetIntZero_1(10);
                break;
            case 3:
                printf("Alocando vetor de inteiros com zeros.\n");
                printf("\tUtilizando alocaVetInt para alocar o vetor \n");
                vet = alocaVetIntZero_2(10);
                break;
            case 4:
                printf("Alocando vetor de inteiros com zeros.\n");
                printf("\tUtilizando alocaVetIntCheio_2 para alocar e inicializar o vetor\n");
                vet = alocaVetIntZero_3(10);
                break;
            case 5:
                printf("Alocando vetor de inteiros com zeros.\n");
                printf("\tUtilizando calloc para alocar e inicializar o vetor\n");
                vet = alocaVetIntZero_4(10);
                break;
            case 6:
                printf("Alocando vetor de inteiros com uns.\n");
                printf("\tImplementação _all inclusive_ (;-)\n");
                vet = alocaVetIntUm_1(10);
                break;
            case 7:
                printf("Alocando vetor de inteiros com uns.\n");
                printf("\tUtilizando alocaVetInt para alocar o vetor \n");
                vet = alocaVetIntUm_2(10);
                break;
            case 8:
                printf("Alocando vetor de inteiros com uns.\n");
                printf("\tUtilizando alocaVetIntCheio_2 para alocar e inicializar o vetor\n");
                vet = alocaVetIntUm_3(10);
                break;
            case 9:
                printf("Alocando vetor de inteiros com valor 9.\n");
                printf("\tImplementação _all inclusive_ (;-)\n");
                vet = alocaVetIntCheio_1(10, 9);
                break;
            case 10:
                printf("Alocando vetor de inteiros com valor 10.\n");
                printf("\tUtilizando alocaVetInt para alocar o vetor \n");
                vet = alocaVetIntCheio_2(10, 10);
                break;
            default:
                printf("Saindo...\n");
                break;
        }
        if (opcao != 11)
        {
            printf("O endereço de vet é: %p\n", vet);
            printf("O conteúdo de vet é: %d\n", *vet);
            printf("O conteúdo de vet[0] é: %d\n", vet[0]);
            printf("O tamanho de vet é: %lu\n", sizeof(vet));
            printf("O tamanho de vet[0] é: %lu\n", sizeof(vet[0]));
            for(int i = 0; i < 10; i++)
                printf("vet[%d]: %d\n", i, vet[i]);
            free(vet);
        }
    }while (opcao != 11);
    
    return 0;
}


int menuDeTestes(void)
{
    int opcao = 0;
    printf("Testando as implementações.");
    printf("Testes disponíveis:\n");
    printf("1. alocaVetInt - \n");
    printf("2. alocaVetIntZero_1 - \n");
    printf("3. alocaVetIntZero_2 - \n");
    printf("4. alocaVetIntZero_3 - \n");
    printf("5. alocaVetIntZero_4 - \n");
    printf("6. alocaVetIntUm_1 - \n");
    printf("7. alocaVetIntUm_2 - \n");
    printf("8. alocaVetIntUm_3 - \n");
    printf("9. alocaVetIntCheio_1 - \n");
    printf("10. alocaVetIntCheio_2 - \n");
    printf("11. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 11)
    {
        printf("Opção incorreta!!!.");
        printf("Testes disponíveis:\n");
        printf("1. alocaVetInt - \n");
        printf("2. alocaVetIntZero_1 - \n");
        printf("3. alocaVetIntZero_2 - \n");
        printf("4. alocaVetIntZero_3 - \n");
        printf("5. alocaVetIntZero_4 - \n");
        printf("6. alocaVetIntUm_1 - \n");
        printf("7. alocaVetIntUm_2 - \n");
        printf("8. alocaVetIntUm_3 - \n");
        printf("9. alocaVetIntCheio_1 - \n");
        printf("10. alocaVetIntCheio_2 - \n");
        printf("11. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
    };
    return opcao;
}

// 1.a
int* alocaVetInt(int a)
{
    int* vet = (int*) malloc(a * sizeof(int));
    return vet;
}

// 1.b
int* alocaVetIntZero_1(int a)
{
    int* vet = (int*) malloc(a * sizeof(int));
    for(int i = 0; i < a; i++)
    {
        vet[i] = 0;
    }
    return vet;
}
//ou
int* alocaVetIntZero_2(int a)
{
    int* vet = alocaVetInt(a);
    for(int i = 0; i < a; i++)
    {
        vet[i] = 0;
    }
    return vet;
}
// ou
int* alocaVetIntZero_3(int a)
{
    int* vet = alocaVetIntCheio_2(a, 0);
    return vet;
}
// ou e também respondendo o Exercício 2
int* alocaVetIntZero_4(int a)
{
    int* vet = (int *) calloc(a, sizeof(int));
    return vet;
}

// 1.c
int* alocaVetIntUm_1(int a)
{
    int* vet = (int*) malloc(a * sizeof(int));
    for(int i = 0; i < a; i++)
    {
        vet[i] = 1;
    }
    return vet;
}
// ou
int* alocaVetIntUm_2(int a)
{
    int* vet = alocaVetInt(a);
    for(int i = 0; i < a; i++)
    {
        vet[i] = 1;
    }
    return vet;
}
// ou ainda
int* alocaVetIntUm_3(int a)
{
    int* vet = alocaVetIntCheio_2(a, 1);
    return vet;
}

// 1.d
int* alocaVetIntCheio_1(int a, int val)
{
    int* vet = (int*) malloc(a * sizeof(int));
    for(int i = 0; i < a; i++)
    {
        vet[i] = val;
    }
    return vet;
}
// ou
int* alocaVetIntCheio_2(int a, int val)
{
    int* vet = alocaVetInt(a);
    for(int i = 0; i < a; i++)
    {
        vet[i] = val;
    }
    return vet;
}