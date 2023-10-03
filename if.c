#include <stdio.h>

int n = 21;

int main()
{
    if (n > 10 && n < 20){
        printf("%d es mayor que 10", n);
        printf("\n");
    }
    else if (n == 10){
        printf("El número es 10");
        printf("\n");
    }
    else if (n > 20)
        printf("%d es mayor que 20", n);
    else if (n < 10)
        printf("El número es menor que 10");
    else
        printf("Error no hay npumero");  
        printf("\n");
    return 0;
    }