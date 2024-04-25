#include <stdio.h>
#include "lista_01.h"
int main() {
	int n = 5;
	char linha[n+1];
	desenhaLinhaR(n, linha);
	putchar('\n');
	desenhaTriangulo(n, 1);
	printf("\n");
	desenhaTriangulo(n, 2);
	printf("\n");
	desenhaTriangulo(n, 3);
	printf("\n");
	desenhaTriangulo(n, 4);
	return 0;
}
int desenhaLinhaR(int tamanho, char linha[]) {
	if (tamanho <= 0 || tamanho > 20)
		return 1;
	linha[tamanho - 1] = '*';
	desenhaLinhaR(tamanho - 1, linha);
	printf("%c", linha[tamanho - 1]);
	return 0;
}
int desenhaTriangulo(int tamanho, int tipo) {
	if (tamanho <= 0 || tamanho > 20)
		return 1;
	char linha[tamanho + 1];

	switch (tipo) {
	case 1:
		for (int i = 1; i <= tamanho; i++) {
			desenhaLinhaR(i, linha);
			printf("\n");
		}
		break;
	case 2:
		for (int i = tamanho; i >= 1; i--) {
			desenhaLinhaR(i, linha);
			printf("\n");
		}
		break;
	case 3:
		for (int i = 1; i <= tamanho; i++) {
			for (int j = 1; j < i; j++)
				printf(" ");
			desenhaLinhaR(tamanho - i + 1, linha);
			printf("\n");
		}
		break;
	case 4:
		for (int i = 1; i <= tamanho; i++) {
			for (int j = tamanho; j > i; j--)
				printf(" ");
			desenhaLinhaR(i, linha);
			printf("\n");
		}
		break;
	default:
		return 2;
	}
	return 0;
}
