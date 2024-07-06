#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main() {
    int tamanho, tipo;
    printf("Digite a altura do triângulo: ");
    scanf("%d", &tamanho);
    printf("Escolha o tipo de triângulo (1-4):\n");
    printf("1 - Triângulo retângulo\n");
    printf("2 - Triângulo retângulo invertido\n");
    printf("3 - Triângulo retângulo invertido espelhado\n");
    printf("4 - Triângulo retângulo alinhado à direita\n");
    scanf("%d", &tipo);

    if (desenhaTriangulo(tamanho, tipo) != 0) {
        printf("Erro ao desenhar o triângulo.\n");
    }

    return 0;
}
