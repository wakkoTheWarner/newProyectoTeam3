import os

# ------------------------------- write_file ------------------------------- #
# Objetivo:
# - Esta función escribe la información de los estudiantes en un archivo tipo CSV.
#
# Precondiciones:
# - El argumento `output_path` debe ser una ruta válida en donde el archivo puede ser escrito.
# - El argumento `header` debe ser una representación en cadena del encabezado del archivo CSV.
# - El argumento`students` debe ser una lista de objetos que representa a los estudiantes.
#
# Postcondiciones:
# - Se crea un archivo CSV que contiene al encabezado especificado y también debe tener la información de los estudiantes en la ruta que fue indicada por el argumento `output_path`.
#
# Descripción de los Argumentos:
# - `output_path`: La ruta donde se escribirá el archivo CSV.
# - `header`: El encabezado del archivo CSV que se especificará para que contenga los nombres de las columnas.
# - `students`: Una lista de objetos que representan a los estudiantes. Cada uno de estos objetos deben tener una representación en cadena que se puedan escribir detro del archivo CSV.
#
# Autor: Javier Santos Babilonia
#
# Fecha de Finalización: 05/04/2024
def write_file(output_path, header, students):
    # Crea y escribe en el archivo csv
    with open(output_path, "w") as file:
        # Escribe el encabezado en el archivo
        file.write(header)
        # Itera sobre cada estudiante en la lista de estudiantes
        for student in students:
            # Escribe la representación en cadena del estudiante en el archivo
            file.write(str(student) + "\n")

    # Obtiene la ruta absoluta del archivo
    absolute_path = os.path.abspath(output_path)

    # Imprime un mensaje indicando que el archivo ha sido creado exitosamente y la ruta del archivo
    print('\033[92m' + "\nEl archivo ha sido creado exitosamente en la siguiente ruta: " + '\033[1;32m' + "\n" + absolute_path + '\033[0m' + "\n")

    # Retorna de la función
    return

# ------------------------------- Student Class ------------------------------- #
# Objetivo: Esta clase representa a un estudiante con un número, nombre e id.
#
# Precondiciones:
# - Los argumentos `num`, `name` e `id` deben ser proporcionados al inicializar una instancia de la clase Student.
#
# Postcondiciones:
# - Al inicializar una instancia de la clase Student, se crean los atributos `num`, `name` e `id` con los valores proporcionados.
# - La función `__str__` devuelve una representación en cadena de la instancia de la clase Student en el formato "[num], [name], [id]".
#
# Descripción de los Argumentos:
# - `num`: Un valor que representa el número del estudiante.
# - `name`: Una cadena que representa el nombre del estudiante.
# - `id`: Un valor que representa el id del estudiante.
#
# Autor: Christian J. Santiago Rivera
#
# Fecha de Finalización: 04/04/2024
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
# Objetivo: Esta función construye el encabezado del archivo de salida. Solicita al usuario que ingrese información
# sobre la universidad y el profesor, y utiliza esta información junto con la información del curso y el
# semestre para construir el encabezado.
#
# Precondiciones:
# - El argumento `header` debe ser una lista de cadenas que contiene las líneas del encabezado del archivo de entrada.
# - El usuario debe proporcionar la información de la universidad cuando se le solicite o se utilizarán los valores por defecto.
# - Las funciones `semester_parser` y `course_parser` deben estar definidas y funcionar correctamente.
#
# Postcondiciones:
# - La función devuelve una cadena que representa el encabezado del archivo de salida.
#
# Descripción de los Argumentos:
# - header: Una lista de cadenas que contiene las líneas del encabezado del archivo de entrada.
#
# Autor: Eduardo A. Sosa Torres
#
# Fecha de Finalización: 27/03/2024
def header_builder(header):
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
        university_name = "UNIVERSIDAD ABC123"
    if university_campus == "":
        university_campus = "RECINTO DE ISLA DE MONA"
    if university_department == "":
        university_department = "DEPARTAMENTO DE CIENCIAS EN COMPUTADORAS"
    if professor_name == "":
        professor_name = "PEPITO PEREZ"

    # Convierte la información de la universidad a mayúsculas
    university_name = university_name.upper()
    university_campus = university_campus.upper()
    university_department = university_department.upper()
    professor_name = professor_name.upper()

    # Construye el texto del encabezado
    header_text = "," + university_name + "\n," + university_campus + "\n," + university_department + "\n\nSEMESTRE: " + semester + "\nPROF: " + professor_name + "\nCURSO: " + course + "\n\n\n" + "NUM,NOMBRE,ID,Email,Telefono" + "\n"

    # Retorna el texto del encabezado
    return header_text

# Objetivo: Esta función toma una cadena que representa un semestre en inglés y la convierte a una representación
# en español en el formato [Mes - Mes Año]. La cadena de entrada debe contener los nombres de los meses en inglés y
# el año. La función devuelve una cadena que representa el semestre en español.
#
# Precondiciones:
# - El argumento `semester` debe ser una cadena que contiene los nombres de los meses en inglés y el año.
#
# Postcondiciones:
# - La función devuelve una cadena que representa el semestre en español en el formato [Mes - Mes Año].
#
# Descripción de los Argumentos:
# - `semester`: Una cadena que contiene los nombres de los meses en inglés y el año.
#
# Autor: Eduardo A. Sosa Torres
#
# Fecha de Finalización: 27/03/2024
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

# Objetivo: Esta función toma una cadena que representa un curso y una sección, y construye una representación
# del nombre del curso. La cadena de entrada debe contener el nombre del curso y la sección. La función devuelve una
# cadena que representa el nombre del curso en el formato [Nombre del Curso (Sección)].
#
# Precondiciones:
# - El argumento `course` debe ser una cadena que contiene el nombre del curso.
# - El argumento `section` debe ser una cadena que contiene la sección del curso.
#
# Postcondiciones:
# - La función devuelve una cadena que representa el nombre del curso en el formato [Nombre del Curso (Sección)].
#
# Descripción de los Argumentos:
# - `course`: Una cadena que contiene el nombre del curso.
# - `section`: Una cadena que contiene la sección del curso.
#
# Autor: Eduardo A. Sosa Torres
#
# Fecha de Finalización: 27/03/2024
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
# Objetivo: La clase read_file se utiliza para leer datos de un archivo específico y extraer informacion relevante.
#
# Precondiciones:
# - Debe existir un archivo en la dirección especificada. De lo contrario se producirá un error al intentar abrir el archivo.
# - El archivo debe estar codificado en utf-8 o ISO-8859-1.
# - El archivo debe contar con un formato específico. Las primeras 12 líneas contendrán el encabezado, el resto serán datos tabulados de los estudiantes.
# - La clase Student debe estar definida.
# - Las funciones header_builder(header) y header_text deben estar definidas.
#
# Postcondiciones:
# - Al ejecutar la función read_file(path_to_file) se espera construir el encabezado.
# - Esa misma función debe haber creado la lista de estudiantes students y cada uno debería estar representado por una instancia de la clase Student con sus atributos.
# - El valor de retorno será header_text, students.
#
# Descripción de los Argumentos:
# - `path_to_file`: Una cadena que representa la dirección del archivo a leer.
#
# Autor: Azkaria L. Rosado Rodriguez
#
# Fecha de Finalización: 05/04/2024
def read_file(path_to_file):
    # Inicializa las variables
    header = []
    students = []
    header_text = ""
    counter = 0

    # Intenta abrir el archivo y leer los datos
    try:
        # Abre el archivo en modo lectura y codificado en utf-8.
        with open(path_to_file, "r", encoding='utf-8') as file:
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
    # Si da error con encoding UTF-8 utiliza ISO-8859-1
    except UnicodeDecodeError:
        # Abre el archivo en modo lectura y codificado en ISO-8859-1.
        with open(path_to_file, "r", encoding='ISO-8859-1') as file:
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
# Objetivo: Esta función verifica la ruta del archivo de entrada o salida proporcionada por el usuario. Si la ruta es
# válida y el archivo o directorio existe, la función devuelve la ruta. Si la ruta no es válida o el archivo o
# directorio no existe, la función solicita al usuario que ingrese una ruta válida. Si el usuario no proporciona una
# ruta válida después de tres intentos, la función cierra el programa.
#
# Precondiciones:
# - El argumento check debe ser un entero que indica si se está verificando la ruta del archivo de entrada (0) o de salida (1).
# - El archivo de entrada debe existir en la ruta proporcionada por el usuario y debe ser legible.
# - La ruta de salida proporcionada por el usuario debe ser válida y el programa debe tener permisos para escribir en esa ubicación.
#
# Postcondiciones:
# - Si la ruta del archivo es válida y el archivo o directorio existe, la función devuelve la ruta.
# - Si la ruta del archivo no es válida o el archivo o directorio no existe, la función solicita al usuario que ingrese una ruta válida.
# - Si el usuario no proporciona una ruta válida después de tres intentos, la función cierra el programa.
#
# Descripción de los Argumentos:
# - check: Un entero que indica si se está verificando la ruta del archivo de entrada (0) o de salida (1).
#
# Autor: Ian P. Roman
#
# Fecha de Finalización: 01/04/2024
def path_verifier(check):
    # Verifica si el usuario desea ingresar la ruta del archivo
    if check == 0:
        # Inicializa las variables
        default_path = os.path.join("Resources", "Data", "")
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
                if os.path.isabs(file_path):
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
        default_path = os.path.join("Resources", "Output", "")
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
                if os.path.isabs(file_path):
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
# Objetivo: Este bloque de código es el punto de entrada principal del programa. Solicita al usuario que ingrese la
# ruta del archivo de entrada, lee el archivo y almacena los datos, solicita al usuario que ingrese la ruta del
# archivo de salida, escribe los datos en el archivo de salida y finalmente cierra el programa.
#
# Precondiciones:
# - Las funciones `path_verifier`, `read_file` y `write_file` deben estar definidas y funcionar correctamente.
# - El archivo de entrada debe existir en la ruta proporcionada por el usuario y debe ser legible.
# - La ruta de salida proporcionada por el usuario debe ser válida y el programa debe tener permisos para escribir en esa ubicación.
#
# Postcondiciones:
# - Si todas las operaciones se completan con éxito, los datos se leen del archivo de entrada, se procesan y se escriben en el archivo de salida en la ubicación especificada.
# - Si ocurre algún error durante el proceso, el programa se cierra.
#
# Descripción de los Argumentos:
# - Este bloque de código no toma argumentos.
#
# Autor: Eduardo A. Sosa
#
# Fecha de Finalización: 26/03/2024
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