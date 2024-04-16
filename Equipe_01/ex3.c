#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main() {
    int tamanho, tipo;

    printf("Digite o tamanho da pirâmide: ");
    scanf("%d", &tamanho);

    printf("Digite o tipo de piramide (0) para verdade e (1) falsidade: ");
    scanf("%d", &tipo);

    desenharPiramide(tamanho,tipo);

    return 0;
}
