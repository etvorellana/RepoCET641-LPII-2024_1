#include <stdio.h>
#include <stdlib.h>
#include "..//lista.h"

double inverte (double numero[], int n, int inicio);

int main(int argc, char const *argv[])
{
    double number [2] = {4.0,5.0};
    
    inverte(number, 2,0);

    for (int i = 0; i< 2; i++)
    {
        printf("%.2lf\n", number[i]);
    }
    return 0;
}