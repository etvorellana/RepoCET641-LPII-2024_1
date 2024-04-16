#include <stdio.h>


int desenharPiramide(int tamanho, int tipo) {

  if(tamanho < 1 || tamanho > 20) {
    printf("Tamanho inválido");
    return 1;
  }

  if(tipo != 0 && tipo != 1){
    printf("Tipo inválido");
    return 1;
  }

  if(tipo == 0){

    for (int i = 1; i <= tamanho; i++) {

    for (int j = tamanho - i ; j>= 1; j--) {
        printf("  ");
    }
    for (int j = 1; j <= i; j++) {
            printf("* ");
        }

    for (int j = 1; j <= i; j++) {
      printf("* ");
      }
        printf("\n");
    }
    return 0;
    }

   else if(tipo == 1) {
    for (int i = tamanho; i >= 1; i--) {
        for (int j = 1; j <= tamanho - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
      for (int j = 1; j <= i; j++) {
          printf("* ");
      }
      for (int j = 1; j <= tamanho - i ; j++) {
          printf("  ");
      }
        printf("\n");
    }
    return 0;
    }

}

int main() {
    int tamanho, tipo;

    printf("Digite o tamanho da pirâmide: ");
    scanf("%d", &tamanho);

    printf("Digite o tipo de piramide (0) para verdade e (1) falsidade: ");
    scanf("%d", &tipo);

    desenharPiramide(tamanho,tipo);

    return 0;
}
