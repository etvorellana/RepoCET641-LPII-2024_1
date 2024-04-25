#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lista_01.h"

int desenhaLinhaR(int tamanho, char linha[]) { 
    if (tamanho < 1 || tamanho > 20) {
        return 1;
    } else {
        linha[tamanho-1] = '*';
        desenhaLinhaR(tamanho-1, linha);   
    } 
    return 0;
}

int desenhaTriangulo1(int tamanho, int tipo) {
    if (tamanho < 1 || tamanho > 20) {
        printf("O tamanho deve estar entre 1 e 20.\n");
        return 1;
    } else if (tipo < 1 || tipo > 4) {
        printf("O tipo digitado deve estar entre 1 e 4.\n");
        return 2;
    } else {
        if (tipo == 1) {
            for (int i = 1; i <= tamanho; i++) {
                char array[21];

                desenhaLinhaR(i, array);
                array[i] = '\0';
                printf("%s\n", array);
            }
        } else if (tipo == 2) {
            for (int i = tamanho; i > 0; i--) {
                char array[21];

                desenhaLinhaR(i, array);
                array[i] = '\0';
                printf("%s\n", array);
            }
        } else if (tipo == 3) {
                char array[21];

                desenhaLinhaR(tamanho, array);
                for (int i = 0; i < tamanho; i++) {
                    array[i-1] = ' ';
                    array[tamanho] = '\0';
                    printf("%s\n", array);
                }
        } else if (tipo == 4) {
                char array[21];
                
                for (int i = 1; i <= tamanho; i++) {
                    desenhaLinhaR(tamanho, array);
                    for (int j = tamanho-i; j != 0; j--) {
                        array[j-1] = ' ';
                    }
                    array[tamanho] = '\0';
                    printf("%s\n", array);
                }
        }
        return 0;
    }
}


int main() {
    int tam, tipo = 0;

    printf("Digite o tamanho do triângulo: \n");
    scanf("%i", &tam);
    printf("Digite o tipo do triângulo: \n");
    scanf("%i", &tipo);

    desenhaTriangulo1(tam, tipo);
    return 0;
}