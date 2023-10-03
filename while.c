#include <stdio.h>

int n = 15;

int main()
{
    while (n > 10){
        printf("n es %d y es mayor que 10", n);
        n = n - 1;
        printf("\n");
    }
    if (n == 10) 
    printf("n es igual 10\n", n);
    else
        printf("n es %d y es menor que 10", n);
        printf("\n");
    return 0;
    }