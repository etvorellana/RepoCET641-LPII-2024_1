#include <stdio.h>
#include <stdlib.h> //para poder utilizar a função rand()
#include <time.h>   //para poder utilizar a funçao time()

int main(void)
{     
    printf("Utilizando arrays\n");
    printf("A função rand() gera um inteiro entre 0 e RAND_MAX\n");
    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("Simulando 10 lançamentos de um dado:\n");
    int dado[20]; //declarando um array de inteiros
    int hist[6] = {0, 0, 0, 0, 0, 0}; //declarando e inicializando um array de inteiros
    printf("( ");
    for (int i = 0; i < 20; i++)
    {
        dado[i] = 1 + rand() % 6;
        hist[dado[i] - 1]++; //incrementando o contador
        printf("%d", dado[i]);
        if (i < 19)
            printf(", ");
        else
            printf(")\n");
    }
    for(int i = 0; i < 6; i++){
        printf("Face %d: %d vezes\n", i+1, hist[i]);
        hist[i] = 0; //zerando o contador
    }
    printf("Todas as vezes que rodar este exemplo vai gerar o mesmo resultado!\n");
    unsigned long int semente;
    printf("Entre com a semente para gerar uma nova sequencia: ");
    scanf("%lu", &semente);
    srand(semente);
    printf("( ");
    for (int i = 0; i < 20; i++)
    {
        dado[i] = 1 + rand() % 6;
        hist[dado[i] - 1]++; //incrementando o contador
        printf("%d", dado[i]);
        if (i < 19)
            printf(", ");
        else
            printf(")\n");
    }
    for(int i = 0; i < 6; i++){
        printf("Face %d: %d vezes\n", i+1, hist[i]);
        hist[i] = 0; //zerando o contador
    }
    printf("Sementes diferentes irão gerar resultados diferentes!\n");
    printf("A mesma semente gera o mesmo resultado!\n");
    printf("Escolhendo a semente de forma automática\n");
    srand(time(NULL));
    printf("( ");
    for (int i = 0; i < 20; i++)
    {
        dado[i] = 1 + rand() % 6;
        printf("%d", dado[i]);
        hist[dado[i] - 1]++; //incrementando o contador
        if (i < 19)
            printf(", ");
        else
            printf(")\n");
    }
    for(int i = 0; i < 6; i++){
        printf("Face %d: %d vezes\n", i+1, hist[i]);
        hist[i] = 0; //zerando o contador
    }
    printf("Todas as vezes que rodar este exemplo gera diferentes resultados!\n");
    return 0;
}