#include <stdio.h>
#include "Biblioteca/lista_01.h"

int main(void) {
  //determinada uma array chamada valores com numeros tipo double
  double valores[] = {1, 2, 3, 4, 5};
  //descobrir o tamanho da array valores
  N = sizeof(valores) / sizeof(valores[0]);

  //uso da funçao e atribuiçao do valor encontrado para a variavel media
  double media = valorMedioG(valores);

  printf("O valor médio é: %.2f\n", media);

  return 0;
}
