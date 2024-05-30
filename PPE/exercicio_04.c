#include <stdio.h>

int quantLetras(char str[ ]);
int quantLetrasR(char str[ ]);

int main(void)
{
    char str[] = "123+=-agiu123+=-desproporcionadamente123+=-";
    printf("Quantidade de letras: %d\n", quantLetras(str));
    printf("Quantidade de letras: %d\n", quantLetrasR(str));
    return 0;
}

int quantLetras(char str[ ])
{
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++)
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            cont++;

    return cont;
}

int quantLetrasR(char str[ ])
{
    if(str[0] == '\0')
        return 0;
    if((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
        return 1 + quantLetrasR(&str[1]);
    return quantLetrasR(str+1);
}