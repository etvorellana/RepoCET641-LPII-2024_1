#include "lista_01.h"
#include <stdio.h>

int main() {
	desenhaTabuleiro(5);
}

void printN(char c, int n) {
	for (int i = 0; i < n; i++)
		putchar(c);
}

int desenhaTabuleiro(int tamanho) {
	if (tamanho <= 2 || tamanho > 8) return 1;

	for (int linha = 0; linha < tamanho; linha++) {
		char c1 = (linha % 2 == 0) ? ' ' : '*';
		char c2 = (linha % 2 == 0) ? '*' : ' ';

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < tamanho; j++) {
				char c = (j % 2 == 0) ? c1 : c2;
				printN(c, 5);
			}
			putchar('\n');
		}
	}
	return 0;
}
