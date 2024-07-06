#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int numMat;
    char email[50];
}TAluno;

struct SAluno{
    char nome[50];
    int numMat;
    char email[50];
    struct sAluno *prox;
};

typedef struct SAluno TSAluno;
typedef TSAluno *PTAluno;
void printLista(PTAluno lista);

PTAluno alocaAluno();
PTAluno iniAluno(char* nome, int matric, char* email);

int main(void)
{
    PTAluno listaHead = NULL;
    // Criando um aluno
    PTAluno aluno = iniALuno("Esbel", 202311234, "esbel@uesc.br");
    listaHead = aluno;
    printLista(listaHead);
    return 0;
}

PTAluno alocaAluno()
{
    PTAluno aluno = (PTAluno) malloc(sizeof(TSAluno));
    return aluno;
}

PTAluno iniAluno(char* nome, int matric, char* email)
{
    PTAluno aluno = alocaAluno();
    aluno->numMat = matric;
    strcpy(aluno->nome, nome);
    strcpy(aluno->email, email);
    aluno->prox = NULL;
    return aluno;
}

void printLista(PTAluno lista)
{
    PTAluno p = lista;
    while(p != NULL)
    {
        printf("Nome: %s\n", p->nome);
        printf("Matricula: %d\n", p->numMat);
        printf("Email: %s\n", p->email);
        p = p->prox;
    }
}