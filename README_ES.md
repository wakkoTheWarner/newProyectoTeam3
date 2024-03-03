
Para la versión en Inglés de este documento, haga clic [aquí](README.md).

# Proyecto de Investigación en C++

Este proyecto en C++ es un sistema de registro de estudiantes universitarios. Lee los datos de los estudiantes de un archivo, los procesa y escribe los datos procesados en otro archivo. Los datos incluyen nombres de los estudiantes, ID, estado de registro, nivel y créditos. Se le solicita al usuario que ingrese el nombre de la institución, el campus y el nombre del profesor. Los datos procesados, incluyendo el nombre de la institución, campus, departamento, semestre, nombre del profesor, curso y la tabla de información de los estudiantes, se escriben entonces en un nuevo archivo llamado "output.csv".

## 🛠️ Instalación

Este proyecto requiere MinGW para compilar y ejecutar. El requisito mínimo de versión es MinGW 3.6.0-1 de 2019, pero la versión recomendada es MinGW w64 versión 11.0 o 12.0. El código ha sido probado en MinGW 3.6.0-1, MinGW w64 11.0 y 12.0.

### Instalación de MinGW

1. Descarga el Gestor de Instalación de MinGW desde [aquí](https://sourceforge.net/projects/mingw/).

2. Abre el archivo descargado y sigue las instrucciones para instalar el Gestor de Instalación de MinGW.

3. Una vez instalado, abre el Gestor de Instalación de MinGW.

4. Selecciona los paquetes que necesitas (al menos `mingw32-base` y `mingw32-gcc-g++`).

5. Aplica los cambios y espera a que los paquetes se instalen.

⚠️ **Advertencia**: Esta versión de MinGW está desactualizada. Úsala bajo tu propio riesgo. ⚠️

Para una guía visual sobre cómo instalar MinGW, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=fzOmcmUcl_E).

### Instalación de MinGW w64

1. Descarga MSYS2 de la [página oficial](https://www.msys2.org/) o directamente a través de este [enlace del instalador](https://www.msys2.org/).

2. Ejecuta el instalador y sigue las instrucciones en pantalla. Elige tu carpeta de instalación (la predeterminada suele estar bien) y asegúrate de marcar `Ejecutar MSYS2 ahora` al final.

3. Una vez instalado, abre el terminal de MSYS2.

4. En el terminal de MSYS2, ejecuta: `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`

5. Escribe `Y` y presiona Enter cuando se te pida confirmar la instalación.

Para una guía visual sobre cómo instalar MinGW w64, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=DMWD7wfhgNY).

### Configuración de la Variable de Entorno de MinGW

1. Abre las Propiedades del Sistema (Haz clic derecho en Computadora en el menú de inicio, o usa el atajo de teclado Win+Pause)

2. Haz clic en Configuración avanzada del sistema

3. Haz clic en Variables de entorno

4. Bajo Variables del sistema, encuentra y selecciona la variable Path

5. Haz clic en Editar

6. En la ventana Editar variable del sistema, haz clic en Nuevo

7. Escribe la ruta a la carpeta bin de MinGW (por ejemplo, `C:\MinGW\bin` o `C:\msys64\mingw64\bin` para MinGW w64)

8. Haz clic en Aceptar en todas las ventanas para aplicar los cambios

Puede que necesites reiniciar cualquier ventana de comando abierta para que los cambios surtan efecto.

### Prueba de Instalación

Después de instalar MinGW o MinGW w64, puedes probar si la instalación fue exitosa ejecutando los siguientes comandos en el símbolo del sistema:

```cmd
gcc --version
g++ --version
gdb --version
```

## 🏃‍♂️Cómo Ejecutar

Para ejecutar el código, necesitas tener MinGW instalado con una versión superior a `6.3.0-1` de 2019. El código también funciona con iteraciones actuales de MinGW (MinGW-w64 como 11.0 w64 la última versión de MSYS2 12.0 w64).

### Ejecutando en jGrasp

1. **Configura el espacio de trabajo**: Instala y abre jGrasp. Navega a `Configuraciones > PATH/CLASSPATH > Espacio de trabajo`. Desde el Espacio de trabajo, selecciona la pestaña `PATH`, luego la pestaña `PATHS`. Haz clic en `Nuevo` e inserta la ruta de tu directorio MinGW (Para MSYS2, es `C:\msys64\ucrt64`. Para MinGW 6.3.0-1 es `C:\MinGW`).

2. **Establece el compilador**: Ve a la pestaña `Compilador`, establece el lenguaje a `C++`, y en la pestaña `Entorno`, selecciona `g++ genérico`. Haz clic en `Aplicar` y luego en `Cerrar`.

3. **Ejecuta el código**: En la pestaña `Explorar` en el lado izquierdo de jGrasp, navega a la ruta de la carpeta del proyecto y abre `main.cpp`. Haz clic en el icono verde doble `+` en el encabezado para compilar y enlazar los códigos, luego haz clic en el icono rojo de ejecución para correr el archivo ejecutable `main.exe`.

Para una guía visual sobre cómo configurar el entorno de jGrasp y ejecutar un archivo C++, puedes ver este [video de YouTube](https://youtu.be/fzOmcmUcl_E?si=7SDH4_e3-i4Be46x&t=253).

### Ejecutando en Visual Studio Code

1. **Instala Visual Studio Code y MinGW**: Si aún no lo has hecho, instala Visual Studio Code y MinGW. Asegúrate de agregar MinGW al PATH de tu sistema.

2. **Instala la extensión de C++**: Ve a la vista de Extensiones (`Ver > Extensiones`), busca `c++`, y luego instala la extensión `C/C++` proporcionada por Microsoft.

3. **Abre el proyecto en Visual Studio Code**: Abre Visual Studio Code, luego ve a `Archivo > Abrir Carpeta` y selecciona la carpeta del proyecto.

4. **Ejecuta el código**: Haz clic en `Ejecutar o Depurar...` en la esquina superior derecha, haz clic en Ejecutar y selecciona `C/C++: g++ desde C:\msys64\mingw64\bin\g++.exe` para construir el código. Esto creará un archivo ejecutable en el mismo directorio que tu código fuente así como también lo ejecutará (puede que tengas que ejecutarlo 2 veces).

Para una guía visual sobre cómo configurar el entorno de Visual Studio Code y ejecutar un archivo C++, puedes ver este [video de YouTube](https://www.youtube.com/watch?v=DMWD7wfhgNY).

## 🔧Uso

### Cómo Usar

Este programa está diseñado para procesar datos de estudiantes de un archivo de texto y exportarlos en formato CSV. Aquí están los pasos para usar este programa:

1. **Compila y Ejecuta el Programa**: Para iniciar el programa, tienes dos opciones basadas en tu entorno de desarrollo:

   - Si usas una interfaz de línea de comandos (CLI), primero compila el archivo `main.cpp` y luego ejecuta el ejecutable resultante con los siguientes comandos:

     Ejemplo:
     ```bash
     g++ main.cpp -o main
     ./main
     ```

   - Alternativamente, si usas un Entorno de Desarrollo Integrado (IDE) como jGrasp, simplemente haz clic en el botón **Compilar y Enlazar**, luego en el botón **Ejecutar**.

2. **Ruta del Archivo de Entrada**: El programa primero te pedirá que ingreses la ruta del archivo de texto de entrada. Este archivo debe contener los datos de los estudiantes que deseas procesar. Puedes ingresar solo el nombre del archivo si el archivo está en el mismo directorio que el programa, o la ruta completa al archivo. Si el archivo tiene una extensión `.txt`, puedes incluirla, pero si no, el programa la agregará automáticamente por ti.

   Ejemplo:
   ```
   Ingresa la ruta del archivo: ./Resources/Data/student_data.txt
   ```

3. **Ingresa Información Adicional**: Luego, el programa te pedirá que ingreses información adicional que no está incluida en el archivo de entrada. Esto incluye el nombre de la institución, el recinto, el departamento y el nombre del profesor. Por favor, ingresa estos detalles según se te solicite.

   Ejemplo:
   ```
   Nombre de Institucion: Universidad Interamericana de Puerto Rico
   Recinto: Recinto Principal
   Departamento: Departamento de Ciencias de Computadoras
   Profesor: John Doe
   ```

4. **Ruta del Archivo de Salida**: Finalmente, el programa te pedirá que ingreses la ruta y el nombre del archivo CSV de salida. Aquí se escribirán los datos procesados. Al igual que con el archivo de entrada, puedes ingresar solo el nombre del archivo si deseas que el archivo se cree en el mismo directorio que el programa, o la ruta completa al archivo. Si el archivo tiene una extensión `.csv`, puedes incluirla, pero si no, el programa la agregará automáticamente por ti.

   Ejemplo:
   ```
   Ingresa la ruta y nombre del archivo de salida: ./Resources/Output/student_output.csv
   ```

5. **Revisa la Salida**: Una vez que hayas ingresado toda la información requerida, el programa procesará los datos y los escribirá en el archivo de salida. Luego imprimirá un mensaje diciéndote que los datos han sido exportados. Ahora puedes abrir el archivo de salida para ver los datos procesados.

   Ejemplo:
   ```
   Los datos se han exportado al archivo ./Resources/Output/student_output.csv
   ```

Ten en cuenta que este programa asume que el archivo de entrada está formateado correctamente y que todos los datos son válidos. Si el programa encuentra un error al leer el archivo, imprimirá un mensaje de error y terminará.

## 📂Estructura de Archivos

El proyecto está organizado en una estructura de carpetas simple. Aquí está la estructura de archivos del proyecto:

```
Project
│   CMakeLists.txt
│   Documentacion del Proyecto.html
│   main.cpp
│   main.exe
│   README.md
│   README_ES.md
│
└───Resources
    │
    └───Data
    │   │   student_data.txt
    │
    └───Output
        │   student_output.csv
```

- `CMakeLists.txt`: Archivo de configuración de CMake para compilar el proyecto. No es necesario para compilar y ejecutar el proyecto en jGrasp o Visual Studio Code.
- `Documentacion del Proyecto.html`: Documentación del proyecto en formato HTML.
- `main.cpp`: Archivo fuente principal del proyecto.
- `main.exe`: Archivo ejecutable del proyecto.
- `README.md`: Archivo README en inglés.
- `README_ES.md`: Archivo README en español.
- `Resources`: Carpeta que contiene los archivos de datos de entrada y salida.
  - `Data`: Carpeta que contiene el archivo de datos de entrada.
  - `Output`: Carpeta que contiene el archivo de datos de salida.
  - `student_data.txt`: Archivo de datos de entrada.
  - `student_output.csv`: Archivo de datos de salida.

## 📋Características

- **Lectura de Archivos**: El programa lee los datos de los estudiantes de un archivo de texto.
- **Procesamiento de Datos**: El programa procesa los datos de los estudiantes y los almacena en una estructura de datos.
- **Escritura de Archivos**: El programa escribe los datos procesados en un archivo CSV.
- **Interfaz de Usuario**: El programa solicita al usuario que ingrese información adicional que no está incluida en el archivo de entrada.
- **Validación de Datos**: El programa asume que los datos de entrada son válidos y están formateados correctamente.
- **Documentación del Proyecto**: El proyecto incluye un archivo de documentación en formato HTML.
- **Soporte de Idiomas**: El proyecto incluye un archivo README en inglés y en español.
- **Estructura de Archivos**: El proyecto está organizado en una estructura de carpetas simple.
- **Compilación y Ejecución**: El proyecto se puede compilar y ejecutar en jGrasp y Visual Studio Code.
- **Configuración de Entorno**: El proyecto incluye instrucciones para instalar MinGW y MinGW w64, así como para configurar el entorno de jGrasp y Visual Studio Code.
- **Uso del Programa**: El proyecto incluye instrucciones sobre cómo usar el programa.
- **Autores**: El proyecto incluye una sección de autores que enumera a los contribuyentes del proyecto.

## 📦Estructura del Código

El proyecto está estructurado en torno a varios componentes clave, cada uno con un rol específico:

1. `main.cpp`: Este es el archivo fuente principal del proyecto. Contiene la función `main()` que es el punto de entrada del programa. La función `main()` maneja la interacción del usuario, la lectura y escritura de archivos, y el procesamiento de datos.

    - `filePathValidator()`: Esta función valida la ruta del archivo de entrada. Si la ruta es válida, devuelve `true`, de lo contrario, devuelve `false`. Si la ruta es inválida, imprime un mensaje de error.
    - `outputFilePathValidator()`: Esta función valida la ruta del archivo de salida. Si la ruta es válida, devuelve `true`, de lo contrario, devuelve `false`. Si la ruta es inválida, imprime un mensaje de error.


2. `Student`: Esta clase representa a un estudiante con varios atributos como número, nombre, ID del estudiante, estado de registro, nivel, créditos, calificación de mitad de período, calificación final y detalles de la calificación. Proporciona métodos para obtener y establecer estos atributos.

    - `getStudentNumber()`: Este método devuelve el número del estudiante.
    - `getStudentName()`: Este método devuelve el nombre del estudiante.
    - `getStudentID()`: Este método devuelve el ID del estudiante.
    - `getRegistrationStatus()`: Este método devuelve el estado de registro del estudiante.
    - `getLevel()`: Este método devuelve el nivel del estudiante.
    - `getCredits()`: Este método devuelve los créditos del estudiante.
    - `getMidtermGrade()`: Este método devuelve la calificación de mitad de período del estudiante.
    - `getFinalGrade()`: Este método devuelve la calificación final del estudiante.
    - `getGradeDetails()`: Este método devuelve los detalles de la calificación del estudiante.
    - `setStudentNumber()`: Este método establece el número del estudiante.
    - `setStudentName()`: Este método establece el nombre del estudiante.
    - `setStudentID()`: Este método establece el ID del estudiante.
    - `setRegistrationStatus()`: Este método establece el estado de registro del estudiante.
    - `setLevel()`: Este método establece el nivel del estudiante.
    - `setCredits()`: Este método establece los créditos del estudiante.
    - `setMidtermGrade()`: Este método establece la calificación de mitad de período del estudiante.
    - `setFinalGrade()`: Este método establece la calificación final del estudiante.
    - `setGradeDetails()`: Este método establece los detalles de la calificación del estudiante.


3. `FileReader`: Esta clase se utiliza para leer un archivo de texto en formato CSV y extraer datos de estudiantes. Los datos incluyen el número del estudiante, nombre, ID del estudiante, estado de registro, nivel, créditos, calificación de mitad de período, calificación final y detalles de la calificación.


4. `FileParser`: Esta clase se utiliza para analizar un archivo y extraer información relevante del curso. La información extraída incluye el nombre del curso, el número de registro del curso (CRN) y la duración del curso.

    - `modifyDuration()`: Esta función se utiliza para modificar la duración de un curso. La duración se proporciona en el formato "Fecha de inicio - Fecha de finalización", y la función la modifica para que esté en el formato "MES_INICIO-MES_FINAL AÑO". Además, traduce los nombres de los meses al español.
    - `monthTranslator()`: Esta función se utiliza para traducir los nombres de los meses del inglés al español.


5. `HeaderMaker`: Esta clase se utiliza para crear un encabezado con los datos proporcionados. El encabezado incluye el nombre de la universidad, ubicación del campus, nombre del departamento, semestre, nombre del profesor, nombre del curso y CRN.


6. `FileWriter`: Esta clase se utiliza para crear un archivo de texto en formato CSV, donde se escriben los datos de los estudiantes. Esto simplifica el proceso de escritura de datos en archivos.


Cada uno de estos componentes juega un papel crucial en la funcionalidad general del proyecto. El archivo `main.cpp` orquesta el proceso, utilizando las otras clases para leer, procesar y escribir datos.

## 📝 Autores

Esta sección enumera a los autores que contribuyeron a los diferentes archivos en el proyecto:

- `main.cpp`: Eduardo A. Sosa Torres
- `FileParser`: Ian P. Roman
- `FileReader`: Christian J. Santiago Rivera
- `FileWriter`: Javier Santos Babilonia
- `HeaderMaker`: Azkaria L. Rosado Rodriguez
- `Students`: Eduardo A. Sosa Torres
- `README.md`: Eduardo A. Sosa Torres
