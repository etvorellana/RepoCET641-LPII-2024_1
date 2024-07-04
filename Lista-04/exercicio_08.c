/*
    Exercício 8.
    A seguinte expressão gera um valor de ponto flutuante de precisão simples entre 
    0 e 10: ((float)rand() / RAND_MAX) * 10. Implemente a seguinte função:
    float* geraNotas(int qAlunos): que retorna um array de valores de ponto flutuante 
    representando as notas dos alunos de uma turma. As notas são geradas de forma 
    aleatória e a quantidade de alunos na turma é especificada pelo parâmetro qAlunos.
*/

#include <stdio.h>
#include <stdlib.h>

float* geraNotas(int qAlunos);

int main(void)
{
    printf("Exercício 8.\n");
    float* notas;
    notas = geraNotas(10);
    if (notas)
    {
        printf("Notas geradas:\n");
        for(int i = 0; i < 10; i++)
            printf("Nota %d: %.2f\n", i + 1, notas[i]);
        free(notas);
    }
    return 0;
}

float* geraNotas(int qAlunos)
{
    if(qAlunos < 1)
        return NULL;
    float* notas = (float*) malloc(qAlunos * sizeof(float));
    for(int i = 0; i < qAlunos; i++)
        notas[i] = ((float)rand() / RAND_MAX) * 10;
    return notas;
}