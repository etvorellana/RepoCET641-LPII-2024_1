#include <stdio.h>
#include <string.h>

struct aluno
{
    char nome[50];
    int matricula;
    char email[50];
};

typedef struct aluno tAluno;

int main(void)
{
    tAluno aluno1, turma[5];
    char nome[50] = "Aluno          ";
    for(int i = 0; i < 5; i++)
    {
        aluno1.matricula = 20210000 + i;
        nome[8] = 'a' + i;
        strcpy(aluno1.nome, nome);
        strcpy(aluno1.email, aluno1.nome);
        strcat(aluno1.email, "@uesc.br");
        turma[i] = aluno1;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Aluno: %s\n", turma[i].nome);
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Email: %s\n", turma[i].email);
    } // end for

    if (aluno1.matricula == turma[4].matricula)
        printf("Aluno1 e turma[4] são iguais\n");
    else
        printf("Aluno1 e turma[4] são diferentes\n");

    return 0;
}