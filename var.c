#include <stdio.h>

// Variable Declarations
int a, b, c;
float f, g, h; 

int main()
{
    // Variable initialization
    a = 10;
    b = 2147483647; // Se desbordo

    c = a + b;
    printf("Value of sum is: %d", c);
    return 0;
}