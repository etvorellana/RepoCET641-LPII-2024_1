#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

int main(int argc, char *argv[]) {
	int i, N;
	printf("Digite o tamanho do vetor:\n");
	scanf("%d", &N);
	double x[N];
	for(i = 0; i < N; i++){
		printf("Digite o valor para a posicao [%d]", i);
		scanf("%lf", &x[i]);
	}
	printf("Vetor normalizado!\n");
	normalizando(x, N);
	return 0;
}