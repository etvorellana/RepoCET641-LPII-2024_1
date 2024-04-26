#include <stdio.h>
  #include <string.h>

  void inverterString(char str[]) {
    
if (str[0] == '\0') {
        return;
    } else {

    inverterString(str + 1);
    printf("%c", str[0]);
     
    }
}

  int ehPalindromo(char str[], int n) {
   
      if (n <= str[0]) {
        return 0;
      }
        
       if (str[0] != str[n]) {
              return 1;
   
  }
    return ehPalindromo(str + 1, n - 1);
  }
  int main() {

      char str[100];

      // Solicita a entrada da string ao usuário
      printf("Digite uma string: ");
      gets(str);
      

      // Inverte a string
      printf("A string invertida é: ");
      inverterString(str);
    printf("\n");
    
   
     
      // Verifica se a string é um palíndromo
      if (ehPalindromo(str, 100)) 
          printf("%s é um palíndromo.\n", str);
      else
          printf("%s não é um palíndromo.\n", str);

      return 0;
  }