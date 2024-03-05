#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Declaração de Variáveis\n");
    char ch1; // declarando uma variável de tipo char
    ch1 = 'a'; // inicializando a variável
    char ch2 = 'b'; // declarando e inicializando
    char ch3 = 99; // declarando e inicializando
    printf("Tipo char\n");
    printf("char: %lu BYTES\n", sizeof(char));
    printf("CHAR_MIN= %d, CHAR_MAX= %d\n", CHAR_MIN, CHAR_MAX);
    printf("Modificadores\n");
    printf("unsigned char: %lu BYTES\n", sizeof(signed char));
    printf("UCHAR_MAX= %u\n", UCHAR_MAX);
    unsigned char uch1, uch2; // declarando múltiplas variáveis
    uch1 = uch2 = 100U; // inicializando múltiplas variáveis

    printf("Variáveis char: %c, %c, %c\n", ch1, ch2, ch3);
    printf("Variável char como caractere: %c\n", ch1);
    printf("Variável char como inteiro: %d\n", ch1);
    printf("Variáveis unsigned char: %c, %c\n", uch1, uch2);

    printf("Operações com char\n");
    char ch4 = ch3 + 2; // operação de adição
    printf("char ch4 = ch3 + 2: %c\n", ch4);
    int upper2lower = 'a' - 'A'; // operação de subtração
    printf("De minuscula para maiúscula: %c -> %c\n", 'a' , 'a' - upper2lower);
    printf("De maiúscula para minuscula: %c -> %c\n", 'A' , 'A' + upper2lower);
    printf("Os restantes operadores aritméticos também podem ser usados com char\n");
    printf("Operadores aritméticos: +, -, *, /, \%%\n");
    printf("Operadores relacionais: \n"); 
    printf("A < a : %d\n", 'A' < 'a');
    printf("B > A : %d\n", 'B' < 'A');
    printf("A == A : %d\n", 'A' == 'A');
    printf("A == a : %d\n", 'A' == 'a');
    printf("A != A : %d\n", 'A' != 'A');
    printf("A != a : %d\n", 'A' != 'a');
    printf("A <= A : %d\n", 'A' <= 'A');
    printf("A <= a : %d\n", 'A' <= 'a');
    printf("A >= A : %d\n", 'A' >= 'A');
    printf("A >= a : %d\n", 'A' >= 'a');
    printf("Operadores incremento e decremento:\n");
    printf("ch1: %c\n", ch1);
    printf("ch1++: %c\n", ch1++);
    printf("ch1: %c\n", ch1);
    printf("++ch1: %c\n", ++ch1);
    printf("ch1: %c\n", ch1);
    printf("Os operadores compostos também podem ser usados com char\n");
    printf("Operadores compostos: +=, -=, *=, /=, \%%=\n");

    printf("Operador condicional ou ternário:\n");
    printf("Transformando uma letra de minúscula em maiúscula\n");
    ch1 = 'a';
    ch2 = (ch1 >= 'a' && ch1 <= 'z') ? ch1 - upper2lower : ch1;
    printf("ch1: %c, ch2: %c\n", ch1, ch2);
    ch1 =  (ch2 >= 'a' && ch2 <= 'z') ? ch2 - upper2lower : ch2;
    printf("ch1: %c, ch2: %c\n", ch2, ch1);

    printf("Uma forma alternativa de usar este operador:\n");
    ((ch1 >= 'a') && (ch1 <= 'z')) ? printf("ch1 é uma letra minúscula\n"):printf("ch1 não é uma letra minúscula\n");
    ((ch1 >= 'A') && (ch1 <= 'Z')) ? printf("ch1 é uma letra maiúscula\n") : printf("ch1 não é uma letra maiúscula\n");   
    //ou
    ((ch1 >= 'a') && (ch1 <= 'z')) ? printf("ch1 é uma letra minúscula\n") :
        ((ch1 >= 'A') && (ch1 <= 'Z')) ? printf("ch1 é uma letra maiúscula\n") : printf("ch1 não é uma letra\n");
    return 0;
}




