#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lista_01.h"


int quantidade(char str[], int inicio, int fim);

int main(){
    char str_1[100];

    printf("Digite uma string: ");
    gets(str_1);

    int tamanho = strlen(str_1);

    int quant = quantidade(str_1, 0, tamanho - 1);
    printf("A quantidade eh: %d\n", quant);

    return 0;
}

int quantidade(char str[], int inicio, int fim) {
    int cont = 0;

    if (inicio > fim){ //Caso base: se inicio > fim ent�o para de contar.
        return 0;
    }

    if (str[inicio] == 'A' || str[inicio] == 'a'){
        cont = cont + 1;
    }

    return cont + quantidade(str, inicio + 1, fim);
}
