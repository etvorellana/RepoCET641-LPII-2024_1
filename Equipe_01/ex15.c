#include <stdio.h>
#include "Biblioteca/lista_01.h"

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
