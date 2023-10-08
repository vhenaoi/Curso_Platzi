int main() {
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr; // ptr apunta al primer elemento del arreglo

// Avanzar el puntero y acceder a elementos del arreglo
printf("%d\n", *ptr); // Imprimirá 1
ptr++; // Mover el puntero al siguiente elemento
printf("%d\n", *ptr); // Imprimirá 2
}
