#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;    // ch é uma variável de tipo char
    char* pch;  // pch é um ponteiro para char
    int a;      // a é uma variável de tipo int
    int* pa;    // pa é um ponteiro para int
    //x é uma variável de tipo double e px é um ponteiro para double
    double *px, x; 

    // Podemos fazer os ponteiros apontarem para as variáveis
    pch = &ch;
    ch = 'a';
    printf("ch = %c\n", ch);
    // para acessar o valor apontado por um ponteiro, usamos o operador *
    printf("pch é um ponteiro que referencia (aponta para) o endereço: %p\n", pch);
    printf("O conteúdo do endereço apontado por pch é: %c\n", *pch);

    // podemos usar o endereço de memória para atribuir um valor à variável
    px = &x;
    *px = 3.14;
    printf("px é um ponteiro que referencia (aponta para) o endereço: %p\n", px);
    printf("O conteúdo do endereço apontado por px é: %f\n", *px);
    printf("O valor de x é: %f\n", x);

    // Já usamos o endereço das variáveis pem funções com passagem por referência
    pa = &a;
    printf("Digite um valor para a: ");
    scanf("%d", pa);
    printf("O valor de a é: %d\n", a);
    return 0;

}