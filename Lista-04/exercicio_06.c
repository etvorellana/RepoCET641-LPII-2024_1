/*
    Implementar a seguinte função: char* geraNome(int tam) que retorna 
    uma string contendo uma "nome” gerado de forma aleatória, misturando 
    letras e alternando consoantes e vogais. O nome deve ter no mínimo 
    dois e no máximo tam caracteres, todos minúsculos menos o primeiro 
    que deve ser maiúsculo. Se tam for menor 2 a função retorna null.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* geraNome_Longo(int tam);
char* geraPalavra(int tam);
char* geraNome(int tam);



int main(void)
{
    srand(time(NULL));
    printf("Exercício 6.\n");
    char* nome;
    for(int i = 1; i <= 10; i++)
    {
        nome = geraNome(10);
        if (nome)
        {
            printf("Nome %d gerado: %s\n", i, nome);
            free(nome);
        }
    }
    return 0;
}


char* geraPalavra(int tam)
{
    if(tam < 2)
        return NULL;
    char* palavra = (char*) malloc((tam + 1) * sizeof(char));
    char vogais[] = "aeiou";
    char consoantes[] = "bcdfghjklmnpqrstvwxyz";
    int i = 0;
    int j = 0;
    tam = 2 + rand() % (tam - 2);
    while(i < tam)
    {
        if(i % 2 == 0)
        {
            palavra[i] = consoantes[rand() % 21];
        }
        else
        {
            palavra[i] = vogais[rand() % 5];
        }
        i++;
    }
    palavra[i] = '\0';
    return palavra;
}

char* geraNomeLongo(int tam)
{
    if(tam < 2)
        return NULL;
    char* nome = (char*) malloc((tam + 1) * sizeof(char));
    char vogais[] = "aeiou";
    char consoantes[] = "bcdfghjklmnpqrstvwxyz";
    int i = 0;
    int j = 0;
    tam = 2 + rand() % (tam - 2);
    while(i < tam)
    {
        if(i % 2 == 0)
        {
            nome[i] = consoantes[rand() % 21];
        }
        else
        {
            nome[i] = vogais[rand() % 5];
        }
        i++;
    }
    nome[0] = nome[0] - ('a' - 'A');
    nome[i] = '\0';
    return nome;
}

char* geraNome(int tam)
{
    if(tam < 2)
        return NULL;
    char* nome = geraPalavra(tam);
    nome[0] = nome[0] - ('a' - 'A');
    return nome;
}