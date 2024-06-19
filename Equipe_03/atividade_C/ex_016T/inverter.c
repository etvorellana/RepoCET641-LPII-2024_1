#include <stdio.h>
#include <string.h>
#include "..//lista.h"

int main() {
    char frase[20];

    printf("Digite a frase\n: ");

    fgets (frase, sizeof(frase), stdin);

    printf("\nInveertida: ");
    inverteFrase(frase);
    printf("\n");
    return 0;
}
