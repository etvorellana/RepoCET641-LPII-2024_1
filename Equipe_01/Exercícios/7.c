#include <stdio.h>

int desenhaLinhaR(int tamanho, char linha[]) {
  if (tamanho < 1 || tamanho > 20) {
    return 1;
  } else {
    linha[tamanho - 1] = '*';
    desenhaLinhaR(tamanho - 1, linha);
    printf("%c", linha[tamanho - 1]);
  }
  return 0;
}

int desenhaTriangulo(int tamanho, int tipo) {
  if (tamanho < 1 || tamanho > 20) {
    printf("Tamanho inválido");
    return 1;
  } else {

    char linha[21];

    switch (tipo) {
    case 1:
      for (int i = 1; i <= tamanho; i++) {
        desenhaLinhaR(i, linha);
        printf("\n");
      }
      break;
    case 2:
      for (int i = tamanho; i >= 1; i--) {
        desenhaLinhaR(i, linha);
        printf("\n");
      }
      break;
    case 3:
      for (int i = tamanho; i >= 1; i--) {
        for (int j = 1; j <= tamanho - i; j++) {
          printf(" ");
        }
        desenhaLinhaR(i, linha);
        printf("\n");
      }
      break;
    case 4:
      for (int i = 1; i <= tamanho; i++) {
        for (int j = tamanho - i; j >= 1; j--) {
          printf(" ");
        }
        desenhaLinhaR(i, linha);
        printf("\n");
      }
      break;
    default:
      printf("Tipo inválido");
      return 2;
    }
  }
  return 0;
}

int main() {
  int tamanho, tipo;
  printf("Digite a altura do triângulo: ");
  scanf("%d", &tamanho);
  printf("Escolha o tipo de triângulo (1-4):\n");
  printf("1 - Triângulo retângulo\n");
  printf("2 - Triângulo retângulo invertido\n");
  printf("3 - Triângulo retângulo invertido alinhado a direita\n");
  printf("4 - Triângulo retângulo alinhado à direita\n");
  scanf("%d", &tipo);

  desenhaTriangulo(tamanho, tipo);

  return 0;
}
