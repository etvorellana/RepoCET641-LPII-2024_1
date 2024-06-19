#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

int main() {
	int tamanho, tipo;
	printf("Informe o tamanho do triangulo:\n");
	scanf("%d", &tamanho);
	char linha[tamanho];
	printf("Informe o tipo do trinagulo\n");
	scanf("%d", &tipo);
	desenhaTrianguloRec(tamanho , tipo);
	return 0;
}
