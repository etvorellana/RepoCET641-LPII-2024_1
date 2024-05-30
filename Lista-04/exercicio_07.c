/*
    Exercício 7.
    Implementar a seguinte função: char* geraFrase(int tam) que retorna 
    uma string contendo uma "frase” gerada de forma aleatória, misturando 
    palavras geradas de forma aleatória. As palavra deve ter no mínimo 
    dois e no máximo 10 caracteres, todos minúsculos menos a primeira 
    palavra que deve começar com o primeiro caractere maiúsculo. A frase 
    deve ter tam palavras.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* geraPalavra(int tam);
char* geraNome(int tam);
char* geraFrase(int tam);

int main(void)
{
    srand(time(NULL));
    printf("Exercício 7.\n");
    char* frase;
    for(int i = 1; i <= 10; i++)
    {
        frase = geraFrase(10);
        if (frase)
        {
            printf("Frase %d gerada: %s\n", i, frase);
            free(frase);
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

char* geraNome(int tam)
{
    if(tam < 2)
        return NULL;
    char* nome = geraPalavra(tam);
    nome[0] = nome[0] - ('a' - 'A');
    return nome;
}

char* geraFrase(int tam)
{
    if(tam < 1)
        return NULL;
    char* frase = (char*) malloc(1 * sizeof(char));
    frase[0] = '\0';
    char* palavra;
    for(int i = 0; i < tam; i++)
    {
        palavra = geraPalavra(10);
        if(palavra)
        {
            if(i == 0)
            {
                palavra[0] = palavra[0] - 32;
            }
            frase = (char*) realloc(frase, (strlen(frase) + strlen(palavra) + 2) * sizeof(char));
            strcat(frase, palavra);
            strcat(frase, " ");
            free(palavra);
        }
    }
    frase[strlen(frase) - 1] = '\0';
    return frase;
}