#include <stdio.h>
#include <math.h>
#include "..//lista.h"

double valorMedio(double[], int);

int main() {

  double V[] = {1.5, 2.5, 3.5, 4.5};
  int t = 4;

  double m = valorMedio(V, t);
  printf("O valor medio dos elementos do array eh: %.2f\n", m);
}