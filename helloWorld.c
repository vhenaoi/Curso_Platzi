#include <stdio.h>

int main()
{
    /*First hello world in C language
    printf("Hello Student");
    */
    printf("Hello, world!\n");
    return 0;
}

void main()
{
    /*Especifica que no hay valor disponible, se
    usa en 3 escenarios
            1. Función retorna tipo de datos void
                void funtion()
            2. Función tiene argumentos de tipo void
                int rand(void)
            3. Puntero o apuntador que va a la dirección en memoria 
            de un objeto, pero no le importa el tipo de dato que 
            tenga

    */
   return 0;
}

/*
Basic Types:
    Aritmeticos

    (A) Valores enteros
                    int 2 -32,768 to 32,767 
                    unsigned int 0 to 65,535  

                    int 4 -2,147,483,648 to 2,147,483,647
                    unsigned int 0 to 4,294,967,295

                    short 2 Bytes -32,768 to 32,767
                    unsigned short 2 Bytes 0 to 65,535

                    long 8 Bytes -9223372036854775808 to 9223372036854775807
                    unsigned long 0 to 18446744073709551615

    (B) De punto Flotante float

                    float 4 Bytes 1.2E-38 to 3.4E+38   6 decimal places
                    double 8 Bytes 2.3R-308 to 1.7E+308 15 decimal places
                    long double 10 Bytes 3.4E-4932 to 1.1E+4932 19 decimal places
*/