/*
    Crie uma função que recebe uma string e um caractere 
    (void apagaCaractere(char ch, char str[])), 
    e apague todas as ocorrências desse caractere na string.
*/

#include <stdio.h>
#include <string.h>
#include "lista-02.h"

int main() {
    char str[100], teste[100], ch;

    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    printf("Digite um caractere: ");
    ch = getchar();
    strcpy(teste, str);
    apagaCaractere(ch, teste);
    printf("String sem o caractere: %s\n", teste);
    printf("String sem o caractere: %s\n", str);

    strcpy(teste, str);
    apagaCaractereV2(ch, teste);
    printf("String sem o caractere: %s\n", teste);
    printf("String sem o caractere: %s\n", str);

    strcpy(teste, str);
    apagaCaractereR(ch, teste);
    printf("String sem o caractere: %s\n", teste);
    printf("String sem o caractere: %s\n", str);

    strcpy(teste, str);
    apagaCaractereV2R(ch, teste);
    printf("String sem o caractere: %s\n", teste);
    printf("String sem o caractere: %s\n", str);


    return 0;
}

// Implementação do exercício 
void apagaCaractere(char ch, char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            str[i] = ' ';
        }
    }
}

/*
    Implemente a versão recursiva do exercício anterior 
    (void apagaCaractereR(char ch, char str[]))
*/
void apagaCaractereR(char ch, char str[])
{
    if(str[0] == '\0') {
        return;
    }else {
        if (str[0] == ch) {
            str[0] = ' ';
        }
        apagaCaractereR(ch, str + 1);
        //apagaCaractereR(ch, &str[1]);
    }
}



//Uma implementação diferente para o exercício anterior
void apagaCaractereV2(char ch, char str[])
{
    int i, j;

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
   // ch = t 
   //                                   i 
   // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 
   //[e,s,a,n,d,o, ,a, ,a, ,f,u,n,\0,ã,o,\0]
   //                             j
}


//Uma implementação recursiva para o exercício anterior ...
// mas incompleta.
void apagaCaractereV2R(char ch, char str[])
{
    if(str[0] == '\0') {
        return;
    }else {
        if(str[0] != ch) {
            apagaCaractereV2R(ch, str + 1);
        }else{
            str[0] = str[1];
            apagaCaractereV2R(ch, str);
        }
    }
}

