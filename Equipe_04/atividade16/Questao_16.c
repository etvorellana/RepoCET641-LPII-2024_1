#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lista_01.h"


void inverter_string(char str[], int inicio, int fim);
int verificar_palindromo(char str[], int inicio, int fim);

int main(){
    char str_1[100];
    printf("Digite uma string: ");
    gets(str_1);

    int tamanho = strlen(str_1);

    inverter_string(str_1, 0, tamanho - 1);
    printf("A string invertida: %s\n", str_1);

    if (verificar_palindromo(str_1, 0, tamanho - 1))
        printf("A string eh um palindromo.\n");
    else
        printf("A string nao eh um palindromo.\n");

    return 0;
}


void inverter_string(char str[], int inicio, int fim) {
    if (inicio >= fim){
        return;
    }
    else {
        char aux;

        aux = str[inicio];
        str[inicio] = str[fim];
        str[fim] = aux;

        inverter_string(str, inicio + 1, fim - 1); // Chamada recursiva para inverter o restante da string
    }
}

int verificar_palindromo(char str[], int inicio, int fim){

    if(inicio >= fim){
        return 1;
    }

    else{
        if (str[inicio] != str[fim]){
            return 0;
        }
    }

    return verificar_palindromo(str, inicio + 1, fim - 1); // Chamada recursiva para verificar o restante da string
}
