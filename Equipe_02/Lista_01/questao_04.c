#include<stdio.h>
int desenhaTabuleiro(int);
int main(){
 desenhaTabuleiro(5);
}
int desenhaTabuleiro(int tamanho) {
  if (tamanho <= 2 || tamanho > 8)
    return 1;
for(int i=0;i<tamanho;i++)
  if(i%2==0){
  for(int i=0;i<tamanho;i++){
   for (int i = 0; i < tamanho; i++) {
          for(int j=0;j<tamanho;j++)
            putchar(' ');
          for(int k=0;k<tamanho;k++)
            putchar('*');}
  putchar('\n');}}
  else{
    for(int i=0;i<tamanho;i++){
     for (int i = 0; i < tamanho; i++) {
            for(int j=0;j<tamanho;j++)
              putchar('*');
            for(int k=0;k<tamanho;k++)
              putchar(' ');}
    putchar('\n');}}
      return 0;
  }