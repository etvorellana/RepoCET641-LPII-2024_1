#include<stdio.h>
int desenhaLinha(int,char[]);
int desenhaTriangulo(int, int);
int main(){
  int tamanho=5;
  char linha[tamanho];
  desenhaLinha(tamanho,linha);
  putchar('\n');
  desenhaTriangulo(tamanho,4);
}
int desenhaLinha(int tamanho, char linha[]) {
  if (tamanho < 1 || tamanho > 20)
    return 1;
  for (int i = 0; i < tamanho; i++)
    linha[i] = '*';
  linha[tamanho] = '\0';
  puts(linha);
  return 0;
}
int desenhaTriangulo(int tamanho, int tipo) {
  if (tamanho > 20 || tamanho <= 1)
    return 2;
  char linha[tamanho];
  switch (tipo) {
  case 1:
    for (int i = 0; i < tamanho; i++)
      desenhaLinha(i + 1, linha);
    break;
  case 2:
    for (int i = 0; i < tamanho; i++)
      desenhaLinha(tamanho - i, linha);
    break;
  case 3:
    for (int i = 0; i < tamanho; i++) {
      for (int j = 0; j < i; j++)
        putchar(' ');
      desenhaLinha(tamanho - i, linha);
    }
    break;
  case 4:
    for (int i = 0; i < tamanho; i++) {
      for (int j = tamanho - i - 1; j > 0; j--)
        putchar(' ');
      desenhaLinha(i + 1, linha);
    }
  default:
    return 1;
  }
  return 0;
}
