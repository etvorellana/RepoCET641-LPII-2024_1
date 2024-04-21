#include <stdlib.h>
#include <stdio.h>
#include "../lista_01.h"


int maior_valor(int vetor[], int tam, int indice);

int main(){

    int tam, i, resultado;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor_1[tam];

    for(i=0; i<tam; i++){
        printf("Informe um valor: ");
        scanf("%d", &vetor_1[i]);
    }

    printf("O maior valor eh: %d\n", maior_valor(vetor_1, tam, 0));
}

int maior_valor(int vetor[], int tam, int indice){
    if (tam == 0){
        return vetor[indice];
    }
    else{
        if(vetor[tam - 1] > vetor[indice]){
            return maior_valor(vetor, tam - 1, tam - 1);
        }
        else{
            return maior_valor(vetor, tam - 1, indice);
        }
    }
}
