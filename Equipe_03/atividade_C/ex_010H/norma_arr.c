#define N10 5
#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"


int main(int argc, char *argv[]) {
	double x[N10], nx[N10];
	int i;
	for(i = 0; i < N10; i++){
		printf("Digite o valor para a posicao [%d]", i);
		scanf("%lf", &x[i]);
	}
	printf("Vetor normalizado!\n");
	normaliza(x);
	return 0;
}