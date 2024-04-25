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
                char array[tamanho];

                desenhaLinha(i, array);
                printf("%s\n", array);
            }
        } else if (tipo == 2) {
            for (int i = tamanho; i != 0; i--) {
                char array[tamanho];

                desenhaLinha(i, array);
                printf("%s\n", array);
            }
        } else if (tipo == 3) {
                char array[tamanho];

                desenhaLinha(tamanho, array);
                for (int i = 0; i < tamanho; i++) {
                    array[i-1] = ' ';
                    printf("%s\n", array);
                }
        } else if (tipo == 4) {
                char array[tamanho];
                
                for (int i = 1; i <= tamanho; i++) {
                    desenhaLinha(tamanho, array);
                    for (int j = tamanho-i; j != 0; j--) {
                        array[j-1] = ' ';
                    }
                    
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