// TAREA 1
// Implementa un programa en C que lea el archivo binario e imprima los nombres, 
//edades y géneros de todos los estudiantes dentro de un rango de edades.

// CORRER ESTAS LINEAS EN LA TERMINAL

// gcc -Wall -Wextra -g3 -std=c99 Veronica_Henao_tarea1.c -o Veronica_Henao_tarea1.exe
// ./Veronica_Henao_tarea1.exe sample_data.bin 18 25

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1)  // Establece el alineamiento en 1 byte
// Estructura para el encabezado del archivo
typedef struct {
    uint16_t magic;
    uint32_t student_count;
    uint32_t course_count;
    uint32_t enrollment_count;
} Header;
#pragma pack()  // Restablece el alineamiento por defecto

#pragma pack(1)  // Establece el alineamiento en 1 byte
typedef struct {
    uint32_t student_id;
    uint8_t flags;
    char name[23];
    uint32_t age;
} StudentRecord;
#pragma pack()  // Restablece el alineamiento por defecto

// Función para leer el encabezado del archivo
int readHeader(FILE *file, Header *header) {
    return fread(header, sizeof(Header), 1, file);
}

// Función para leer un registro de estudiante
int readStudentRecord(FILE *file, StudentRecord *student) {
    return fread(student, sizeof(StudentRecord), 1, file);
}


int main(int argc, char *argv[]) {
    uint32_t i;

    if (argc != 4) {
        printf("Usage: %s <binary_file> <age_min> <age_max>\n", argv[0]);
        return 1;
    }

    const char *binary_file = argv[1];
    uint32_t age_min = atoi(argv[2]);
    uint32_t age_max = atoi(argv[3]);

    if (age_min >= age_max) {
        printf("Error: age_min debe ser menor que age_max.\n");
        return 1; // Salir del programa con un código de error
    }

    FILE *file = fopen(binary_file, "rb");
    if (file == NULL) {
        printf("File '%s' does not exist.\n", binary_file);
        return 1;
    }

    Header header;

    if (readHeader(file, &header) != 1) {
        printf("Error reading file header.\n");
        fclose(file);
        return 1;
        }

    printf("Students in the age range:\n");
    printf("%-30s%-30s%-10s\n", "Name", "Age", "Gender");
    for (i = 0; i < header.student_count; i++) {
        StudentRecord student;
        if (readStudentRecord(file, &student) != 1) {
            printf("Error reading student record %d.\n", i);
            break;
        }

        if (student.age >= age_min && student.age <= age_max) {
            //printf("ID: %u, Name: %s, Age: %u, Gender: %s\n", student.student_id, student.name, student.age,
                   //(student.flags & 1) == 1 ? "Female" : "Male");
           //printf("%-30s%-30u%-10s\n", student.name, student.age, (student.flags & 1) == 1 ? "Female" : "Male");

        }
    }

    fclose(file);
    return 0;
}






