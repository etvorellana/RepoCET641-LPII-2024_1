#include <stdio.h>
#include <string.h>

#include "manipulandoStrings.h"

int main(void)
{
    char fileName[50];
    printf("Digite o nome do arquivo: ");
    fgets(fileName, 50, stdin);
    ajustaFGetsString(fileName);
    printf("abrindo o arquivo  %s para leitura\n", fileName);
    return 0;
}