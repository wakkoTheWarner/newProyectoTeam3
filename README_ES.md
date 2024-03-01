
Para la versión en inglés de este documento, haz clic [aquí](README.md).

# Proyecto de Investigación en C++

Este proyecto de C++ es un sistema de registro de estudiantes universitarios. Lee datos de estudiantes de un archivo, los procesa y escribe los datos procesados en otro archivo. Los datos incluyen nombres de estudiantes, IDs, estado de registro, nivel y créditos. Se le pide al usuario que ingrese el nombre de la institución, el campus y el nombre del profesor. Los datos procesados, incluyendo el nombre de la institución, campus, departamento, semestre, nombre del profesor, curso y la tabla de información de los estudiantes, luego se escriben en un nuevo archivo llamado "output.csv".

## 🛠️ Instalación

Este proyecto requiere MinGW para compilar y ejecutar. El requisito mínimo de versión es MinGW 3.6.0-1 de 2019, pero la versión recomendada es MinGW w64 versión 11.0 o 12.0. El código ha sido probado en MinGW 3.6.0-1, MinGW w64 11.0 y 12.0.

### Instalación de MinGW

1. Descarga el Administrador de Instalación de MinGW desde [aquí](https://sourceforge.net/projects/mingw/).

2. Abre el archivo descargado y sigue las instrucciones para instalar el Administrador de Instalación de MinGW.

3. Una vez instalado, abre el Administrador de Instalación de MinGW.

4. Selecciona los paquetes que necesitas (al menos `mingw32-base` y `mingw32-gcc-g++`).

5. Aplica los cambios y espera a que se instalen los paquetes.

⚠️ **Advertencia**: Esta versión de MinGW está desactualizada. Úsala bajo tu propio riesgo.

Para una guía visual sobre cómo instalar MinGW, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=fzOmcmUcl_E).

### Instalación de MinGW w64

1. Descarga MSYS2 desde la [página oficial](https://www.msys2.org/) o directamente a través de este [enlace del instalador](https://www.msys2.org/).

2. Ejecuta el instalador y sigue las instrucciones en pantalla. Elige tu carpeta de instalación (lo usual es que la predeterminada esté bien) y asegúrate de marcar `Ejecutar MSYS2 ahora` al final.

3. Una vez instalado, abre el terminal de MSYS2.

4. En el terminal de MSYS2, ejecuta: `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`

5. Escribe `Y` y presiona Enter cuando se te pida para confirmar la instalación.

Para una guía visual sobre cómo instalar MinGW w64, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=DMWD7wfhgNY).

### Configuración de la Variable de Entorno MinGW

1. Abre las Propiedades del Sistema (Haz clic derecho en Computadora en el menú de inicio, o usa el atajo de teclado Win+Pausa)

2. Haz clic en Configuración avanzada del sistema

3. Haz clic en Variables de entorno

4. Bajo Variables del sistema, encuentra y selecciona la variable Path

5. Haz clic en Editar

6. En la ventana Editar variable del sistema, haz clic en Nuevo

7. Escribe la ruta a la carpeta bin de MinGW (por ejemplo, `C:\MinGW\bin` o `C:\msys64\mingw64\bin` para MinGW w64)

8. Haz clic en Aceptar en todas las ventanas para aplicar los cambios

Puede que necesites reiniciar cualquier ventana de comando abierta para que los cambios tengan efecto.

### Prueba de la Instalación

Después de instalar MinGW o MinGW w64, puedes probar si la instalación fue exitosa ejecutando los siguientes comandos en la línea de comandos:

```cmd
gcc --version
g++ --version
gdb --version
```

## 🏃‍♂️Cómo Ejecutar

Para ejecutar el código, necesitas tener MinGW instalado con una versión superior a `6.3.0-1` de 2019. El código también funciona con iteraciones actuales de MinGW (MinGW-w64 como 11.0 w64 la última versión de MSYS2 12.0 w64).

### Ejecutando en jGrasp

1. **Configura el espacio de trabajo**: Instala y abre jGrasp. Navega a `Configuración > PATH/CLASSPATH > Espacio de trabajo`. Desde el Espacio de trabajo, selecciona la pestaña `PATH`, luego selecciona la pestaña `PATHS`. Haz clic en `Nuevo` e inserta la ruta de tu directorio MinGW (Para MSYS2, es `C:\msys64\ucrt64`. Para MinGW 6.3.0-1 es `C:\MinGW`).

2. **Establece el compilador**: Ve a la pestaña `Compilador`, establece el lenguaje a `C++`, y en la pestaña `Entorno`, selecciona `g++ genérico`. Haz clic en `Aplicar` luego en `Cerrar`.

3. **Ejecuta el código**: En la pestaña `Examinar` en el lado izquierdo de jGrasp, navega a la ruta de la carpeta del proyecto y abre `main.cpp`. Haz clic en el ícono verde doble `+` en el encabezado para compilar y vincular los códigos, luego haz clic en el ícono rojo de ejecución para correr el archivo ejecutable `main.exe`.

Para una guía visual sobre cómo configurar el entorno de jGrasp y ejecutar un archivo C++, puedes ver este [video de YouTube](https://youtu.be/fzOmcmUcl_E?si=7SDH4_e3-i4Be46x&t=253).

### Ejecutando en Visual Studio Code

1. **Instala Visual Studio Code y MinGW**: Si aún no lo has hecho, instala Visual Studio Code y MinGW. Asegúrate de agregar MinGW al PATH de tu sistema.

2. **Instala la extensión de C++**: Ve a la vista de Extensiones (`Ver > Extensiones`), busca `c++`, y luego instala la extensión `C/C++` proporcionada por Microsoft.

3. **Abre el proyecto en Visual Studio Code**: Abre Visual Studio Code, luego ve a `Archivo > Abrir Carpeta` y selecciona la carpeta del proyecto.

4. **Ejecuta el código**: Haz clic en `Ejecutar o Depurar...` en la esquina superior derecha, haz clic en Ejecutar y selecciona `C/C++: g++ desde C:\msys64\mingw64\bin\g++.exe` para construir el código. Esto creará un archivo ejecutable en el mismo directorio que tu código fuente así como también lo ejecutará (puede que tengas que ejecutarlo 2 veces).

Para una guía visual sobre cómo configurar el entorno de Visual Studio Code y ejecutar un archivo C++, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=DMWD7wfhgNY).

## 🔧Uso

Este programa está diseñado para procesar datos de estudiantes de un archivo de texto y exportarlos en formato CSV. Aquí están los pasos para usar este programa:

1. **Compilar y Ejecutar el Programa**: Primero, compila el archivo `main.cpp` y ejecuta el ejecutable resultante. Esto iniciará el programa.

   Ejemplo:
   ```bash
   g++ main.cpp -o main
   ./main
   ```

2. **Ruta del Archivo de Entrada**: El programa te pedirá primero que ingreses la ruta del archivo de texto de entrada. Este archivo debe contener los datos de los estudiantes que deseas procesar. Puedes ingresar solo el nombre del archivo si el archivo está en el mismo directorio que el programa, o la ruta completa al archivo. Si el archivo tiene una extensión `.txt`, puedes incluirla, pero si no, el programa la agregará automáticamente por ti.

   Ejemplo:
   ```
   Ingresa la ruta del archivo: ./Resources/Data/student_data.txt
   ```

3. **Ingresar Información Adicional**: Luego, el programa te pedirá que ingreses información adicional que no está incluida en el archivo de entrada. Esto incluye el nombre de la institución, el recinto, el departamento y el nombre del profesor. Por favor, ingresa estos detalles como se te solicite.

   Ejemplo:
   ```
   Nombre de Institución: Universidad Interamericana de Puerto Rico
   Recinto: Campus Principal
   Departamento: Departamento de Ciencias de Computadoras
   Profesor: John Doe
   ```

4. **Ruta del Archivo de Salida**: Finalmente, el programa te pedirá que ingreses la ruta y nombre del archivo CSV de salida. Aquí se escribirán los datos procesados. Al igual que con el archivo de entrada, puedes ingresar solo el nombre del archivo si deseas que el archivo se cree en el mismo directorio que el programa, o la ruta completa al archivo. Si el archivo tiene una extensión `.csv`, puedes incluirla, pero si no, el programa la agregará automáticamente por ti.

   Ejemplo:
   ```
   Ingresa la ruta y nombre del archivo de salida: ../Resources/Output/student_output.csv
   ```

5. **Verificar la Salida**: Una vez que hayas ingresado toda la información requerida, el programa procesará los datos y los escribirá en el archivo de salida. Luego, imprimirá un mensaje diciéndote que los datos han sido exportados. Ahora puedes abrir el archivo de salida para ver los datos procesados.

   Ejemplo:
   ```
   Los datos se han exportado al archivo ../Resources/Output/student_output.csv
   ```

Por favor, ten en cuenta que este programa asume que el archivo de entrada está formateado correctamente y que todos los datos son válidos. Si el programa encuentra un error al leer el archivo, imprimirá un mensaje de error y terminará.

## 📕main.cpp

### Objetivo

La función principal de este programa es procesar una lista de estudiantes de un archivo de texto y convertirla en un formato CSV compatible con Excel. El programa solicita al usuario la ruta del archivo de entrada, lee y procesa los datos del archivo, solicita información adicional al usuario y, finalmente, escribe los datos procesados e información adicional en un archivo de salida.

### Pre-condiciones

- El usuario debe proporcionar una ruta de archivo válida para el archivo de entrada cuando se le solicite. Esto puede ser una cadena vacía, un nombre de archivo o una ruta de archivo completa.
- El archivo de entrada debe existir en la ruta proporcionada y debe ser legible.
- El usuario debe proporcionar información adicional válida cuando se le solicite.

### Post-condiciones

- Se crea un archivo de salida en la ruta especificada con los datos procesados e información adicional.
- Si no se puede abrir el archivo de entrada, el programa termina con un mensaje de error.

### Descripción de cada argumento

- `filePath`: Una cadena que representa la ruta del archivo de entrada. Se le solicita al usuario que ingrese esta ruta.
- `nombreInstitucion`: Una cadena que representa el nombre de la institución. Se le solicita al usuario que ingrese esta información.
- `recinto`: Una cadena que representa el recinto. Se le solicita al usuario que ingrese esta información.
- `departamento`: Una cadena que representa el departamento. Se le solicita al usuario que ingrese esta información.
- `profesor`: Una cadena que representa el nombre del profesor. Se le solicita al usuario que ingrese esta información.
- `outputFilePath`: Una cadena que representa la ruta del archivo de salida. Se le solicita al usuario que ingrese esta ruta.

### Información Adicional

- La función utiliza varias funciones auxiliares y clases para leer y procesar los datos del archivo de entrada, crear el encabezado para el archivo de salida y escribir los datos en el archivo de salida.
- La función verifica las rutas de archivo proporcionadas por el usuario y las ajusta según sea necesario.
- La función verifica si se puede abrir el archivo de entrada y termina con un mensaje de error si no es posible.
- La función informa al usuario cuando los datos han sido exportados al archivo de salida.

## 📕Students.cpp

### Objetivo

El código seleccionado representa la implementación de la clase `Estudiante` en C++. Esta clase se utiliza para representar a un estudiante con varios atributos como número, nombre, ID de estudiante, estado de registro, nivel, créditos, calificación de medio término, calificación final y detalles de la calificación. Proporciona métodos para obtener y establecer estos atributos.

### Pre-condiciones

- Para el constructor de `Estudiante`, todos los parámetros proporcionados deben ser válidos y no nulos.
- Para los métodos `set`, los valores proporcionados deben ser válidos y no nulos.

### Post-condiciones

- Después de la construcción, se crea un objeto `Estudiante` con los atributos proporcionados.
- Los métodos `get` devuelven el valor actual del atributo correspondiente.
- Los métodos `set` actualizan el valor del atributo correspondiente.

### Descripción de cada argumento

- `num`: Un entero que representa el número del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getNum` y `setNum`.
- `name`: Una cadena que representa el nombre del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getName` y `setName`.
- `studentId`: Una cadena que representa el ID del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getId` y `setId`.
- `registrationStatus`: Una cadena que representa el estado de registro del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getRegistrationStatus` y `setRegistrationStatus`.
- `level`: Una cadena que representa el nivel del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getLevel` y `setLevel`.
- `credits`: Una cadena que representa los créditos del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getCredits` y `setCredits`.
- `midterm`: Una cadena que representa la calificación de medio término del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getMidterm` y `setMidterm`.
- `final`: Una cadena que representa la calificación final del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getFinal` y `setFinal`.
- `gradeDetail`: Una cadena que representa los detalles de la calificación del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos `getGradeDetail` y `setGradeDetail`.

### Información Adicional

- La clase `Estudiante` es una simple clase de datos sin comportamiento más allá de almacenar y recuperar sus atributos.
- Los métodos `get` son todos `const`, lo que significa que no modifican el objeto y se pueden llamar en objetos `const`.
- Los métodos `set` no son `const`, lo que significa que modifican el objeto y no se pueden llamar en objetos `const`.
- La clase `Estudiante` no gestiona ningún recurso, por lo que no necesita definir un destructor, constructor de copia o operador de asignación de copia. Los proporcionados por defecto por el compilador son suficientes.

## 📝 Autores

Esta sección enumera a los autores que contribuyeron a los diferentes archivos en el proyecto:

- `main.cpp`: Eduardo A. Sosa Torres
- `FileParser.cpp`/`FileParser.h`: [PREDETERMINADO]
- `FileReader.cpp`/`FileReader.h`: [PREDETERMINADO]
- `FileWriter.cpp`/`FileWriter.h`: [PREDETERMINADO]
- `HeaderMaker.cpp`/`HeaderMaker.h`: [PREDETERMINADO]
- `Students.cpp`/`Students.h`: [PREDETERMINADO]
- `README.md`: Eduardo A. Sosa Torres
- Hizo el código ejecutable en jGrasp: Eduardo A. Sosa Torres

## 📋[TEMPORARY] To-Do

### Coding Requirements
- [✔️] Develop a C++ application that processes content from a Studlist-generated page, saved in a text file, into a CSV format compatible with Excel.
- [✔️] The application must request additional information not included in the Studlist file (e.g., name of the institution, campus) from the user.
- [✔️] The application should prompt the user for the name of the input text file and the output CSV file.
- [✔️] Ensure the application can handle any number of student records, from 1 to many.
- [] The program must be well-documented, with detailed comments on functions and methods, including objective, pre-conditions, post-conditions, argument descriptions, author, and date of completion.
    - [] Word Documentation
    - [✔️] Comment Documentation
    - [✔️] Function Documentation

### Turnable Requirements:
- [] A single file containing all the program code.
- [] A video (5-10 minutes, mp4 format) demonstrating the application's functionality, including a walkthrough of the code and examples of executions. The video must have clear voice explanations and legible on-screen text.
- [] Test files used in the video and for program testing, showcasing the application's capability to load and process data.
- [] A peer evaluation document as provided by the professor, filled out and submitted individually.
- [] All files (code, video, tests, peer evaluation) must be named according to the format COMP3800MemberCpp## and compressed into a single folder for submission.