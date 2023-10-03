#include <stdio.h>

int n = 15;

int main()
{
    do
    {
        if (n == 10)
            printf("n es igual a 10\n");
        else
            printf("n es %d y es menor que 10\n", n);

        n = n - 1;
        printf("\n");
    } while (n > 10);

    printf("n es %d y es mayor que 10\n", n);

    return 0;
}