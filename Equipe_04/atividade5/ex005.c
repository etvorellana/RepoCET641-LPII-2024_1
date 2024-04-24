#include <stdio.h>
#include "../lista_01.h"

int desenhaLinha(int tamanho, char linha[]) {
    if (tamanho < 1 || tamanho > 20) {
        printf("O valor digitado deve estar entre 1 e 20.\n");
        return 1;
    } else {
        for (int i = 0; i < tamanho; i++) {
            linha[i] = '*';
        }
        linha[tamanho] = '\0';
        return 0;
    }
}

int main() {
    int tam = 0;

    printf("Digite o tamanho da linha: \n");
    scanf("%i", &tam);

    char arr[tam];

    desenhaLinha(tam, arr);

    printf("%s", arr);

    //printf("\n %i \n", arr[tam]);

    return 0;
}