#include <stdio.h>
#include "..//lista.h"

int main() {
  int tam;
  char linha[21];
  printf("Informe o tamanho da linha: ");
  scanf("%d", &tam);

  desenhaLinha(tam, linha);
  printf("Linha desenhada: \n");
  printf("%s\n", linha);
}
