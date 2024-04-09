/*
Leia um valor inteiro, que representa o tempo de duração, em segundos, 
de um determinado evento, e retorne no formato horas:minutos:segundos.
*/

#include <stdio.h>

int main(void) {
  int tempo, horas, minutos, segundos;

  printf("Digite o tempo em segundos: ");
  scanf("%d", &tempo);

  horas = tempo / 3600;
  minutos = (tempo % 3600) / 60;
  segundos = (tempo % 3600) % 60;

  printf("O evento durou %d:%d:%d\n", horas, minutos, segundos);

  return 0;
}