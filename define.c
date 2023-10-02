#include <stdio.h>

#define PIZZACOST 1.5
const newLine = '\n';

int main(){
    float costPizzas;
    float numberOfSlices = 3;
    costPizzas = PIZZACOST * numberOfSlices;

    printf("Total bill: %f", costPizzas);
    printf("%c", newLine);
    printf("Total bill: %.2f", costPizzas);
    printf("%c", newLine);
}