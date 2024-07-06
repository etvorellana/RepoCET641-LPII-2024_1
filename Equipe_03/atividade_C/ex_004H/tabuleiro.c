#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

int desenhaTabuleiro(int tamanho);

int main() {
	int tamanho;
	printf("-------------------------DESENHA TABULEIRO-------------------------\n\n");
	printf("Desenhe o tamanho do tabuleiro que vai ser gerado:\n");
	scanf("%d", &tamanho);
	desenhaTabuleiro(tamanho);
	return 0;
}