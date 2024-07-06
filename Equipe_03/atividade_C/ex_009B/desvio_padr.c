#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "..//lista.h"
#include <math.h>


int main() {
  int N;

  // Solicita ao usuário para fornecer o valor de N
  printf("Digite a quantidade de elementos no array: ");
  scanf("%d", &N);

  // Verifica se N é válido
  if (N <= 0) {
    printf("Quantidade inválida de elementos.\n");
    return 1;
  }

  // Declara e inicializa o array com o tamanho fornecido pelo usuário
  double valores[N];

  // Solicita ao usuário para fornecer os valores do array
  printf("Digite os %d valores do array: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &valores[i]);
  }

  // Calcula o desvio padrão dos valores no array
  double desvioPadrao = desvioPadraoG(valores, N);

  // Imprime o resultado
  printf("O desvio padrão dos valores no array é: %.2lf\n", desvioPadrao);

  return 0;
}