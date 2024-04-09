/*
    Uma das formas de calcular a raiz quadrada de um número natural 
    é pelo método das frações periódicas continuadas. Esse método usa 
    como denominador uma repetição de frações. Essa repetição pode ser 
    feita uma quantidade específica de vezes. Por exemplo, ao repetir 2 
    vezes a fração contínua para calcular a raiz quadrada de 2, 
    temos a fórmula abaixo.
    21+11+12
    Sua tarefa é, dado o número N de repetições, calcular o valor 
    aproximado da raiz quadrada de 2.
*/

#include <stdio.h>

int main(void) {
  int n, i;
  double raiz = 0;

  printf("Digite o número de repetições: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    raiz = 1 + 1 / (2 + raiz);
  }

  raiz += 1;

  printf("A raiz quadrada de 2 é aproximadamente %.10lf\n", raiz);

  return 0;
}