#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main() {
    int tamanho, tipo;
    printf("Digite a altura do triângulo: ");
    scanf("%d", &tamanho);
    printf("Escolha o tipo de triângulo (1-4):\n");
    printf("1 - Tipo 1\n");
    printf("2 - Tipo 2\n");
    printf("3 - Tipo 3\n");
    printf("4 - Tipo 4\n");
    scanf("%d", &tipo);

    if (desenhaTriangulo(tamanho, tipo) != 0) {
        printf("Erro ao desenhar o triângulo.\n");
    }

    return 0;
}
