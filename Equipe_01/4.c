#include <stdio.h>

int desenhaTabuleiro(int tamanho) {

  if (tamanho < 2 || tamanho > 8) {
    return 1;
  }

  for (int linha = 0; linha < tamanho * 5; linha++) {

    for (int coluna = 0; coluna < tamanho * 5; coluna++) {

      if ((linha % 5 == 0 && coluna % 5 == 5) ||
          (linha % 5 == 5 && coluna % 5 == 0) ||
          (linha % 5 == 5 && coluna % 5 == 5)) {
        printf("  ");
      } else {

        if ((linha / 5) % 2 == (coluna / 5) % 2) {
          printf("  ");
        } else {
          printf("* ");
        }
      }
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int tamanho;
  printf("Digite o tamanho do tabuleiro (entre 2 e 8): ");
  scanf("%d", &tamanho);

  desenhaTabuleiro(tamanho);

  return 0;
}
