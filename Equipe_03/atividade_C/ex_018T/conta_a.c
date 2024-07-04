#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

int main() {
    char frase[20];

    printf("Digite a frase");
    
    fgets(frase, sizeof(frase), stdin);

    int ocorrencias = contarCaracteresA(frase, 0);
    printf("'a' ou 'A' aparece %d vezes\n", ocorrencias);
    return 0;
}