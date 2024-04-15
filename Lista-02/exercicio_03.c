/*
    Crie uma função que recebe uma string e dois caracteres 
    void trocaCaracteres(char ch1, char ch2, char str[]), 
    e substitua todas as ocorrências na string do caractere 
    ch1 pelo caractere ch2.
*/

#include <stdio.h>
#include <string.h>
#include "lista-02.h"

int main() {
    char str[100], frase[100], c1, c2;

    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    printf("Digite um caractere: ");
    c1 = getchar();
    printf("Digite outro caractere: ");
    c2 = getchar();
    strcpy(frase, str);
    trocaCaracteres(c1, c2, frase);
    printf("String sem o caractere: %s\n", frase);
    printf("String sem o caractere: %s\n", str);

    return 0;
}

void trocaCaracteres(char ch1, char ch2, char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch1) {
            str[i] = ch2;
        }
    }
}

/*
    Implemente a versão recursiva do exercício anterior 
    (void trocaCaracteresR(char ch1, char ch2, char str[]))
*/

void trocaCaracteresR(char ch1, char ch2, char str[])
{
    if(str[0] == '\0') {
        return;
    }else {
        if (str[0] == ch1) {
            str[0] = ch2;
        }
        trocaCaracteresR(ch1, ch2, str + 1); //ou
        //trocaCaracteresR(ch1, ch2, &str[1]);
    }
}