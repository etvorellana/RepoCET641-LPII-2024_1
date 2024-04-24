//  Implemente a função 
// int desenhaLinhaR(int tamanho, char[] linha)
// como uma versão recursiva da função implementada no exercício 5.
// Teste esta função no exemplo desenvolvido no exercício 2. 


#include <stdio.h>
#include <string.h>
#include "../lista_01.h"

int desenhaLinhaR(int tamanho, char linha[]) { 
    if (tamanho < 1 || tamanho > 20) {
        return 1;
    } else {
        linha[tamanho-1] = '*';
        desenhaLinhaR(tamanho-1, linha);   
    } 
    return 0;
}

int main() {
    int tam = 0;

    printf("Digite o tamanho da linha: \n");
    scanf("%i", &tam);

    char arr[21];

    desenhaLinhaR(tam, arr);

    printf("%s", arr);
    printf("\n");

    return 0;
}