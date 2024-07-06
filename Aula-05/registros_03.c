#include <stdio.h>

typedef struct{
    double* A;
    double** mA;
    int nLin;
    int nCol;
}tMatrix;

tMatrix createMatrix(int nLin, int nCol)
{
    tMatrix matrix;
    matrix.A = (double *) malloc(nLin*nCol*sizeof(double));
    matrix.mA = (double **) malloc(nLin*sizeof(double*));
    for(int i = 0; i < nLin; i++)
        matrix.mA[i] = matrix.A + i*nCol;
        //matrix.mA[i] = &matrix.A[i*nCol];
    matrix.nLin = nLin;
    matrix.nCol = nCol;
    return matrix;
}

void desalocaMatrix(tMatrix* matrix)
{
    free(matrix->A);
    free(matrix->mA);
    matrix->A = NULL;
    matrix->mA = NULL;
    matrix->nLin = 0;
    matrix->nCol = 0;
}   
 

int main(void)
{
    tMatrix M = createMatrix(3, 4);
    int i = 1, j = 2;
    M.A[i*M.nCol + j] = 10.0;
    M.mA[i][j] = 20.0;
    return 0;
}