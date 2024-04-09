#include <stdio.h>
#include <string.h>

#include "manipulandoStrings.h"

int main(void)
{
    char nome[50];
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);
    printf("Seu nome %s !!!!\n", nome);
    ajustaFGetsString(nome);
    printf("Seu nome %s !!!!\n", nome);
    return 0;
}

