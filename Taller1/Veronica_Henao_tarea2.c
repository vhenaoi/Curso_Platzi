// TAREA 2
// Implementa un programa en C que calcule e imprima
// la edad promedio de los estudiantes que asisten a un curso específico.

// CORRER ESTAS LINEAS EN LA TERMINAL

// gcc -Wall -Wextra -g3 -std=c99 Veronica_Henao_tarea2.c -o Veronica_Henao_tarea2.exe
// ./Veronica_Henao_tarea2.exe sample_data.bin

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1)  // Establece el alineamiento en 1 byte

// Estructura para el encabezado del archivo
typedef struct {
    uint16_t magic;
    uint32_t student_count;
    uint32_t course_count;
    uint32_t enrollment_count;
} Header;

// Estructura para los registros de cursos
typedef struct {
    uint32_t course_id;
    char name[32];  // Se aumenta el tamaño para acomodar el nombre
    uint32_t credit_hours;
} CourseRecord;

// Estructura para los registros de matrículas
typedef struct {
    uint32_t student_id;
    uint32_t course_id;
    uint32_t year;
    uint32_t semester;
    uint32_t student_age; // Agregamos la edad del estudiante
} EnrollmentRecord;

#pragma pack()  // Restablece el alineamiento por defecto

// Función para leer el encabezado del archivo
int readHeader(FILE *file, Header *header) {
    return fread(header, sizeof(Header), 1, file);
}

// Función para leer un registro de curso
int readCourseRecord(FILE *file, CourseRecord *course) {
    return fread(course, sizeof(CourseRecord), 1, file);
}

// Función para leer un registro de matrícula
int readEnrollmentRecord(FILE *file, EnrollmentRecord *enrollment) {
    return fread(enrollment, sizeof(EnrollmentRecord), 1, file);
}

// Estructura para almacenar el nombre del curso y su promedio de edad
typedef struct {
    char name[32];
    float average_age;
} CourseAge;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    const char *binary_file = argv[1];

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
    
    printf("%-40s%-10s\n", "Course Name", "Average Age");

    CourseAge course_ages[header.course_count]; // Arreglo para almacenar los promedios de edad por curso
    uint32_t i;
    uint32_t j;

    for (i = 0; i < header.course_count; i++) {
        CourseRecord course;
        if (readCourseRecord(file, &course) != 1) {
            //printf("Error reading course record %d.\n", i);
            continue; // Continuar con el próximo curso
        }

        uint32_t total_age = 0;
        uint32_t course_student_count = 0;
        uint32_t successful_enrollments = 0;

        for (j = 0; j < header.enrollment_count; j++) {
            EnrollmentRecord enrollment;
            if (readEnrollmentRecord(file, &enrollment) != 1) {
                //printf("Error reading enrollment record %d.\n", j);
                // Aquí puedes registrar el número de registro problemático si lo deseas
                continue; // Continuar con la próxima matrícula
            }

            if (enrollment.course_id == course.course_id) {
                // Encontramos un estudiante inscrito en este curso
                total_age += enrollment.student_age;
                course_student_count++;
                // Aquí puedes registrar el número de registro leído con éxito si lo deseas
                successful_enrollments++;
            }
        }
        // Después del bucle, muestra el número total de registros de matrícula leídos con éxito
        printf("Total de registros de matricula leidos con exito: %u\n", successful_enrollments);

        // Calcular el promedio de edad solo si al menos un estudiante se inscribió en el curso
        if (course_student_count > 0) {
            float average_age = (float)total_age / (float)course_student_count;
            // Almacenar el nombre del curso y su promedio de edad en la estructura CourseAge
            snprintf(course_ages[i].name, sizeof(course_ages[i].name), "%s", course.name);
            course_ages[i].average_age = average_age;
        }
    }

    // Imprimir la tabla de resultados
    for (i = 0; i < header.course_count; i++) {
        printf("%-40s%.2f\n", course_ages[i].name, course_ages[i].average_age);
    }

    fclose(file);
    return 0;
}

