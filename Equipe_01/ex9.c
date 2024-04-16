#include <stdio.h>
//neste caso, math.h e usado para o uso da funcao pow e sqrt
#include <math.h>
#include "Biblioteca/lista_01.h"

int main(void) {
  //definicao de uma array chamada valores com numeros do tipo double
  double valores[] = {2.5, 4.5, 6.5, 8.5, 10.5};

  //serve para calcular o tamanho da array
  N = sizeof(valores) / sizeof(valores[0]);

  //chama a funcao de desvioPadrao para calcular o desvio
  //dos elementos da array valores, como foi dito no argumento
  double desvio = desvioPadraoG(valores);

  //imprime o valor encontrado acima
  printf("Desvio Padrão: %.2f\n", desvio);

  return 0;
}
