#include <stdio.h>
char str[] = "agiu desproporcionadamente";
int cont = 0;
int tam = 26;
int main(void){
    for(int i = 0; i < tam; i++){
        if(str[i] == 'a')
            cont++;
    }
    printf("A letra 'a' aparece %d vezes na string %s\n", cont, str);
    return 0;
}





