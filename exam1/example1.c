void modificarValor(int *ptr) {
    *ptr = 10;
}

int main() {
    int num = 5;
    modificarValor(&num);
    printf("El nuevo valor de num es: %d\n", num); // Imprimirá "El nuevo valor de num es: 10"
    return 0;
}

