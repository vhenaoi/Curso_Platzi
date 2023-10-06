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

// gcc -Wall -Wextra -g3 -std=c99 Veronica_Henao_tarea3.c -o Veronica_Henao_tarea3.exe
// ./Veronica_Henao_tarea3.exe sample_data.bin

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Constantes para los valores mágicos
#define MAGIC_NUMBER 0xaeaa //Parece que tuviera un error
#define NUM_SEMESTERS 2
#define NUM_YEARS 5

#pragma pack(1)  // Establece el alineamiento en 1 byte

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

#pragma pack()  // Restablece el alineamiento por defecto

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <archivo binario>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    uint16_t magic;
    uint32_t student_count, course_count, enrollment_count;

    fread(&magic, sizeof(uint16_t), 1, file);
    if (magic != MAGIC_NUMBER) {
        printf("El archivo no tiene la cadena mágica correcta (0x%x)\n", magic);
        fclose(file);
        return 1;
    }
    printf("Magic: 0x%x\n", magic);

    fread(&student_count, sizeof(uint32_t), 1, file);
    fread(&course_count, sizeof(uint32_t), 1, file);
    fread(&enrollment_count, sizeof(uint32_t), 1, file);
    printf("Estudiantes: %u, Cursos: %u, Matriculas: %u\n", student_count, course_count, enrollment_count);

    struct Student students[student_count];
    for (size_t i = 0; i < student_count; i++) {
        fread(&students[i], sizeof(struct Student), 1, file);
    }

    // Inicializa una matriz para realizar un seguimiento de los estudiantes únicos
    // por género y tipo de estudiante
    bool unique_students_by_gender_and_type[2][2][NUM_YEARS][NUM_SEMESTERS] = {{{{false}}}};
    
    printf("enrollment_count = %u\n", enrollment_count);
    
    struct Enrollment enrollment;
    for (size_t i = 0; i < enrollment_count; i++) {
        fread(&enrollment, sizeof(struct Enrollment), 1, file);
        struct Student student = students[enrollment.student_id];

        if (student.is_graduate) {
            unique_students_by_gender_and_type[student.is_female][1][enrollment.year - 2019][enrollment.semester - 1] = true;
        } else {
            unique_students_by_gender_and_type[student.is_female][0][enrollment.year - 2019][enrollment.semester - 1] = true;
        }
        // Imprimir información sobre cada paso
        printf("Step %lu: Student ID = %u, Gender = %u, Graduate = %u, Year = %u, Semester = %u\n",
            (unsigned long)(i + 1), enrollment.student_id, student.is_female, student.is_graduate, enrollment.year, enrollment.semester);
    }

    fclose(file);

    // Imprime los resultados en formato de tabla
    printf("Year  | Semester | Male Undergraduate | Female Undergraduate | Male Graduate | Female Graduate \n");
    printf("---------------------------------------------------------------------------------------\n");
    for (size_t year = 0; year < NUM_YEARS; year++) {
        for (size_t semester = 0; semester < NUM_SEMESTERS; semester++) {
            int male_undergraduate = 0, female_undergraduate = 0, male_graduate = 0, female_graduate = 0;
            for (size_t i = 0; i < student_count; i++) {
                if (unique_students_by_gender_and_type[0][0][year][semester] && students[i].is_female == 0 && students[i].is_graduate == 0) {
                    male_undergraduate++;
                }
                if (unique_students_by_gender_and_type[1][0][year][semester] && students[i].is_female == 1 && students[i].is_graduate == 0) {
                    female_undergraduate++;
                }
                if (unique_students_by_gender_and_type[0][1][year][semester] && students[i].is_female == 0 && students[i].is_graduate == 1) {
                    male_graduate++;
                }
                if (unique_students_by_gender_and_type[1][1][year][semester] && students[i].is_female == 1 && students[i].is_graduate == 1) {
                    female_graduate++;
                }
            }
            printf("%-5lu| %-9lu| %-16lu| %-16lu| %-17lu| %-17lu\n", (unsigned long)(year + 2019), (unsigned long)(semester + 1),
            (unsigned long)male_undergraduate, (unsigned long)female_undergraduate, (unsigned long)male_graduate, (unsigned long)female_graduate);

        }
    }

    return 0;
}





