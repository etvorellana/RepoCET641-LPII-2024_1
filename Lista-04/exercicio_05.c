/*
    Exercício 5.
    Implementar a seguinte função: char* geraPalavra(int tam) que retorna 
    uma string contendo uma "palavra” gerada de forma aleatória, misturando 
    letras e alternando consoantes e vogais. A palavra deve ter no mínimo 
    dois e no máximo tam caracteres, todos minúsculos. Se tam for menor 2 
    a função retorna null.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* geraPalavra(int tam);

int main(void)
{
    srand(time(NULL));
    printf("Exercício 5.\n");
    char* palavra;
    for(int i = 1; i <= 10; i++)
    {
        palavra = geraPalavra(10);
        if (palavra)
        {
            printf("Palavra %d gerada: %s\n", i, palavra);
            free(palavra);
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