#include <stdio.h>

/*Implemente uma função para calcular o valor médio de um conjunto de valores armazenados em um array de valores de tipo double. O cabeçalho da função deve ser:
double valorMedioG(double x[ ]);
A quantidade de elementos no array é armazenada na variável global, N, declarada como sendo de tipo int. Implemente uma aplicação que demonstra a aplicação da função.*/

//variável global
int N;

//funcao usada para calcular o valor medio de uma array com numeros tipo double
double valorMedioG(double x[]) {
  double soma = 0.0;

  //percorre todos os valores na array e os soma, armazenando na variavel soma
  for (int i = 0; i < N; i++)
    soma += x[i];

  //formula para obter a media
  double media = soma / N;

  //retorna o valor obtido na variavel media
  return media;
}

int main(void) {
  //determinada uma array chamada valores com numeros tipo double
  double valores[] = {1, 2, 3, 4, 5};
  //descobrir o tamanho da array valores
  N = sizeof(valores) / sizeof(valores[0]);

  //uso da funçao e atribuiçao do valor encontrado para a variavel media
  double media = valorMedioG(valores);

  printf("O valor médio é: %.2f\n", media);

  return 0;
}
