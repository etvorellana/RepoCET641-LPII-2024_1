/*
Crie uma função que recebe uma string e um array de inteiros 
(void contaCaracteres(char str[ ], int con [ ])) 
e retorna, no array de inteiros, quantas vezes aparece na 
string cada uma das letras do alfabeto. A função não deve 
fazer distinção entre maiúsculas e minúsculas.
*/

#include <stdio.h>
#include <string.h>
#include "lista-02.h"

int main() {
    char str[100];
    // criando um array de contadores preenchido com zeros
    int cont[26] = {0}; // 26 letras do alfabeto
    int contR[26] = {0}; // 26 letras do alfabeto

    printf("Digite uma string: ");
    fgets(str, 100, stdin);

    contaCaracteres(str, cont);
    contaCaracteresR(str, contR);

    for(int i = 0; i < 26; i++)
        printf("A letra %c aparece %d, %d vezes\n", i + 'a', cont[i], contR[i]);
    
    return 0;
}

void contaCaracteres(char str[ ], int con [ ])
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            con[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            con[str[i] - 'A']++;
        }
    }
}

/*
Implemente a versão recursiva do exercício anterior 
(void contaCaracteresR(char str[ ], int con [ ]))
*/

void contaCaracteresR(char str[ ], int con [ ])
{
    if(str[0] == '\0') {
        return;
    } else {
        if (str[0] >= 'a' && str[0] <= 'z') {
            con[str[0] - 'a']++;
        } else if (str[0] >= 'A' && str[0] <= 'Z') {
            con[str[0] - 'A']++;
        }
        contaCaracteresR(str + 1, con);
    }
}
