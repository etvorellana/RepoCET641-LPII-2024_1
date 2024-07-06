#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main(void) {
  //serve para inicializar uma array chamada valores com os numeros definidos
  double valores[] = {1, 2, 3, 4, 5};

  //divide o total da array por um unico elemento, resultando no numero total de elementos da array
  int tamanho = sizeof(valores) / sizeof(valores[0]);

  //a funcao e chamada, tendo como parametros a array valores e o tamanho dele
  double media = valorMedio(valores, tamanho);

  //imprime o resultado na tela
  printf("Resultado: %.2f", media);

  return 0;
}
