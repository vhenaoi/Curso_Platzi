# Abre el archivo binario en modo lectura
binary_file = r"E:\Laboral\Trabajo\AvanzaTech\Codigos\Curso_Platzi\Taller1\sample_data.bin"

try:
    with open(binary_file, "rb") as file:
        # Leer el encabezado del archivo manualmente
        header_data = file.read(14)  # El encabezado tiene 14 bytes según el formato dado
        magic, student_count, course_count, enrollment_count = (
            int.from_bytes(header_data[0:2], byteorder='little'),  # magic
            int.from_bytes(header_data[2:6], byteorder='little'),  # student_count
            int.from_bytes(header_data[6:10], byteorder='little'),  # course_count
            int.from_bytes(header_data[10:14], byteorder='little')  # enrollment_count
        )

        print(f"Course Information:\n{'Course Name':<40}{'Average Age':<10}")

        course_ages = []

        for i in range(course_count):
            # Leer un registro de curso manualmente
            course_data = file.read(40)  # Cada registro de curso tiene 40 bytes
            course_id, name, credit_hours = (
                int.from_bytes(course_data[0:4], byteorder='little'),  # course_id
                course_data[4:36].decode('utf-8').strip('\x00'),  # name
                int.from_bytes(course_data[36:40], byteorder='little')  # credit_hours
            )

            total_age = 0
            course_student_count = 0

            for j in range(enrollment_count):
                # Leer un registro de matrícula manualmente
                enrollment_data = file.read(20)  # Cada registro de matrícula tiene 20 bytes
                student_id, course_id_enroll, year, semester, student_age = (
                    int.from_bytes(enrollment_data[0:4], byteorder='little'),  # student_id
                    int.from_bytes(enrollment_data[4:8], byteorder='little'),  # course_id_enroll
                    int.from_bytes(enrollment_data[8:12], byteorder='little'),  # year
                    int.from_bytes(enrollment_data[12:16], byteorder='little'),  # semester
                    int.from_bytes(enrollment_data[16:20], byteorder='little')  # student_age
                )

                if course_id_enroll == course_id:
                    total_age += student_age
                    course_student_count += 1

            if course_student_count > 0:
                average_age = total_age / course_student_count
                course_ages.append((name, average_age))

        for course_name, average_age in course_ages:
            print(f"{course_name:<40}{average_age:.2f}")

except FileNotFoundError:
    print(f"File '{binary_file}' does not exist.")
except Exception as e:
    print(f"An error occurred: {str(e)}")

