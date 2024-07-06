
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double *alocaMatriz1d(const int n, const int m);
void preencher (double *mat,int n, int m, FILE *fp);
int consultaint(FILE *fp);
double consultadouble(FILE *fp);
void todalogica(double* mataux,double* mataa,double* matb, int lx,int cx,int la,double alpha );
void multiplicacaovetorial(double *mat,double coeficiente,int l, int C);
void soma(double *mat1, double *mat2, int l,int c);
void printar(double *mat, long int quant, char* mensagem);
void trancrever(double *mat, int l, int c);
double menorvalor(double *ma, int linha, int coluna);

int main(void)
{
  int linha, coluna, linhaaux, colunaaux;
  double alpha, beta;
  double *matA, *matB, *matC, *matAux;
  int colunaA, linhaC, colunaC; 

  FILE *fp = fopen("gemmMatrixEq4.bin", "rb");
  if(fp==NULL){
    printf("DEU ERROOOOOO\n");
    exit(1);

  }


  alpha=consultadouble(fp);
  printf("valor de alpha %f\n", alpha);

  linhaaux=linha=consultaint(fp);

  printf("valor da linha de A %d\n", linha);

  colunaA= coluna=consultaint(fp);
  printf("valor da coluna de A %d\n", coluna);

  matA = alocaMatriz1d(linha, coluna);

  preencher(matA, linha, coluna, fp);

  printar(matA, 100, "valor de A");

  linha=consultaint(fp);

  printf("valor da linha de B %d\n", linha);

  colunaaux=coluna=consultaint(fp);
  printf("valor da coluna de B %d\n", coluna);

  matB = alocaMatriz1d(linha, coluna);
  preencher(matB, linha, coluna, fp);

  printar(matB, 100, "valor de B");

  beta=consultadouble(fp);

  printf("valor de beta %f\n", beta);

  linhaC=linha=consultaint(fp);
  printf("valor da linha de C %d\n", linha);

  colunaC=coluna=consultaint(fp);
  printf("valor da coluna de C %d\n", coluna);


  matC=alocaMatriz1d(linha, coluna);

  preencher(matC, linha, coluna, fp);
  printar(matC, 100, "valor de C");

  printf("auxlinha %d, auxcoluna %d \n",linhaaux, colunaaux);


  matAux =(double *)calloc(colunaaux*linhaaux,sizeof(double));  

  todalogica(matAux, matA, matB, linhaaux, colunaaux, colunaA, alpha);

  printar(matAux, 100, "valor de Aux");

  multiplicacaovetorial(matC, beta, linhaC, colunaC);

  printar(matC, 100, "valor de C");

  soma(matC, matAux, linhaaux, colunaaux);


  printar(matC, 100, "valor de C final");

  printf("C[n-8][0]=%lf, C[n - 8][7]=%lf, C[n-1][0],=%lf, C[n-1][7]=%lf,", matC[linhaC-8], matC[linhaC-8+7*linhaC],matC[linhaC-1],matC[linhaC-1+7*linhaC]);

  printf("menor valor de C %f\n", menorvalor(matC, linhaC, colunaC));

  fclose(fp);

  trancrever(matC, linhaC, colunaC);


  free(matA);
  free(matB);
  free(matC);
  free(matAux);

  return 0;
}

double *alocaMatriz1d(const int n, const int m)
{
  double *mat;
  mat =(double*) malloc(n*m*sizeof(double));

  return mat;
}



void preencher (double *mat, int n, int m, FILE *fp){


  for(long int i=0;i<n*m;i++){

    fread(&mat[i], sizeof(double), 1, fp);
  }

}



int consultaint(FILE *fp){
  int valor;
  fread(&valor, sizeof(int), 1, fp);
  return valor;

}

double consultadouble(FILE *fp){
  double valor;
  fread(&valor, sizeof(double), 1, fp);
  return valor;
}


void todalogica(double* mataux,double* mataa,double* matb, int lx,int cx,int cl,double alpha ){
  for(long int j =0;j<cx;j++){
    for(long int i =0;i<lx;i++){
      for(long int k = 0; k< cl; k++){
        mataux[j * lx + i] += mataa[j * cl + k] * matb[k * lx + i];
      }
      mataux[j*lx+i]=alpha* mataux[j*lx+i];
    }
  }
}

void multiplicacaovetorial(double *mat,double coeficiente,int l, int C){
  for(long int i =0;i<l*C;i++){
    mat[i]=coeficiente* mat[i];

  }
}

void soma(double *mat1, double *mat2, int l,int c){
  for(long int i =0;i<l*c;i++){
    mat1[i]+=mat2[i];
  }
}



double menorvalor(double *ma, int linha, int coluna){
  double menor=ma[0];
  for(int i=0;i<linha;i++){
    if(menor>ma[i*coluna])
      menor=ma[i*coluna];
  }
  return menor;
}


void printar(double *mat,long int quant, char* mensagem){
  for(long int i = 0; i<quant;i++){
    printf("%s %f\n", mensagem, mat[i]);
  }
}

void trancrever(double *mat, int l, int c){

  FILE *fp=  fopen("saida.log", "w");

  if(fp==NULL){
    printf("DEU ERROOOOOO\n");
    exit(1);

  }


  for(long int i = 0; i<c*l;i++){
    fprintf(fp, "  %f  ", mat[i]);

  }

  fclose(fp);


}
