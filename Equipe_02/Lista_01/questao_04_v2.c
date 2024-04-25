#include <stdio.h>
#include "lista_01.h"

int main()
{
	int tamanho=0;

	printf("Digite o Tamanho do tabuleiro(2 e 8):");
	scanf("%d", &tamanho);

	desenhaTabuleiro(tamanho);
	return 0;
}

int desenhaTabuleiro(int tamanho)
{
	if(tamanho < 2 || tamanho > 8)
		return 1;
	else{
		for(int i = 0; i < tamanho*5; i++)
		{
			for(int j = 0; j < tamanho*5; j++)
			{

				// Alterna entre '*' e ' ' para desenhar o padrão de xadrez
				if ((i / 5 + j / 5) % 2 == 0)
					printf("  ");// se for par desenha ' '
				else
					printf("* "); // se for impar '*'

			}

			printf("\n");
		}
	}
	return 0;
}
