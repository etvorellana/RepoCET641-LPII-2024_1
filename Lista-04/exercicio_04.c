/*
    A função realloc permite redimensionar o espaço alocado para 
    um bloco de memória. Pesquise pela sintaxe e o uso desta função 
    e veja de que forma podemos utilizar a mesma para implementar 
    as seguintes funções.
    a. char* copiaStr(char* strFonte, char* strDestino): Esta função 
    copia o conteúdo da strFonte para a strDestino. e retorna o 
    endereço de strDestino. Vamos supor que as duas strings estão 
    totalmente preenchidas e que que a função retorna uma string 
    totalmente preenchida. 
    b. char* concatStr(char* strIni, char* strFim): Esta função 
    concatena o conteúdo da strIni e d a strFim na string strIni. 
    A função retorna o endereço da string strIni.  Vamos supor que 
    as duas strings estão totalmente preenchidas e que que a função 
    retorna uma string totalmente preenchida.     

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copiaStr(char* strFonte, char* strDestino);
char* concatStr(char* strIni, char* strFim);

int main(void)
{
    char* strIni = (char*) malloc(11 * sizeof(char));
    char* strFim = (char*) malloc(11 * sizeof(char));
    strIni = copiaStr("Hello", strIni);
    strFim = copiaStr(" World!", strFim);
    strIni = concatStr(strIni, strFim);
    printf("strIni: %s\n", strIni);
    free(strIni);
    free(strFim);
    return 0;


}

char* copiaStr(char* strFonte, char* strDestino)
{
    int tamFonte = strlen(strFonte);
    int tamDestino = strlen(strDestino);
    strDestino = (char*) realloc(strDestino, (tamFonte + 1) * sizeof(char));
    for(int i = 0; i < tamFonte; i++)
    {
        strDestino[i] = strFonte[i];
    }
    strDestino[tamFonte] = '\0';
    return strDestino;
}