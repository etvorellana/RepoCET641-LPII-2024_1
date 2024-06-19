#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int n;
    int *x;
}TVetor;
TVetor alocaArray(int n);
void desaloca(TVetor x);
void arrayAleotorio(TVetor x);
int main(void){
    TVetor x;
    x = alocaArray(10);
    arrayAleotorio(x);
    for(int i = 0; i < x.n; i++){
        printf("x[%d] = %d\n", i, x.x[i]);
    }
    desaloca(x);
    return 0;
}
