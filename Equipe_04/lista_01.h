

#ifndef LISTA_H
#define LISTA_H


int desenhaQuadrado(int tam, int vaz);
int desenhaTriangulo(int tam, int tipo);
int desenhaPiramide(int tam, int tipo);
int desenhaTabuleiro(int tam);
int desenhaLinha(int tamanho, char linha[]);
int desenhaTriangulo1(int tamanho, int tipo);
int desenhaLinhaR(int tamanho, char linha[]);
double valorMedioG(double x[ ]);
void preencherLR(double lista[], int n);
double desvioPadraoG(double x[]);
void normaliza(double x_inout[]);
double soma_recursiva(double vetor[], int tamanho);
double calculo_media(double vetor[], int tamanho);
void inversor(double lista[], int n);
void inverter_string(char str[], int inicio, int fim);
int verificar_palindromo(char str[], int inicio, int fim);
int maior_valor(int vetor[], int tam, int indice);
int quantidade(char str[], int inicio, int fim);



#endif