
# C++ Investigation Project

This C++ project is a university student registration system. It reads student data from a file, processes it, and writes the processed data to another file. The data includes student names, IDs, registration status, level, and credits. The user is prompted to input the institution's name, campus, and professor's name. The processed data, including the institution's name, campus, department, semester, professor's name, course, and the table of students' information, is then written to a new file named "output.csv".

## 🔧Usage

```c++
$ ./main
Ingresa la ruta del archivo: /path/to/input.txt
Nombre de Institucion: My Institution
Recinto: My Campus
Departamento: My Department
Profesor: My Professor
Ingresa la ruta y nombre del archivo de salida: /path/to/output.csv
Los datos se han exportado al archivo /path/to/output.csv
```

## 🏃‍♂️How to Run

To run the code, you need to have MinGW installed with a release higher than `6.3.0-1` from 2019. The code also works with current iterations of MinGW (MinGW-w64 such as 11.0 w64 the latest version of MSYS2 12.0 w64).

### Running in jGrasp

1. **Set up the workspace**: Install and open jGrasp. Navigate to `Settings > PATH/CLASSPATH > Workspace`. From the Workspace, select the `PATH` tab, then select the `PATHS` tab. Click on `New` and insert the path of your MinGW directory (For MSYS2, it's `C:\msys64\ucrt64`. For MinGW 6.3.0-1 it's `C:\MinGW`).

2. **Set the compiler**: Go to the `Compiler` tab, set the language to `C++`, and in the `Environment` tab, select `g++ generic`. Click `Apply` then `Close`.

3. **Run the code**: In the `Browse` tab on the left side of jGrasp, navigate to the path of the project folder and open `main.cpp`. Click on the double green `+` icon in the header to compile and link the codes, then click on the red running icon to run the `main.exe` executable file.

For a visual guide on setting up the jGrasp environment and running a C++ file, you can watch this [YouTube video](https://youtu.be/fzOmcmUcl_E?si=7SDH4_e3-i4Be46x&t=253).

### Running in Visual Studio Code

1. **Install Visual Studio Code and MinGW**: If you haven't already, install Visual Studio Code and MinGW. Make sure to add MinGW to your system's PATH.

2. **Install the C++ extension**: Go to the Extensions view (`View > Extensions`), search for `c++`, and then install the `C/C++` extension provided by Microsoft.

3. **Open the project in Visual Studio Code**: Open Visual Studio Code, then go to `File > Open Folder` and select the project folder.

4. **Run the code**: Click `Run or Debug...` on the top right corner, click Run and select `C/C++: g++ from C:\msys64\mingw64\bin\g++.exe` to build the code. This will create an executable file in the same directory as your source code as well as run it (might have to run it 2 times).

For a visual guide on setting up the Visual Studio Code environment and running a C++ file, you can watch this [YouTube video](https://www.youtube.com/watch?v=DMWD7wfhgNY).

## 🔧Usage

```c++
$ ./main
Ingresa la ruta del archivo: /path/to/input.txt
Nombre de Institucion: My Institution
Recinto: My Campus
Departamento: My Department
Profesor: My Professor
Ingresa la ruta y nombre del archivo de salida: /path/to/output.csv
Los datos se han exportado al archivo /path/to/output.csv
```

## 📕main.cpp

### Objective

The main function of this program is to process a student list from a text file and convert it into a CSV format compatible with Excel. The program prompts the user for the input file path, reads and processes the data from the file, requests additional information from the user, and finally writes the processed data and additional information to an output file.

### Pre-conditions

- The user must provide a valid file path for the input file when prompted. This can be an empty string, a file name, or a full file path.
- The input file must exist at the provided path and must be readable.
- The user must provide valid additional information when prompted.

### Post-conditions

- An output file is created at the specified path with the processed data and additional information.
- If the input file cannot be opened, the program terminates with an error message.

### Description of each argument

- `filePath`: A string that represents the path of the input file. The user is prompted to enter this path.
- `nombreInstitucion`: A string that represents the name of the institution. The user is prompted to enter this information.
- `recinto`: A string that represents the campus. The user is prompted to enter this information.
- `departamento`: A string that represents the department. The user is prompted to enter this information.
- `profesor`: A string that represents the professor's name. The user is prompted to enter this information.
- `outputFilePath`: A string that represents the path of the output file. The user is prompted to enter this path.

### Additional Information

- The function uses several helper functions and classes to read and process the data from the input file, create the header for the output file, and write the data to the output file.
- The function verifies the file paths provided by the user and adjusts them as necessary.
- The function checks if the input file can be opened and terminates with an error message if it cannot.
- The function informs the user when the data has been exported to the output file.

## 📕Students.cpp

### Objective

The selected code represents the implementation of the `Student` class in C++. This class is used to represent a student with various attributes such as number, name, student ID, registration status, level, credits, midterm grade, final grade, and grade details. It provides methods to get and set these attributes.

### Pre-conditions

- For the `Student` constructor, all provided parameters must be valid and non-null.
- For the `set` methods, the provided values must be valid and non-null.

### Post-conditions

- After construction, a `Student` object is created with the provided attributes.
- The `get` methods return the current value of the corresponding attribute.
- The `set` methods update the value of the corresponding attribute.

### Description of each argument

- `num`: An integer that represents the student's number. This is both a parameter for the constructor and the subject of the `getNum` and `setNum` methods.
- `name`: A string that represents the student's name. This is both a parameter for the constructor and the subject of the `getName` and `setName` methods.
- `studentId`: A string that represents the student's ID. This is both a parameter for the constructor and the subject of the `getId` and `setId` methods.
- `registrationStatus`: A string that represents the student's registration status. This is both a parameter for the constructor and the subject of the `getRegistrationStatus` and `setRegistrationStatus` methods.
- `level`: A string that represents the student's level. This is both a parameter for the constructor and the subject of the `getLevel` and `setLevel` methods.
- `credits`: A string that represents the student's credits. This is both a parameter for the constructor and the subject of the `getCredits` and `setCredits` methods.
- `midterm`: A string that represents the student's midterm grade. This is both a parameter for the constructor and the subject of the `getMidterm` and `setMidterm` methods.
- `final`: A string that represents the student's final grade. This is both a parameter for the constructor and the subject of the `getFinal` and `setFinal` methods.
- `gradeDetail`: A string that represents the student's grade details. This is both a parameter for the constructor and the subject of the `getGradeDetail` and `setGradeDetail` methods.

### Additional Information

- The `Student` class is a simple data class with no behavior beyond storing and retrieving its attributes.
- The `get` methods are all `const`, meaning they do not modify the object and can be called on `const` objects.
- The `set` methods are not `const`, meaning they modify the object and cannot be called on `const` objects.
- The `Student` class does not manage any resources, so it does not need to define a destructor, copy constructor, or copy assignment operator. The default ones provided by the compiler are sufficient.

## 📝 Authors

This section lists the authors who contributed to the different files in the project:

- `main.cpp`: Eduardo A. Sosa Torres
- `FileParser.cpp`/`FileParser.h`: [DEFAULT]
- `FileReader.cpp`/`FileReader.h`: [DEFAULT]
- `FileWriter.cpp`/`FileWriter.h`: [DEFAULT]
- `HeaderMaker.cpp`/`HeaderMaker.h`: [DEFAULT]
- `Students.cpp`/`Students.h`: [DEFAULT]
- `README.md`: Eduardo A. Sosa Torres
- Made the code runnable in jGrasp: Eduardo A. Sosa Torres

## 📋[TEMPORARY] To-Do

### Coding Requirements:

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
 