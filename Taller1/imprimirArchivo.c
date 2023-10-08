// gcc -Wall -Wextra -g3 -std=c99 imprimirArchivo.c -o imprimirArchivo.exe
// ./imprimirArchivo.exe

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nombre_archivo_binario>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s.\n", filename);
        return 1;
    }

    // Leer el encabezado del archivo
    uint16_t magic_string;
    uint32_t student_count, course_count, enrollment_count;

    fread(&magic_string, sizeof(magic_string), 1, file);
    fread(&student_count, sizeof(student_count), 1, file);
    fread(&course_count, sizeof(course_count), 1, file);
    fread(&enrollment_count, sizeof(enrollment_count), 1, file);

    printf("Magic String: 0x%04X\n", magic_string);
    printf("Número de Estudiantes: %u\n", student_count);
    printf("Número de Cursos: %u\n", course_count);
    printf("Número de Matrículas: %u\n", enrollment_count);

    // Leer y mostrar los registros de estudiantes
    for (uint32_t i = 0; i < student_count; i++) {
        uint32_t student_id;
        uint8_t flags;
        char student_name[23];
        uint32_t age;

        fread(&student_id, sizeof(student_id), 1, file);
        fread(&flags, sizeof(flags), 1, file);
        fread(student_name, sizeof(student_name), 1, file);
        fread(&age, sizeof(age), 1, file);

        student_name[23] = '\0';  // Agrega el terminador nulo al final

        printf("Registro %u:\n", i + 1);
        printf("ID del Estudiante: %u\n", student_id);
        printf("Genero: %s\n", (flags & 0x01) ? "Femenino" : "Masculino");
        printf("Nombre del Estudiante: %s\n", student_name);
        printf("Edad del Estudiante: %u\n", age);
        printf("\n");
    }

    fclose(file);

    return 0;
}





