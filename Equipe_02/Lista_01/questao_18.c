#include<stdio.h>
#include<string.h>
int quantidadeA(char x[],int n){
  int qtA=0;
  if(n==0)
    return 0;
  if(x[n-1]=='a'||x[n-1]=='A')
    qtA++;
  return qtA+quantidadeA(x,n-1);
}
int main(){
    char a[6]="ArAra";
    int x=quantidadeA(a,6);
    printf("%d",x);
    
}