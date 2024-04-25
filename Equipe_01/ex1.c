#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main(void) {

  int tamanho, vazado;

  printf("Digite o tamanho do quadrado: ");
  scanf("%d", &tamanho);

  printf("\nDigite se o quadrado será vazado ou não(0 para não e 1 para sim): ");
  scanf("%d", &vazado);

  desenhaQuadrado(tamanho, vazado);

  return 0;
}
