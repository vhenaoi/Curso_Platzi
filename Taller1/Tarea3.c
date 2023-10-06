// TAREA 3
// Implementa un programa en C que lea el archivo 
// binario e imprima el número de estudiantes distintos 
// que se matricularon en al menos 1 clase por semestre, 
// divididos por género y tipo de estudiante (estudiante 
// de posgrado o estudiante de pregrado). Imprime los resultados 
// en un formato similar a una tabla con seis columnas: Año, Semestre, 
// Hombres de pregrado, Mujeres de pregrado, Hombres de posgrado, 
// Mujeres de posgrado.

// CORRER ESTAS LINEAS EN LA TERMINAL

// gcc -Wall -Wextra -g3 -std=c99 Tarea3.c -o Tarea3.exe
// ./Tarea3.exe sample_data.bin

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Estructura para representar un estudiante
struct Student {
    uint32_t id;
    uint8_t is_female;
    uint8_t is_graduate;
    char name[23];
    uint32_t age;
};

// Estructura para representar un curso
struct Course {
    uint32_t id;
    char name[32];
    uint32_t credit_hours;
};

// Estructura para representar una matrícula
struct Enrollment {
    uint32_t student_id;
    uint32_t course_id;
    uint32_t year;
    uint32_t semester;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <archivo binario>\n", argv[0]);
        return 1;
    }

    // Abre el archivo binario en modo lectura
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Lee el encabezado
    uint16_t magic;
    uint32_t student_count, course_count, enrollment_count;
    size_t i;
    size_t j;
    uint32_t year;

    fread(&magic, sizeof(uint16_t), 1, file);
    printf("Magic: 0x%x\n", magic); // Agregado para depuración
    if (magic != 0xaeaa) {
        printf("El archivo no tiene la cadena magica correcta\n");
        fclose(file);
        return 1;
    }
    fread(&student_count, sizeof(uint32_t), 1, file);
    fread(&course_count, sizeof(uint32_t), 1, file);
    fread(&enrollment_count, sizeof(uint32_t), 1, file);
    printf("Estudiantes: %u, Cursos: %u, Matriculas: %u\n", student_count, course_count, enrollment_count); // Agregado para depuración

    // Lee los registros de estudiantes
    struct Student students[student_count];
    for (i = 0; i < student_count; i++) {
        fread(&students[i], sizeof(struct Student), 1, file);
    }
    printf("Leidos %u registros de estudiantes\n", student_count); // Agregado para depuración

    // Lee los registros de cursos (no se utilizan en este programa)
    struct Course courses[course_count];
    for (i = 0; i < course_count; i++) {
        fread(&courses[i], sizeof(struct Course), 1, file);
    }
    printf("Leidos %u registros de cursos\n", course_count); // Agregado para depuración

    // Inicializa una matriz para realizar un seguimiento de los estudiantes únicos
    // por género y tipo de estudiante
    uint32_t unique_students_by_gender_and_type[2][2] = {{0}};

    // Lee los registros de matrículas y realiza el conteo de estudiantes únicos
    struct Enrollment enrollment;
    uint32_t *enrolled_students = malloc(student_count * sizeof(uint32_t));
    for (i = 0; i < enrollment_count; i++) {
        fread(&enrollment, sizeof(struct Enrollment), 1, file);

        // Verifica si el estudiante ya se ha registrado en este semestre
        int is_duplicate = 0;
        for (j = 0; j < unique_students_by_gender_and_type[0][0]; j++) {
            if (enrolled_students[j] == enrollment.student_id) {
                is_duplicate = 1;
                break;
            }
        }

        // Si no es un duplicado, contabiliza al estudiante y regístralo
        if (!is_duplicate) {
            struct Student student = students[enrollment.student_id];
            if (student.is_graduate) {
                unique_students_by_gender_and_type[student.is_female][1]++;
            } else {
                unique_students_by_gender_and_type[student.is_female][0]++;
            }
            enrolled_students[unique_students_by_gender_and_type[0][0]] = enrollment.student_id;
            unique_students_by_gender_and_type[0][0]++;
        }
    }
    printf("Leidas %u matrículas\n", enrollment_count); // Agregado para depuración

    // Imprime los resultados en formato de tabla
    printf("Year  | Semester | Male Undergrand | Female Undergrad | Male Grand | Female Grand \n");
    printf("---------------------------------------------------------------------------------------\n");
    for (year = 0; year <= 4; year++) {
        for (uint32_t semester = 0; semester <= 1; semester++) {
            printf("%-5d| %-9d| %-16d| %-16d| %-17d| %-17d\n", year + 2019, semester + 1,
                unique_students_by_gender_and_type[0][0], unique_students_by_gender_and_type[1][0],
                unique_students_by_gender_and_type[0][1], unique_students_by_gender_and_type[1][1]);
        }
    }

    // Libera la memoria y cierra el archivo
    free(enrolled_students);
    fclose(file);

    return 0;
}




