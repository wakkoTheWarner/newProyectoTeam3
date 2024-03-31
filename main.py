# @Author: Eduardo A. Sosa Torres

import os
import json

# ------------------------------- write_file ------------------------------- #
def write_file(output_path, header, students):
    # Crea y escribe en el archivo csv
    with open(output_path, "w") as file:
        # Escribe el encabezado en el archivo
        file.write(header)
        # Itera sobre cada estudiante en la lista de estudiantes
        for student in students:
            # Escribe la representación en cadena del estudiante en el archivo
            file.write(str(student) + "\n")

    absolute_path = os.path.abspath(output_path)

    # Imprime un mensaje indicando que el archivo ha sido creado exitosamente
    print('\033[92m' + "\nEl archivo ha sido creado exitosamente en la siguiente ruta: " + '\033[1;32m' + "\n" + absolute_path + '\033[0m')

    # Retorna de la función
    return

# ------------------------------- Student Class ------------------------------- #
class Student:
    def __init__(self, num, name, id):
        # Inicializa la clase Student con número, nombre e id
        self.num = num
        self.name = name
        self.id = id

    def __str__(self):
        # Devuelve una representación en cadena de la clase Student
        return f"{self.num}, {self.name}, {self.id}"

# ------------------------------- header_builder ------------------------------- #
def header_builder(header):
    # Carga la configuración desde el archivo 'config.json'
    with open('config.json') as f:
        config = json.load(f)
        defaults = config['default_values']

    # Inicializa las variables
    counter = 0
    course = ""
    semester = ""
    section = ""
    university_name = ""
    university_campus = ""
    university_department = ""
    professor_name = ""

    # Itera sobre cada línea en el encabezado
    for line in header:
        # Si la línea no contiene "Course Information" y el contador es menor a 3
        if line.find("Course Information") == -1 and counter < 3:
            # Asigna la línea a la variable correspondiente
            if counter == 0:
                course = line
            elif counter == 1:
                section = line
            elif counter == 2:
                semester = line
            # Incrementa el contador
            counter += 1

    # Parsea el semestre y el curso
    semester = semester_parser(semester)
    course = course_parser(course, section)

    # Solicita al usuario que ingrese la información de la universidad
    university_name = input("\nIngrese el nombre de la universidad: ")
    university_campus = input("Ingrese el recinto de la universidad: ")
    university_department = input("Ingrese el departamento de la universidad: ")
    professor_name = input("Ingrese el nombre del profesor: ")

    # Si el usuario no ingresa información, se utilizan los valores por defecto
    if university_name == "":
        university_name = defaults["university_name"]
    if university_campus == "":
        university_campus = defaults["university_campus"]
    if university_department == "":
        university_department = defaults["university_department"]
    if professor_name == "":
        professor_name = defaults["professor_name"]

    # Convierte la información de la universidad a mayúsculas
    university_name = university_name.upper()
    university_campus = university_campus.upper()
    university_department = university_department.upper()
    professor_name = professor_name.upper()

    # Construye el texto del encabezado
    header_text = "," + university_name + "\n," + university_campus + "\n," + university_department + "\n\nSEMESTRE: " + semester + "\nPROF: " + professor_name + "\nCURSO: " + course + "\n\n\n" + defaults["table_header"] + "\n"

    # Retorna el texto del encabezado
    return header_text

def semester_parser(semester):
    # Inicializa las variables
    month_status = False
    input_dates = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    output_dates = ["ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"]
    month_one = ""
    month_two = ""
    year = ""

    # Reemplaza los caracteres de tabulación y comas en el semestre
    semester = semester.replace("\t", " ").replace(",", "")

    # Itera sobre cada palabra en el semestre
    for line in semester.split(" "):
        # Si la palabra es un mes y no se ha asignado el primer mes
        if line in input_dates and month_status == False:
            month_one = output_dates[input_dates.index(line)]
            month_status = True
        # Si la palabra es un mes y ya se ha asignado el primer mes
        elif line in input_dates and month_status == True:
            month_two = output_dates[input_dates.index(line)]
            break

        # Si la palabra es un año
        if line.isdigit() and len(line) == 4:
            year = line

    # Construye el semestre
    semester = month_one + "-" + month_two + " " + year

    # Retorna el semestre
    return semester

def course_parser(course, section):
    # Inicializa las variables
    course_status = False
    course_name = ""

    # Itera sobre cada palabra en el curso
    for line in course.split(" "):
        # Si la palabra contiene "-" o "0"
        if line.find("-") > -1 or line.find("0") > -1:
            # Cambia el estado del curso
            if course_status == False:
                course_status = True
            else:
                course_status = False
        # Si el estado del curso es verdadero y la palabra no es un número
        elif course_status == True and not line.isdigit():
            course_name += line + " "
        # Si el estado del curso es verdadero y la palabra es un número
        elif course_status == True and line.isdigit():
            course_name += line

    # Cambia el estado del curso
    course_status = False
    # Itera sobre cada palabra en la sección
    for line in section.split("\t"):
        # Si el estado del curso es falso
        if course_status == False:
            course_status = True
        else:
            # Añade la sección al nombre del curso
            course_name += " (" + line + ")"
            break

    # Retorna el nombre del curso
    return course_name

# ------------------------------- read_file ------------------------------- #
def read_file(path_to_file):
    # Inicializa las variables
    header = []
    students = []
    header_text = ""
    counter = 0

    # Abre el archivo en modo lectura
    with open(path_to_file, "r", encoding="windows-1252") as file:
        # Itera sobre cada línea en el archivo
        for line in file:
            # Si la línea no está vacía y el contador es menor a 12
            if line.strip() != "" and counter < 12:
                # Añade la línea al encabezado
                header.append(line.strip())
                # Incrementa el contador
                counter += 1
            # Si la línea no está vacía y el contador es mayor a 11
            elif line.strip() != "" and counter > 11:
                # Divide la línea en valores
                values = line.split("\t")
                # Crea un nuevo estudiante con los valores obtenidos
                student = Student("\"" + values[0] + "\"", "\"" + values[1].strip() + "\"", "\"" + values[2] + "\"")
                # Añade el estudiante a la lista de estudiantes
                students.append(student)

    # Construye el texto del encabezado
    header_text = header_builder(header)

    # Retorna el texto del encabezado y la lista de estudiantes
    return header_text, students

# ------------------------------- path_verifier ------------------------------- #
def path_verifier(check):
    # Carga la configuración desde el archivo 'config.json'
    with open('config.json') as f:
        config = json.load(f)
        default_paths = config['default_paths']

    # Verifica si el usuario desea ingresar la ruta del archivo
    if check == 0:
        # Inicializa las variables
        default_path = default_paths["input_path"]
        file_path = ""
        user_confirmation = ""

        attempts = 0
        while attempts < 3:
            # Solicita al usuario que ingrese la ruta del archivo
            file_path = input("\nIngrese la ruta del archivo: ")

            # Verifica si el archivo es de tipo .txt
            if file_path.endswith(".txt") == False and file_path.find(".") > -1:
                print('\033[91m' + "\nTipo de archivo inválido. Por favor, ingrese una ruta de archivo válida." + '\033[0m')
            else:
                # Si el archivo no tiene extensión, se le añade .txt
                if file_path.endswith(".txt") == False:
                    file_path = file_path + ".txt"

                # Verifica si la ruta del archivo es absoluta o relativa
                if file_path.find("/") > -1:
                    print('\033[93m' + "\n" + file_path + '\033[0m')
                else:
                    # Si la ruta es relativa, se le añade la ruta por defecto
                    file_path = default_path + file_path
                    print('\033[93m' + "\n" + file_path + '\033[0m')

                # Solicita al usuario que confirme la ruta del archivo
                user_confirmation = input("¿Es esta la ruta correcta del archivo? (sí/no): ")

                # Si el usuario confirma, verifica si el archivo existe
                if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                    # Verifica si el archivo existe
                    if os.path.exists(file_path) == True:
                        # Si el archivo existe, retorna la ruta
                        return file_path
                    else:
                        # Si el archivo no existe, solicita al usuario que ingrese una ruta válida
                        print('\033[91m' + "\nEl archivo no existe. Por favor, ingrese una ruta de archivo válida." + '\033[0m')

            # Incrementa el contador de intentos
            attempts += 1

        # Si se alcanza el máximo de intentos, el programa se cierra
        print('\033[91m' "\n!! -- Se alcanzó el máximo de intentos. El programa ahora saldrá. -- !!" + '\033[0m')

    # Verifica si el usuario desea ingresar la ruta del archivo de salida
    elif check == 1:
        # Inicializa las variables
        default_path = default_paths["output_path"]
        file_path = ""
        user_confirmation = ""

        attempts = 0
        while attempts < 3:
            # Solicita al usuario que ingrese la ruta del archivo de salida
            file_path = input("\nIngrese la ruta del archivo de salida: ")

            # Verifica si el archivo es de tipo .csv
            if file_path.endswith(".csv") == False and file_path.find(".") > -1:
                print('\033[91m' + "\nTipo de archivo inválido. Por favor, ingrese una ruta de archivo válida." + '\033[0m')
            else:
                # Si el archivo no tiene extensión, se le añade .csv
                if file_path.endswith(".csv") == False:
                    file_path = file_path + ".csv"

                # Verifica si la ruta del archivo es absoluta o relativa
                if file_path.find("/") > -1:
                    print('\033[93m' + "\n" + file_path + '\033[0m')
                else:
                    # Si la ruta es relativa, se le añade la ruta por defecto
                    file_path = default_path + file_path
                    print('\033[93m' + "\n" + file_path + '\033[0m')

                # Solicita al usuario que confirme la ruta del archivo
                user_confirmation = input("¿Es esta la ruta correcta del archivo? (sí/no): ")

                # Si el usuario confirma, verifica si el directorio existe
                if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                    dir_name = os.path.dirname(file_path)
                    if not os.path.exists(dir_name):
                        # Si el directorio no existe, solicita al usuario si desea crearlo
                        user_confirmation = input('\033[93m' + "\nEl directorio no existe. " + '\033[0m' + "¿Le gustaría crearlo? (sí/no): ")
                        if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                            # Si el usuario confirma, crea el directorio
                            os.makedirs(dir_name)
                        else:
                            # Si el usuario no confirma, solicita al usuario que ingrese una ruta válida
                            print('\033[91m' + "\nPor favor, ingrese una ruta de archivo válida." + '\033[0m')
                            path_verifier(1)
                    # Si el directorio existe, retorna la ruta
                    return file_path

            # Incrementa el contador de intentos
            attempts += 1

        # Si se alcanza el máximo de intentos, el programa se cierra
        print('\033[91m' "\n!! -- Se alcanzó el máximo de intentos. El programa ahora saldrá. -- !!" + '\033[0m')

    # Si no se cumple ninguna de las condiciones anteriores, el programa se cierra
    exit(0)

# ------------------------------- main ------------------------------- #
if __name__ == '__main__':

    # Solicita al usuario que ingrese la ruta del archivo
    path_to_file = path_verifier(0)

    # Lee el archivo y almacena los datos
    header, students = read_file(path_to_file)

    # Solicita al usuario que ingrese la ruta del archivo de salida
    output_path = path_verifier(1)

    # Escribe los datos en el archivo de salida
    write_file(output_path, header, students)

    # Cierra el programa
    exit(0)