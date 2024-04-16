#include <stdio.h>
#include "lista_01.h"

int main()
{
    char c[3][10] = {"gabriel","arara","papagaio"};
    for(int j = 0; j < 3; j++)
        printf("%s\n",c[j]);

    printf("\nPalavras invertidas:\n");
    for(int j = 0; j < 3; j++){
        escreveCon(c[j]);
        printf("\n");
    }

    for(int j = 0; j < 3; j++){
        if(palindromo(c[j],strlen(c[j]),0)) //strlen pega o tamanho
            printf("\n%s e palindromo\n",c[j]);
    }

    return 0;
}

void escreveCon(char *c)//pega o primeiro caractere da string
{

   if( *c != '\0'){
    escreveCon(c+1);
    putchar(*c);
   }
}

int palindromo(char *c,int n, int i)
{
    if( i >= n)
        return 1; //verdadeiro
    if(c[i] != c[n-1])
        return 0; //falso

    return palindromo(c, n - 1, i+1);
}


