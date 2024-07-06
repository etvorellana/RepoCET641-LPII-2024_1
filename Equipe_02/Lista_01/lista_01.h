#ifndef LISTA_01_H
#define LISTA_01_H

#include <math.h>
#include <string.h>

int N;

int desenhaQuadrado(int tamanho, int vazado);
int desenhaTriangulo(int tamanho, int tipo);
int desenhaPiramide(int tamanho, int tipo);
int desenhaTabuleiro(int tamanho);

int desenhaLinha(int tamanho, char linha[]);
int desenhaLinhaR(int tamanho, char linha[]);

double valorMedio(double x[]);
double desvioPadraoG(double x[ ]);
void normaliza(double x_inout[ ]);

double valorMedioN(double x[], int n);
double desvioPadraoN(double x[ ], int n);
void normalizaN(double x_inout[ ], int n);

double valorMedioArr(double x[], int N);
void inversor(double arr[], int n);
void escreveCon(char *c);
int palindromo(char *c, int n, int i);
int maiorNumero(int arr[], int n);
int repeteC(char *c);

int quantidadeA(char x[],int n);

#endif // LISTA_01_H
