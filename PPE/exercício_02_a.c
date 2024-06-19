#include <stdio.h>
char str[] = "agiu desproporcionadamente";
int cont = 0;
int tam = 26;

void conta(int tam){
    for(int i = 0; i < tam; i++){
        if(str[i] == 'a')
            cont++; 
    }
}

int main(void){
    conta(tam);
    printf("A letra 'a' aparece %d vezes na string %s\n", cont, str);
    return 0;
}





