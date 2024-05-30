/*
    Implemente as seguintes funções para alocar dinamicamente strings 
    na forma de arrays de caracteres (c strings). 
    a. char* alocaStr(int a): Esta função aloca um array de caracteres 
    para armazenar até a caracteres e coloca o caractere ‘\0’ na 
    primeira posição do array para especificar que se trata de uma c 
    string vazia. Lembre que para armazenar a caracteres numa c string 
    é preciso reservar mais um caractere para o ‘\0’ no final. 
    b. char* alocaStrEsp(int a): Esta função aloca um array de 
    caracteres para armazenar até a caracteres e coloca o caractere 
    ‘ ’ (espaço em branco) em todas as posições do array caracterizando
    uma c string totalmente preenchida;
    c. char* alocaStrCheia(int a, char ch): Esta função aloca um array 
    de caracteres para armazenar até a caracteres e coloca o caractere 
    ch em todas as posições do array caracterizando uma c string 
    totalmente preenchida;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* alocaStr(int a);
char* alocaStrEsp(int a);
char* alocaStrCheia(int a, char ch);

int main(void)
{
    char* str = alocaStr(10);
    char* strEsp = alocaStrEsp(10);
    char* strCheia = alocaStrCheia(10, 'a');

    printf("str: %s\n", str);
    printf("strEsp: %s\n", strEsp);
    printf("strCheia: %s\n", strCheia);

    free(str);
    free(strEsp);
    free(strCheia);

    return 0;
}

char* alocaStr(int a)
{
    char* str = (char*) malloc((a + 1) * sizeof(char));
    str[0] = '\0';
    return str;
}

char* alocaStrEsp(int a)
{
    //char* str = (char*) malloc((a + 1) * sizeof(char));
    char* str = alocaStr(a);
    for(int i = 0; i < a; i++)
    {
        str[i] = ' ';
    }
    str[a] = '\0';
    return str;
}

char* alocaStrCheia(int a, char ch)
{
    //char* str = (char*) malloc((a + 1) * sizeof(char));
    char* str = alocaStr(a);
    for(int i = 0; i < a; i++)
    {
        str[i] = ch;
    }
    str[a] = '\0';
    return str;
}