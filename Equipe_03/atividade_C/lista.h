#define N10 5

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//verificar se é numero
int verificar()
{
    int numero;
    char letra[20];
    
    while (1)
    {
        fgets(letra, sizeof(letra), stdin);

        int i = 0;
        
        while(letra[i] != '\n')
        {

         if (!isdigit(letra[i]))
         {
            printf("ERRO\nDigite um número: ");
            break;
         }
         i++;
        
        }

        if (letra[i] == '\n')
        {
            numero = atoi(letra);
            break;
        }
    }
    return numero;
}




//------------------------------------------------------
//Funçoes da questão 1

//imprime um menu

void menu()
{

    printf("\n");
    printf("1 -> Quadrado Completo\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("2 -> Quadrado vazado\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i == 0 || i == 2)&&(j == 0 || j == 2))
            {
                printf("*");
            }
            else if (i == 0 || i == 2 || j == 0 || j == 2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


//Desenhar quadrado

int desenhaQuadrado(int tamanho, int vazado)
{
    if ( vazado == 1) // imprime o quadrado completo
    {
        for (int i = 0; i < tamanho; i++)
        {
          for (int j = 0; j < tamanho; j++)
          {
            printf("*");
          }
          printf("\n");
        }
    }
    else if (vazado == 2) //imprime o quadrado vazado
    {
       for (int i = 0; i < tamanho; i++)
       {
         for (int j = 0; j < tamanho; j++)
         {  
            if ((i == 0 || i == tamanho -1) && (j == 0 || j == tamanho - 1)) //preenche as bordas
            {
                printf("*");
            }
            else if ((i == 0 || i == tamanho -1 || j == 0 || j == tamanho - 1)) //preenche os cantos
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
         }
         
         printf("\n");
       } 
    }
    
}







//------------------------------------------------------
//Funçoes da questão 2


int desenhaTriangulo(int t, int tp)
{
    int linha = 0, alinha = 0;
    if (t < 1 || 20 < t)
        return 1;
    if (tp < 1 || 4 < tp)
        return 2;

    if (t == 1)
        printf("*\n");

    for (int i = 1; i <= t; i++)
    {
        if (tp == 1)
            for (int j = 1; j <= i; j++)
                printf("*");
        else if (tp == 2)
            for (int j = t - i; j >= 0; j--)
                printf("*");
        else if (tp == 3)
        {
            if (i > 1)
            {
                linha++;
                while (alinha < linha)
                {
                    printf(" ");
                    alinha++;
                }
            }

            for (int j = t - i; j >= 0; j--)
                printf("*");
            alinha = 0;
        }
        else if (tp == 4)
        {
            for (int j = t - i; j >= 1; j--)
                printf(" ");
            for (int j = 1; j <= i; j++)
                printf("*");
        }
        printf("\n");
    }

    return 0;
}

//------------------------------------------------------






//------------------------------------------------------
//Funçoes da questão 3

int desenhaPiramide(int tamanho, int tipo){
	int i, j, k, aux;
	if(tamanho > 20 || tamanho < 1)
		return 1;
	if(tipo < 0 || tipo > 1)
		return 2;
	if(tipo == 1){
		for(i = 0; i < tamanho; i++){
			for(j = 0; j < tamanho - i; j++){
				printf(" ");
			}
			for(j = 0; j < i ; j ++){
				printf("*");
			}
			for(k = 0; k <= i; k++){
				printf("*");
			}
			printf("\n");
		}
	}
	if(tipo == 0){	
		for(i = 0; i <= tamanho; i++){
    		for(j = 0; j < tamanho - i; j++){
        		printf("*");
    		}
    		for(j = 0; j <= tamanho - i; j++){
    			printf("*");
			}
    	printf("\n");
    		for(j = 0; j <= i; j++){
        printf(" ");
    		}
		}
	}		
}	

//------------------------------------------------------





//------------------------------------------------------
//Funçoes da questão 4


int desenhaTabuleiro(int tamanho){
	int i, j, k, aux;
	if(tamanho < 2 || tamanho > 8)
		return 1;
	for(aux = 0; aux < tamanho; aux ++){
		if(aux % 2 == 0){
			for(i = 0; i < 5; i++){
				for(j = 0; j < tamanho; j++){
					if(j % 2 == 0){
						for(k = 0; k < 5; k++){
							printf("  ");
						}
					}else{
						for(k = 0; k < 5; k++){
							printf("* ");
						}
					}
				}
			printf("\n");
		}
	}else{
		for(i = 0; i < 5; i++){
			for(j = 0; j < tamanho; j++){
				if(j % 2 == 0){
					for(k = 0; k < 5; k++){
						printf("* ");
					}
				}else{
					for(k = 0; k < 5; k++){
						printf("  ");
					}
				}
			}
		printf("\n");
		}
	}	
}
}


//------------------------------------------------------






//------------------------------------------------------
//Funçoes da questão 5 e parte da 6

int desenhaLinha(int tamanho, char linha[]) {
  if (tamanho < 1 || tamanho > 20)
    return 1;

  for (int i = 0; i < tamanho; i++)
    linha[i] = '*';

  linha[tamanho] = '\0';

  return 0;
}

//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 6

int desenhaTriangulo2(int tamanho, int tipo)
{
    if (tamanho < 1 || tamanho > 20)
        return 1;
    if (tipo < 1 || tipo > 4)
        return 2;

    char linha[21];
  
    for (int i = 1; i <= tamanho; i++)
    {
        if (tipo == 1)
            desenhaLinha(i, linha);
        else if (tipo == 2)
            desenhaLinha(tamanho - i + 1, linha);
        else if (tipo == 3)
        {
            desenhaLinha(tamanho - i + 1, linha);
            printf("%*s", i - 1, ""); // Imprime espaços
        }
        else if (tipo == 4)
        {
            printf("%*s", tamanho - i, ""); // Imprime espaços
            desenhaLinha(i, linha);
        }
        printf("%s\n", linha);
    }

    return 0;
}

//------------------------------------------------------




//------------------------------------------------------
//Funçoes da questão 7

int desenhaLinha_Triangulo(int tamanho, char linha[]){
	linha[tamanho] = '*';
	if(tamanho == 0)
		return 1;
	printf("%c", linha[tamanho]);
	desenhaLinha_Triangulo(tamanho - 1, linha);
}

int desenhaTrianguloRec(int tamanho, int tipo){
	int i, j;
	char linha[tamanho];
	//tipo 1 
	if(tipo == 1){
		for(i = 0; i <= tamanho; i++){
			desenhaLinha_Triangulo(i, linha);
			printf("\n");
		}
	}
	//tipo 2
	if(tipo == 2){
		for(i = 0; i <= tamanho; i++){
			desenhaLinha_Triangulo(tamanho - i, linha);
			printf("\n");
		}
	}
	//tipo 3
	if(tipo == 3){
		for(i = 0; i < tamanho; i++){
			for(j = 0; j < i; j++){
				printf(" ");
			}			
			desenhaLinha_Triangulo(tamanho - i, linha);
			printf("\n");
		}
	}
	//tipo 4
	if(tipo == 4){
		for(i = 0; i < tamanho; i++){
			for(j = 0; j < tamanho - i; j++){
				printf(" ");
			}			
			desenhaLinha_Triangulo(i + 1, linha);
			printf("\n");
		}
	}		
}

//---------------------------------------------------


//------------------------------------------------------
//Funçoes da questão 8
double valorMedioG(double x[], int N) {
  double soma = 0.0;

  for (int i = 0; i < N; i++) {
    soma += x[i]; // soma todos os elementos do array
  }

  return soma / N; // valor médio
}


//------------------------------------------------------



//Funçoes da questão 9

// Função para calcular o desvio padrão

double desvioPadraoG(double x[], int N) {
  double media =
      valorMedioG(x, N); // Calcula o valor médio usando a função anterior
  double somaDesvios = 0.0;

  // Calcula a soma dos quadrados dos desvios
  for (int i = 0; i < N; i++) {
    somaDesvios += pow(x[i] - media, 2);
  }

  // Calcula e retorna o desvio padrão
  return sqrt(somaDesvios / N);
}

//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 10

double valorMedio10(double x[]){
	double media;
	int i;
	for(i = 0; i < N10; i++){
		media = media + x[i];
	}
	return (media / N10);
}

void normaliza(double x_inout[]){
	int i = 0;
	double media = valorMedio10(x_inout);
	for(i = 0; i < N10; i++){
		x_inout[i] = x_inout[i] - media;
		printf("%lf\n", x_inout[i]);
	}
}

//------------------------------------------------------




//------------------------------------------------------
//Funçoes da questão 11

double media (int i ,int indice, double numero[])
{
  if (i <= indice)
  {
    return numero[0] + media(i + 1, indice, numero + 1);
  }
  else if (i == indice)
  {
    return 1;
  }
}

//------------------------------------------------------


//------------------------------------------------------
//Funçoes da questão 12 e parte da 13

double valorMedio(double x[], int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += x[i];

    return s / n;
}


//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 13

double desvioPadrao(double x[], int n)
{
    double m = valorMedio(x, n);
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += pow(x[i] - m, 2);

    return sqrt(s / n);
}

//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 14


double valorMedioDa14(double x[], int N){
	double media;
	int i;
	for(i = 0; i < N; i++){
		media = media + x[i];
	}
	return (media / N);
}

void normalizando(double x_inout[], int N){
	int i = 0;
	double media = valorMedioDa14(x_inout, N);
	for(i = 0; i < N; i++){
		x_inout[i] = x_inout[i] - media;
		printf("%lf\n", x_inout[i]);
	}
}

//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 15

double inverte (double numero[],int n, int inicio)
{
    if(n == 0)
    {
        return 0;
    }
    numero [inicio] = 1.0 / numero[inicio]; 
    
    return inverte (numero, n - 1, inicio+1);
    
}
//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 16
void inverteFrase(char frase[]) {
    if (strlen(frase) == 0) {
        return; 
    } else {
        inverteFrase(frase + 1); 
        printf("%c", frase[0]);
    }
}
//----------------------------------------------------


//------------------------------------------------------
//Funçoes da questão 17


int encontra (int numero[], int cont, int numeros)
{

    if (numero[cont] == -1)
    {
        return numeros;
    }
    
    if (numero[cont] > numeros)
    {
        numeros = numero[cont];
    }
    
    return encontra(numero, cont +1, numeros);
}

//------------------------------------------------------



//------------------------------------------------------
//Funçoes da questão 18

int contarCaracteresA(char fras[], int indice) {
    if (fras[indice] == '\0') {
        return 0; 
    }

    char currentChar = fras[indice];
    if (currentChar == 'a' || currentChar == 'A') {
        return 1 + contarCaracteresA(fras, indice + 1);
    } else {
        return contarCaracteresA(fras, indice + 1);
    }
}

//------------------------------------------------------
