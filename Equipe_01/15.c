#include <stdio.h>

/*Faça uma implementação recursiva de uma função que, com base num array de tipo double,
modifique seus elementos para que cada um deles vire o inverso do valor original ( o inverso de x é 1x)*/

//Como a função não retorna nenhum valor, foi usado o void no início e não o double.

void inverterValor(double array[], int tamanho) {

  if (tamanho == 0) {
    return;
  }


  array[tamanho - 1] = 1.0 / array[tamanho -1];

  inverterValor(array, tamanho - 1);

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
  inverterValor(array, tamanho);

  //imprimir na tela
  printf("Invertido:\n");
  //o for e usado para percorrer a array e imprimir cada elemento
  for (int i = 0; i < tamanho; i++)
    printf("%.2lf ", array[i]);

  printf("\n");

  return 0;
}