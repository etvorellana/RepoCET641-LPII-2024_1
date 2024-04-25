//útil para usar funçoes como printf e scanf, por exemplo
#include <stdio.h>

/*Faça uma implementação recursiva de uma função que, com base num array de tipo double,
modifique seus elementos para que cada um deles vire o inverso do valor original ( o inverso de x é 1x)*/

//Como a função não retorna nenhum valor, foi usado o void no início e não o double.
//No entanto, a função ainda aceita um vetor double, sendo o int tamanho e int indice os argumentos.
void inverterValor(double array[], int tamanho, int indice) {

  //usado para verificar se o tamanho do index é o mesmo ao tamanho do vetor, para que não haja erros.
  //Se todos os elementos tiverem sido processados, entao a funçao retorna sem fazer mais nada.
  if (indice == tamanho) {
    return;
  }

  //serve para inverter o elemento no indice atual do vetor, basicamente
  //divide 1 pelo valor do elemento atual e armazena o resultado no
  //vetor, por exemplo: se array[indice] = 2, entao seria 1/2 = 0.5
  array[indice] = 1.0 / array[indice];

  //uso do recursivo para chamar o prox elemento, o 1 serve para incrementar o indice e avançar para o proximo elemento
  //indice + 1 adiciona valor sem alterar o valor de indice em si, ao contrario de indice++, por exemplo
  inverterValor(array, tamanho, indice + 1);

}

//funcao principal
int main(void) {
  //usado para declarar uma array de numeros tipo double e definir os valores
  double array[] = {1.0, 2.0, 3.0, 4.0, 5.0};

  //o calculo e usado para dividir o tamanho total pelo de um elemento dentro da array,
  //resultando no total de numeros na array
  int tamanho = sizeof(array) / sizeof(array[0]);

  //chama a funcao criada para inverter os elementos da array, tamanho indicando o
  //numero total de elementos e o indice sendo 0 para começar desde o primeiro elemento na array
  inverterValor(array, tamanho, 0);

  //imprimir na tela
  printf("Invertido:\n");
  //o for e usado para percorrer a array e imprimir cada elemento
  for (int i = 0; i < tamanho; i++)
    printf("%.4f ", array[i]);

  printf("\n");

  return 0;
}
