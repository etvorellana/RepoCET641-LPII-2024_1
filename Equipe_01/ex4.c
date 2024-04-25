#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main() {
  int tamanho;
  printf("Digite o tamanho do tabuleiro (entre 2 e 8): ");
  scanf("%d", &tamanho);

  desenhaTabuleiro(tamanho);

  return 0;
}
