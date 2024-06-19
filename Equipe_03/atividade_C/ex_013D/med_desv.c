#include <stdio.h>

#include "..//lista.h"

int main() {

   double v[] = {1.5, 2.5, 3.5, 4.5};
  int t = 4;

  double d = desvioPadrao(v, t);
  printf("O desvio padrao dos elementos do array e: %.2f\n", d);
}