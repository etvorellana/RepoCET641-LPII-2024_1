#include <stdio.h>
#include <string.h>
#include "Biblioteca/lista_01.h"

int main() {
    char str[100];

    // Solicita a entrada da string ao usuário
    printf("Digite uma string: ");
    scanf("%s", str);

    // Verifica se a string é um palíndromo
    if (ehPalindromo(str))
        printf("%s é um palíndromo.\n", str);
    else
        printf("%s não é um palíndromo.\n", str);

    return 0;
}
