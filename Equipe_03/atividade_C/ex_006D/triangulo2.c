#include <stdio.h>
#include "..//lista.h"

int main() {
  int t, tp;
  printf("Informe o tamanho do triangulo: ");
  scanf("%d", &t);

  printf("Informe o tipo do triangulo: ");
  scanf("%d", &tp);

  desenhaTriangulo2(t, tp);

}