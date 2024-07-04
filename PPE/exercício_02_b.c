#include <stdio.h>
char str[] = "agiu desproporcionadamente";
int cont;
int tam = 26;
int conta(){
    //int cont = 0;
    for(int i = 0; i < tam; i++){
        if(str[i] == 'a')
            cont++;
    }
    return cont;
}
int main(void){
    conta();
    printf("A letra 'a' aparece %d vezes na string %s\n", cont, str);
    return 0;
}






