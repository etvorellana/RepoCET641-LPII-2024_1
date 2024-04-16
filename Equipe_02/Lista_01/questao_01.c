#include<stdio.h>
int quadrado(int,int);
int main(){
  quadrado(5,1);
  quadrado(5,0);
}
int quadrado(int tamanho,int vazado){
  if(tamanho<1||tamanho>20)
  return 1;
   for(int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++)
    putchar((vazado||i==0||i==tamanho-1||j==0||j==tamanho-1)?'*':' ');
    putchar('\n');}
    return 0;
}