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
    Na implementação destas funções não é permitido o uso de nenhuma 
    função definida no arquivo de cabeçalho string.h, com exceção da 
    função strlen(). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copiaStr(char* strFonte, char* strDestino);
char* concatStr(char* strIni, char* strFim);
int menuDeTestes(void);

int main(void)
{
    printf("Exercício 4.\n");
    int opcao;
    do
    {
        opcao = menuDeTestes();
        switch (opcao)
        {
            case 1:
                printf("Copiando string.\n");
                char* strFonte = "String de teste.";
                char* strDestino = (char*) malloc(50 * sizeof(char));
                for(int i = 0; i < 15; i++)
                    strDestino[i] = 'a' + i;
                printf("String fonte: %s, tamanho: %lu, %lu\n", strFonte, strlen(strFonte), sizeof(strFonte));
                printf("String destino: %s, tamanho: %lu, %lu\n", strDestino, strlen(strDestino), sizeof(strDestino));
                strDestino = copiaStr(strFonte, strDestino);
                printf("String destino: %s, tamanho: %lu, %lu\n", strDestino, strlen(strDestino), sizeof(strDestino));
                free(strDestino);
                break;
            case 2:
                printf("Concatenando strings.\n");
                char* strIni = (char*) malloc(50 * sizeof(char));
                strIni = copiaStr("String inicial.", strIni);
                char* strFim = "String final.";
                printf("String inicial: %s, tamanho: %lu, %lu\n", strIni, strlen(strIni), sizeof(strIni));
                printf("String final: %s, tamanho: %lu, %lu\n", strFim, strlen(strFim), sizeof(strFim));
                strIni = concatStr(strIni, strFim);
                printf("String inicial: %s, tamanho: %lu, %lu\n", strIni, strlen(strIni), sizeof(strIni));
                free(strIni);
                break;
            case 3:
                printf("Saindo.\n");
                break;
        }
    } while(opcao != 3);
    return 0;


}

int menuDeTestes(void)
{
    int opcao;
    printf("Escolha uma opção:\n");
    printf("1. Copiar string.\n");
    printf("2. Concatenar strings.\n");
    printf("3. Sair.\n");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 3)
    {
        printf("Opção inválida. Escolha uma opção válida:\n");
        scanf("%d", &opcao);
    }
    return opcao;

}

char* copiaStr(char* strFonte, char* strDestino)
{
    int tamFonte = strlen(strFonte);
    int tamDestino = strlen(strDestino);
    printf("tamFonte: %d, %lu\n", tamFonte, sizeof(strFonte));
    printf("tamDestino: %d, %lu\n", tamDestino, sizeof(strDestino));
    if(tamFonte > tamDestino)
    {
        strDestino = (char*) realloc(strDestino, (tamFonte + 1) * sizeof(char));
    }
    for(int i = 0; i < tamFonte; i++)
    {
        strDestino[i] = strFonte[i];
    }
    strDestino[tamFonte] = '\0';
    return strDestino;
}

char* concatStr(char* strIni, char* strFim)
{
    int tamIni = strlen(strIni);
    int tamFim = strlen(strFim);
    printf("tamIni: %d, %lu\n", tamIni, sizeof(strIni));
    printf("tamFim: %d, %lu\n", tamFim, sizeof(strFim));
    strIni = (char*) realloc(strIni, (tamIni + tamFim + 1) * sizeof(char));
    for(int i = 0; i < tamFim; i++)
    {
        strIni[tamIni + i] = strFim[i];
    }
    strIni[tamIni + tamFim] = '\0';
    return strIni;
}