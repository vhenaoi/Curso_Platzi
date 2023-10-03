#include <stdio.h>

// Variable Declarations
int a, b, c;
float f, g, h; 

int main()
{
    // Variable initialization
    g = 1000.999999;
    f = 1.111111; // Se desbordo

    h = g + f;
    printf("Value of sum is: %f", h);
    return 0;
}