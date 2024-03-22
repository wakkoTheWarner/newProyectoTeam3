# @Author: Eduardo A. Sosa Torres

import os
import json

# ------------------------------- write_file ------------------------------- #
def write_file(output_path, header, students):
    # Create and write to csv file
    with open(output_path, "w") as file:
        file.write(header)
        for student in students:
            file.write(str(student) + "\n")

    print('\033[92m' + "\nEl archivo ha sido creado exitosamente.")

    return

# ------------------------------- Student Class ------------------------------- #
class Student:
    def __init__(self, num, name, id):
        self.num = num
        self.name = name
        self.id = id

    def __str__(self):
        return f"{self.num}, {self.name}, {self.id}"

# ------------------------------- header_builder ------------------------------- #
def header_builder(header):
    # Load Config
    with open('config.json') as f:
        config = json.load(f)
        defaults = config['default_values']

    # Variables
    counter = 0
    course = ""
    semester = ""
    section = ""
    university_name = ""
    university_campus = ""
    university_department = ""
    professor_name = ""

    for line in header:
        if line.find("Course Information") == -1 and counter < 3:
            if counter == 0:
                course = line
            elif counter == 1:
                section = line
            elif counter == 2:
                semester = line
            counter += 1

    semester = semester_parser(semester)
    course = course_parser(course, section)

    university_name = input("\nIngrese el nombre de la universidad: ")
    university_campus = input("Ingrese el recinto de la universidad: ")
    university_department = input("Ingrese el departamento de la universidad: ")
    professor_name = input("Ingrese el nombre del profesor: ")

    if university_name == "":
        university_name = defaults["university_name"]
    if university_campus == "":
        university_campus = defaults["university_campus"]
    if university_department == "":
        university_department = defaults["university_department"]
    if professor_name == "":
        professor_name = defaults["professor_name"]

    university_name = university_name.upper()
    university_campus = university_campus.upper()
    university_department = university_department.upper()
    professor_name = professor_name.upper()

    header_text = "," + university_name + "\n," + university_campus + "\n," + university_department + "\n\nSEMESTRE: " + semester + "\nPROF: " + professor_name + "\nCURSO: " + course + "\n\n\n" + defaults["table_header"] + "\n"
    return header_text

def semester_parser(semester):
    # Variables
    month_status = False
    input_dates = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    output_dates = ["ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"]
    month_one = ""
    month_two = ""
    year = ""

    semester = semester.replace("\t", " ").replace(",", "")

    for line in semester.split(" "):
        if line in input_dates and month_status == False:
            month_one = output_dates[input_dates.index(line)]
            month_status = True
        elif line in input_dates and month_status == True:
            month_two = output_dates[input_dates.index(line)]
            break

        if line.isdigit() and len(line) == 4:
            year = line

    semester = month_one + "-" + month_two + " " + year

    return semester

def course_parser(course, section):
    # Variables
    course_status = False
    course_name = ""

    for line in course.split(" "):
        if line.find("-") > -1 or line.find("0") > -1:
            if course_status == False:
                course_status = True
            else:
                course_status = False
        elif course_status == True and not line.isdigit():
            course_name += line + " "
        elif course_status == True and line.isdigit():
            course_name += line

    course_status = False
    for line in section.split("\t"):
        if course_status == False:
            course_status = True
        else:
            course_name += " (" + line + ")"
            break

    return course_name

# ------------------------------- read_file ------------------------------- #
def read_file(path_to_file):
    # Variables
    header = []
    students = []
    header_text = ""
    counter = 0

    # ignore blank lines
    with open(path_to_file, "r") as file:
        for line in file:
            if line.strip() != "" and counter < 12:
                header.append(line.strip())
                counter += 1
            elif line.strip() != "" and counter > 11:
                values = line.split("\t")
                student = Student("\"" + values[0] + "\"", "\"" + values[1] + "\"", "\"" + values[2] + "\"")
                students.append(student)

    header_text = header_builder(header)

    return header_text, students

# ------------------------------- path_verifier ------------------------------- #
def path_verifier(check):
    # Load Config
    with open('config.json') as f:
        config = json.load(f)
        default_paths = config['default_paths']

    if check == 0:
        # Variables
        default_path = default_paths["input_path"]
        file_path = ""
        user_confirmation = ""

        attempts = 0
        while attempts < 3:
            file_path = input("\nIngrese la ruta del archivo: ")

            if file_path.endswith(".txt") == False and file_path.find(".") > -1:
                print('\033[91m' + "\nTipo de archivo inválido. Por favor, ingrese una ruta de archivo válida." + '\033[0m')
            else:
                if file_path.endswith(".txt") == False:
                    file_path = file_path + ".txt"

                if file_path.find("/") > -1:
                    print('\033[93m' + "\n" + file_path + '\033[0m')
                else:
                    file_path = default_path + file_path
                    print('\033[93m' + "\n" + file_path + '\033[0m')

                user_confirmation = input("¿Es esta la ruta correcta del archivo? (sí/no): ")

                if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                    if os.path.exists(file_path) == True:
                        return file_path
                    else:
                        print('\033[91m' + "\nEl archivo no existe. Por favor, ingrese una ruta de archivo válida." + '\033[0m')
            attempts += 1
        print('\033[91m' "\n!! -- Se alcanzó el máximo de intentos. El programa ahora saldrá. -- !!" + '\033[0m')
    elif check == 1:
        # Variables
        default_path = default_paths["output_path"]
        file_path = ""
        user_confirmation = ""

        attempts = 0
        while attempts < 3:
            file_path = input("\nIngrese la ruta del archivo de salida: ")

            if file_path.endswith(".csv") == False and file_path.find(".") > -1:
                print('\033[91m' + "\nTipo de archivo inválido. Por favor, ingrese una ruta de archivo válida." + '\033[0m')
            else:
                if file_path.endswith(".csv") == False:
                    file_path = file_path + ".csv"

                if file_path.find("/") > -1:
                    print('\033[93m' + "\n" + file_path + '\033[0m')
                else:
                    file_path = default_path + file_path
                    print('\033[93m' + "\n" + file_path + '\033[0m')

                user_confirmation = input("¿Es esta la ruta correcta del archivo? (sí/no): ")

                if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                    dir_name = os.path.dirname(file_path)
                    if not os.path.exists(dir_name):
                        user_confirmation = input('\033[93m' + "\nEl directorio no existe. " + '\033[0m' + "¿Le gustaría crearlo? (sí/no): ")
                        if user_confirmation.lower() in ["yes", "y", "sí", "si", "s"]:
                            os.makedirs(dir_name)
                        else:
                            print('\033[91m' + "\nPor favor, ingrese una ruta de archivo válida." + '\033[0m')
                            path_verifier(1)
                    return file_path
            attempts += 1
        print('\033[91m' "\n!! -- Se alcanzó el máximo de intentos. El programa ahora saldrá. -- !!" + '\033[0m')
    exit(0)

# ------------------------------- main ------------------------------- #
if __name__ == '__main__':
    path_to_file = path_verifier(0)
    header, students = read_file(path_to_file)
    output_path = path_verifier(1)
    write_file(output_path, header, students)

    exit(0)