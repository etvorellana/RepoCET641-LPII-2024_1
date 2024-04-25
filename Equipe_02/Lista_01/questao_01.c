#include <stdio.h>
#include "lista_01.h"
int main() {
  printf("Preenchido:\n");
  desenhaQuadrado(5,0);
  printf("\n");

  printf("Vazado:\n");
  desenhaQuadrado(5,1);
}
int desenhaQuadrado(int tamanho,int vazado){
  if(tamanho<1||tamanho>20)
  return 1;
   for(int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++)
    putchar((!vazado||i==0||i==tamanho-1||j==0||j==tamanho-1)?'*':' ');
    putchar('\n');}
    return 0;
}
