#include <stdio.h>

int desenhaTriangulo( int tamanho, int tipo)
{
  if (tamanho < 1 || tamanho > 20){
    printf("Tamanho inválido");
    return 1;
  }
  else

    switch (tipo) {
      case 1:
         for (int i = 1; i <= tamanho; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }

          break;
      case 2:
        for (int i = tamanho; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            for (int j = 1; j <= tamanho - i ; j++) {
                printf("  ");
            }
            printf("\n");
        }
          break;
      case 3:
        for (int i = tamanho; i >= 1; i--) {
            for (int j = 1; j <= tamanho - i; j++) {
                printf("  ");
            }
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
          break;
      case 4:
        for (int i = 1; i <= tamanho; i++) {
            for (int j = tamanho - i ; j>= 1; j--) {
                printf("  ");
            }
            for (int j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
    break;
      default:
          printf("Tipo de triângulo inválido.\n");
          return 2;
  }
}

  int main() {
      int tamanho, i, j;
      int tipo;

      printf("Digite a altura do triângulo: ");
      scanf("%d", &tamanho);

      printf("Escolha o tipo de triângulo (1-4):\n");
      printf("1 - Tipo 1\n");
      printf("2 - Tipo 2 \n");
      printf("3 - Tipo 3\n");
      printf("4 - Tipo 4\n");
      scanf("%d", &tipo);

    desenhaTriangulo(tamanho, tipo);

      return 0;
  }
