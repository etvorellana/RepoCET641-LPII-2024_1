#include <stdio.h>

int quantParesR(int x[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (x[n-1] % 2 == 0 ? 0 : 1) + quantParesR(x, n-1);
    }
}

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};


} 