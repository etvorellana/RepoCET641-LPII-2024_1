#include <stdio.h>
#include "..//lista.h"


int main(void) {
  double number[5] = {2.5, 0.0, 0.0, 0.0, 0.0};

  media(0,5, number);
  
  printf("Media%.2lf\n", (media(0,5, number)) / 5);
  return 0;
}
