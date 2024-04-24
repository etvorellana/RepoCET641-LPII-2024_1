#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quantidade(char str[]);

int main(){
    char str_1[] = "StellA dA Silva Ribas";

    int quant = quantidade(str_1);
    printf("A quantidade eh: %d\n", quant);

    return 0;
}

int quantidade(char str[]) {
    int cont = 0;

    if (str[0] == '\0'){
        return 0;
    }

    else{
        if(str[0] == 'A' || str[0] == 'a'){
            cont = cont + 1;
        }

        cont+=quantidade(str + 1);
    }

    return cont;
}
