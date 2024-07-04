#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "..//lista.h"

int main() {
  int N;

  printf("Digite a quantidade de elementos no array: ");
  scanf("%d", &N);

  // verifica se N é válido
  if (N <= 0) {
    printf("Quantidade inválida de elementos.\n");
    return 1;
  }

  double valores[N];

  printf("Digite os %d valores do array: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &valores[i]);
  }

  // calcular o valor médio dos valores no array
  double media = valorMedioG(valores, N);

  printf("O valor médio dos valores no array é: %.2lf\n", media);

  return 0;
}
