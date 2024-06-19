#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "..//lista.h"

int main(int argc, char *argv[]) {
	int tamanho, tipo;
	printf("-------------------------DESENHA PIRAMIDE-------------------------\n\n");
	printf("Informe o tamanho da piramide:\n");
	scanf("%d", &tamanho);
	printf("Informe o tipo da piramide:\n");
	scanf("%d", &tipo);
	desenhaPiramide(tamanho, tipo);
	return 0;
}