#include <stdio.h>
#include <string.h>

void inverterString(char str[]) {
    // Verifica se a string tem tamanho 0 ou 1, nesse caso não há nada para inverter
    if (strlen(str) <= 1)
        return;

    // Troca o primeiro e o último caractere
    char temp = str[0];
    str[0] = str[strlen(str) - 1];
    str[strlen(str) - 1] = temp;

    // Chama a função recursivamente com a string sem o primeiro e o último caractere
    inverterString(&str[1]);
}

int ehPalindromo(char str[]) {
    // String auxiliar para armazenar a cópia da string original
    char strInvertida[strlen(str) + 1];

    // Copia a string original para a string auxiliar
    strcpy(strInvertida, str);

    // Inverte a string auxiliar
    inverterString(strInvertida);

    // Compara a string original com a string invertida
    if (strcmp(str, strInvertida) == 0)
        return 1; // É um palíndromo
    else
        return 0; // Não é um palíndromo
}

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
