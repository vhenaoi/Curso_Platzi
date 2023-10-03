#include <stdio.h>

int opt0 = 0;
int opt1 = 0;
int opt2 = 0;

int main()
{
    // Este rpograma genera menus segun lo que el usuairo elija
    printf("Bienvenido a platzi store, elija una opción:\n");
    printf("0. Platzi bebidas \n");
    printf("1. Platzi comidas \n");
    printf("2. Platzi postres \n");
    if (opt0 == 0){
        printf("Usted eligio la opción 0, vera nuestro menú de bebidas elija una:\n");
        printf("0. Platzi cola cero \n");
        printf("1. Platzi cola con mucha azucar \n");
        printf("2. Platzi piña colada con azucar \n");
        if (opt2 == 0)
            printf("Usted eligio una platzi cola cero, mmm rico\n");
        else if (opt2 == 1)
            printf("Usted eligio una platzi cola con mucha azucar, estás bien?\n");
        else if (opt2 == 2)
            printf("Usted eligio una platzi piña colada con azucar, delicioso\n");
        else
            printf("Opcion invalida\n");
    }
    else if (opt0 == 1){
        printf("Usted eligio la opción 0, vera nuestro menú de comida elija una:\n");
        printf("0. Platzi perro \n");
        printf("1. Platzi hamburguesa \n");
        printf("2. Platzi pizza \n");
        if (opt2 == 0)
            printf("Usted eligio un platzi perro, mmm rico\n");
        else if (opt2 == 1)
            printf("Usted eligio una platzi hamburguesa, estás bien?\n");
        else if (opt2 == 2)
            printf("Usted eligio una platzi pizza, delicioso\n");
        else
            printf("Opcion invalida\n");
    }
    else if (opt0 == 2){
        printf("Usted eligio la opción 0, vera nuestro menú de postres elija una:\n");
        printf("0. Platzi torta \n");
        printf("1. Platzi helado \n");
        printf("2. Platzi alfajores \n");
        if (opt2 == 0)
            printf("Usted eligio una platzi torta, mmm rico\n");
        else if (opt2 == 1)
            printf("Usted eligio un platzi helado, estás bien?\n");
        else if (opt2 == 2)
            printf("Usted eligio unos platzi alfajores, delicioso\n");
        else
            printf("Opcion invalida\n");
    }
    else
        printf("Opcion invalida\n");

    
    return 0;
}