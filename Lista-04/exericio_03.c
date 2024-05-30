/*
    Exercicio 3.
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
int menuDeTestes(void);

int main(void)
{
    printf("Exercício 3.\n");
    int opcao;
    do
    {
        opcao = menuDeTestes();
        switch (opcao)
        {
            case 1:
                printf("Alocando string de caracteres.\n");
                char* str = alocaStr(10);
                printf("String alocada: %s\n", str);
                printf("Tamanho da string: %ld\n", strlen(str));
                printf("Preenchendo string com caracteres.\n");
                for(int i = 0; i < 10; i++)
                    str[i] = 'a' + i;
                str[10] = '\0';
                printf("String preenchida: %s\n", str);
                printf("Tamanho da string: %ld\n", strlen(str));
                free(str);
                break;
            case 2:
                printf("Alocando string de caracteres com espaços.\n");
                char* strEsp = alocaStrEsp(10);
                printf("String alocada: ->%s<-\n", strEsp);
                printf("Tamanho da string: %ld\n", strlen(strEsp));
                free(strEsp);
                break;
            case 3:
                printf("Alocando string de caracteres com caracteres iguais.\n");
                char* strCheia = alocaStrCheia(10, 'a');
                printf("String alocada: %s\n", strCheia);
                printf("Tamanho da string: %ld\n", strlen(strCheia));
                free(strCheia);
                break;
            case 4:
                printf("Saindo...\n");
                break;
        }
    } while(opcao != 4);

    return 0;
}


int menuDeTestes(void)
{
    int opcao;
    printf("Escolha uma opção:\n");
    printf("1. Testar alocaStr\n");
    printf("2. Testar alocaStrEsp\n");
    printf("3. Testar alocaStrCheia\n");
    printf("4. Sair\n");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 4)
    {
        printf("Opção inválida. Digite novamente.\n");
        scanf("%d", &opcao);
    }
    return opcao;
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