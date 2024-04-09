
#include <string.h>

void ajustaFGetsString(char *str)
{
    int i = strlen(str) - 1;
    if (str[i] == '\n')
        str[i] = '\0';
}

