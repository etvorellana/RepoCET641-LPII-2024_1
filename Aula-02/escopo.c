
#include <stdio.h>
#include <stdlib.h>
/**
 * Suponha que temos uma serie de dados numéricos, de ponto flutuante,
 * armazenados num array de 1024 elementos. Para analisar e processar 
 * os dados precisamos:
 * 1- Calcular a média e o desvio padrão da serie;
 * 2- O valor máximo e mínio
 * 3- Normalizar a serie para uma nova com valores entre 0 e 1;
 * 4- Normalizar novamente para virar uma serie com média 0;
 * Por onde começar
 */

void geradorDeSinais(double x[], int n);
double media(double x[], int n);
double maxmin(double x[], int n, int isMax);
void maxminRetorno(double x[], int n, int *min, int *max);
void maxminRetorno2(double x[], int n, double *min, double *max);
double maxminRetorno3(double x[], int n, double *min);
void escalaArray(double x[], int n);
void normaliza(double x[], int n);

int main(void)
{
    double sinal[1024];
    geradorDeSinais(sinal, 1024);
    escalaArray(sinal, 1024);
    normaliza(sinal, 1024);
    double xMedia, xMin, xMax;
    xMedia = media(sinal, 1024);
    printf("media = %.2f\n", xMedia);
    maxminRetorno2(sinal, 1024, &xMin, &xMax);
    printf("min = %.2f, max = %.df \n", xMin, xMax );
    xMin = maxmin(sinal, 1024, 0);
    xMax = maxmin(sinal, 1024, 1);
    printf("min = %.2f, max = %.df \n", xMin, xMax );
    xMax = maxminRetorno3(sinal, 1024, &xMin);
    printf("min = %.2f, max = %.df \n", xMin, xMax );
    int iMin, iMax;
    maxminRetorno(sinal, 1024, &iMin, &iMax);
    xMin = sinal[iMin];
    xMax = sinal[iMax];
    printf("min = %.2f, max = %.df \n", xMin, xMax );
    return;
}

void geradorDeSinais(double x[], int n)
{
    for(int i = 0; i < n; i++)
        x[i] = 25.0 + (((double) rand()) / RAND_MAX)*10;
    return;
}

