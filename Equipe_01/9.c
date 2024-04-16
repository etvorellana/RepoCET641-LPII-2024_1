#include <stdio.h>
//neste caso, math.h e usado para o uso da funcao pow e sqrt
#include <math.h>

//declaracao da variavel global N, para armazenar o tamanho da array, como solicitado
int N;

//calcula o valor medio dos elementos de uma array de tipo double
double valorMedioG(double x[]) {
  double soma = 0.0;

  //loop usado para somar todos os elementos da array e atribuir o valor a soma
  for (int i = 0; i < N; i++)
    soma += x[i];

  //formula da media
  double media = soma / N;

  //retorna o valor calculado pela funcao
  return media;
}

//funcao que vai calcular o desvio padrao
double desvioPadraoG(double x[]) {
  //usado para chamar a funcao acima e calcular a media
  //armazenando na variavel media
  double media = valorMedioG(x);

  double somadosquad = 0.0;

  //percorre os valores na array e calcula o quadrado da diferenca
  //entre cada elemento e a media, somando-os a variavel
  for (int i = 0; i < N; i++)
    somadosquad += pow(x[i] - media, 2);

  //calcula-se a variancia ao dividir a soma dos quadrados das
  //diferenças pela quantidade de elementos N
  double var = somadosquad / N;
  //o desvio padrao seria a raiz quadrada do valor contido em var
  double desvioPadrao = sqrt(var);

  //retorna o valor calculado
  return desvioPadrao;
}

int main(void) {
  //definicao de uma array chamada valores com numeros do tipo double
  double valores[] = {2.5, 4.5, 6.5, 8.5, 10.5};

  //serve para calcular o tamanho da array
  N = sizeof(valores) / sizeof(valores[0]);

  //chama a funcao de desvioPadrao para calcular o desvio
  //dos elementos da array valores, como foi dito no argumento
  double desvio = desvioPadraoG(valores);

  //imprime o valor encontrado acima
  printf("Desvio Padrão: %.2f\n", desvio);

  return 0;
}
