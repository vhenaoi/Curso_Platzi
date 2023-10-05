import pandas as pd

def read_header(file):
    # Leer los primeros 14 bytes del encabezado
    header_data = file.read(14)
    
    # Extraer los valores del encabezado
    magic = int.from_bytes(header_data[0:2], 'little')
    student_count = int.from_bytes(header_data[2:6], 'little')
    course_count = int.from_bytes(header_data[6:10], 'little')
    enrollment_count = int.from_bytes(header_data[10:14], 'little')
    
    return magic, student_count, course_count, enrollment_count

def read_student_record(file):
    # Leer los datos del estudiante
    student_id_bytes = file.read(4)
    student_id = int.from_bytes(student_id_bytes, 'little')
    
    flags_byte = file.read(1)
    flags = int.from_bytes(flags_byte, 'little')
    
    name_bytes = file.read(23)
    name = name_bytes.decode('utf-8').rstrip('\x00')
    
    age_bytes = file.read(4)
    age = int.from_bytes(age_bytes, 'little')
    
    # Interpretar las banderas
    is_female = (flags & 1) == 1
    is_grad_student = (flags & 2) == 2
    
    gender = "Female" if is_female else "Male"
    student_type = "Postgraduate" if is_grad_student else "Undergraduate"
    
    return student_id, name, age, gender, student_type

def read_course_record(file):
    # Leer los datos del curso
    course_id_bytes = file.read(4)
    course_id = int.from_bytes(course_id_bytes, 'little')
    
    course_name_bytes = file.read(32)
    course_name = course_name_bytes.decode('utf-8').rstrip('\x00')
    
    credit_hours_bytes = file.read(4)
    credit_hours = int.from_bytes(credit_hours_bytes, 'little')
    
    return course_id, course_name, credit_hours

def read_enrollment_record(file):
    # Leer los datos de matrícula
    student_id_bytes = file.read(4)
    student_id = int.from_bytes(student_id_bytes, 'little')
    
    course_id_bytes = file.read(4)
    course_id = int.from_bytes(course_id_bytes, 'little')
    
    year_bytes = file.read(4)
    year = int.from_bytes(year_bytes, 'little')
    
    semester_bytes = file.read(4)
    semester = int.from_bytes(semester_bytes, 'little')
    
    return student_id, course_id, year, semester

# Función principal
def main():
    binary_file = input("Archivo .bin: ")
    while True:
        print("La edad minima debe ser menor que la edad maxima")
        age_min = int(input("Edad minima: "))
        age_max = int(input("Edad maxima: "))
        if age_min < age_max:
            break

    students_in_range = []
    
    try:
        with open(binary_file, 'rb') as file:
            magic, student_count, course_count, enrollment_count = read_header(file)
            
            # Leer e imprimir los datos de estudiantes en el rango de edades
            print("Students in the age range:")
            for _ in range(student_count):
                student_id, name, age, gender, student_type = read_student_record(file)
                if age_min <= age <= age_max:
                    #print(f"ID: {student_id}, Name: {name}, Age: {age}, Gender: {gender}, Type: {student_type}")
                    student_data = {
                        'Name': name,
                        'Age': age,
                        'Gender': gender
                    }
                    students_in_range.append(student_data)   
            # Crear un DataFrame a partir de la lista de estudiantes en el rango de edad
            student_range = pd.DataFrame(students_in_range)
            # Imprimir el DataFrame completo
            print(student_range)         
            # Leer e imprimir los datos de cursos
            #print("\nCourse:")
            for _ in range(course_count):
                course_id, course_name, credit_hours = read_course_record(file)
                #print(f"ID: {course_id}, Name: {course_name}, Credit hours: {credit_hours}")
            
            # Leer e imprimir los datos de matrículas
            #print("\nRegistration:")
            for _ in range(enrollment_count):
                student_id, course_id, year, semester = read_enrollment_record(file)
                #print(f"ID: {student_id}, ID Course: {course_id}, Year: {year}, Semester: {semester}")
    
    except FileNotFoundError:
        print(f"The file '{binary_file}' does not exist.")
    except Exception as e:
        print(f"Error reading the binary file: {str(e)}")

if __name__ == "__main__":
    main()

