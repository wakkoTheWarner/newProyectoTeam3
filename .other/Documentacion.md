## TAREAS DE DOCUMENTACIÓN

- [x] if __name__ == '__main__': Eduardo A. Sosa Torres
- [x] path_verifier(): Ian P. Roman
- [ ] read_file(): Azkaria L. Rosado Rodriguez
- [x] header_builder(): Eduardo A. Sosa Torres
- [x] semester_parser(): Eduardo A. Sosa Torres
- [x] course_parser(): Eduardo A. Sosa Torres
- [ ] Student Class: Christian J. Santiago Rivera
- [ ] write_file(): Javier Santos Babilonia

# Documentación Completa del Código y Visión General de la Funcionalidad
Este documento proporciona una descripción detallada de la estructura y el funcionamiento del código fuente del proyecto. Se divide en varias secciones, cada una de las cuales describe un componente clave del proyecto y su funcionalidad. Las secciones incluyen una descripción general del componente, sus objetivos, precondiciones, postcondiciones, descripción de los argumentos, autor y fecha de finalización.

[comment]: <> (------------------------ 📚 HEADER_BUILDER 📚 ------------------------)
[comment]: <> (By Eduardo A. Sosa Torres)

## 📚 header_builder

### Objetivo:
Esta función construye el encabezado del archivo de salida. Solicita al usuario que ingrese información sobre la universidad y el profesor, y utiliza esta información junto con la información del curso y el semestre para construir el encabezado.

### Precondiciones:
- El argumento `header` debe ser una lista de cadenas que contiene las líneas del encabezado del archivo de entrada.
- El archivo 'config.json' debe existir y contener los valores por defecto para el nombre de la universidad, el campus de la universidad, el departamento de la universidad y el nombre del profesor.
- Las funciones `semester_parser` y `course_parser` deben estar definidas y funcionar correctamente.

### Postcondiciones:
- La función devuelve una cadena que representa el encabezado del archivo de salida.

### Descripción de los Argumentos:
- `header`: Una lista de cadenas que contiene las líneas del encabezado del archivo de entrada.

### **Autor**: Eduardo A. Sosa Torres

### **Fecha de Finalización**: 27/03/2024

[comment]: <> (------------------------ SEMESTER_PARSER ------------------------)

## semester_parser

### Objetivo:
Esta función toma una cadena que representa un semestre en inglés y la convierte a una representación en español en el formato [Mes - Mes Año]. La cadena de entrada debe contener los nombres de los meses en inglés y el año. La función devuelve una cadena que representa el semestre en español.

### Precondiciones:
- El argumento `semester` debe ser una cadena que contiene los nombres de los meses en inglés y el año.

### Postcondiciones:
- La función devuelve una cadena que representa el semestre en español en el formato [Mes - Mes Año].

### Descripción de los Argumentos:
- `semester`: Una cadena que contiene los nombres de los meses en inglés y el año.

### **Autor**: Eduardo A. Sosa Torres

### **Fecha de Finalización**: 27/03/2024

[comment]: <> (------------------------ COURSE_PARSER ------------------------)

## course_parser

### Objetivo:
Esta función toma una cadena que representa un curso y una sección, y construye una representación del nombre del curso. La cadena de entrada debe contener el nombre del curso y la sección. La función devuelve una cadena que representa el nombre del curso en el formato [Nombre del Curso (Sección)].

### Precondiciones:
- El argumento `course` debe ser una cadena que contiene el nombre del curso.
- El argumento `section` debe ser una cadena que contiene la sección del curso.

### Postcondiciones:
- La función devuelve una cadena que representa el nombre del curso en el formato [Nombre del Curso (Sección)].

### Descripción de los Argumentos:
- `course`: Una cadena que contiene el nombre del curso.
- `section`: Una cadena que contiene la sección del curso.

### **Autor**: Eduardo A. Sosa Torres

### **Fecha de Finalización**: 27/03/2024

[comment]: <> (------------------------ 📚 PATH_VERIFIER 📚 ------------------------)
[comment]: <> (By Ian P. Roman)

## 📚 path_verifier

### Objetivo:
Esta función verifica la ruta del archivo de entrada o salida proporcionada por el usuario. Si la ruta es válida y el archivo o directorio existe, la función devuelve la ruta. Si la ruta no es válida o el archivo o directorio no existe, la función solicita al usuario que ingrese una ruta válida. Si el usuario no proporciona una ruta válida después de tres intentos, la función cierra el programa.

### Precondiciones:
- El argumento `check` debe ser un entero que indica si se está verificando la ruta del archivo de entrada (0) o de salida (1).
- El archivo 'config.json' debe existir y contener las rutas por defecto para los archivos de entrada y salida.

### Postcondiciones:
- Si la ruta del archivo es válida y el archivo o directorio existe, la función devuelve la ruta.
- Si la ruta del archivo no es válida o el archivo o directorio no existe, la función solicita al usuario que ingrese una ruta válida.
- Si el usuario no proporciona una ruta válida después de tres intentos, la función cierra el programa.

### Descripción de los Argumentos:
- `check`: Un entero que indica si se está verificando la ruta del archivo de entrada (0) o de salida (1).

### **Autor**: Ian P. Roman

### **Fecha de Finalización**: 01/04/2024

[comment]: <> (------------------------ 📚 MAIN 📚 ------------------------)
[comment]: <> (By Eduardo A. Sosa Torres)

## 📚 if __name__ == '__main__'

### Objetivo:
Este bloque de código es el punto de entrada principal del programa. Solicita al usuario que ingrese la ruta del archivo de entrada, lee el archivo y almacena los datos, solicita al usuario que ingrese la ruta del archivo de salida, escribe los datos en el archivo de salida y finalmente cierra el programa.

### Precondiciones:
- Las funciones `path_verifier`, `read_file` y `write_file` deben estar definidas y funcionar correctamente.
- El archivo de entrada debe existir en la ruta proporcionada por el usuario y debe ser legible.
- La ruta de salida proporcionada por el usuario debe ser válida y el programa debe tener permisos para escribir en esa ubicación.

### Postcondiciones:
- Si todas las operaciones se completan con éxito, los datos se leen del archivo de entrada, se procesan y se escriben en el archivo de salida en la ubicación especificada.
- Si ocurre algún error durante el proceso, el programa se cierra.

### Descripción de los Argumentos:
Este bloque de código no toma argumentos.

### **Autor**: Eduardo A. Sosa Torres

### **Fecha de Finalización**: 26/03/2024