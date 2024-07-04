#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverterString(char str[], int i, int n) {

    if (i >= n){
        return;
    } else {
        char temp;

        temp = str[i];
        str[i] = str[n];
        str[n] = temp;

        inverterString(str, i + 1, n - 1); 
      
    }
}

int ehPalindromo(char str[], int i, int n){

    if(i >= n){
        return 1;
    }

    else{
        if (str[i] != str[n]){
            return 0;
        }
    }

    return ehPalindromo(str, i + 1, n - 1); 
  
}
  int main() {

      char str[100];

      // Solicita a entrada da string ao usuário
      printf("Digite uma string(números ou letras minúsculas): ");
      fgets(str,100,stdin);
      str[strlen(str) - 1] = '\0';

    int n = strlen(str);

    inverterString(str,0, n - 1);
    printf("A string invertida é: %s\n", str);
      
    
      if (ehPalindromo(str,0, n - 1))
          printf("É um palíndromo.\n");
      else
          printf("Não é um palíndromo.\n");

      return 0;
  }