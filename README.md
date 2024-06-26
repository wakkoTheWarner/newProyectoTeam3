
# Python Investigation Project

This Python project is a university student registration system. It reads student data from a file, processes it, and writes the processed data to another file. The data includes student names, IDs, registration status, level, and credits. The user is prompted to input the institution's name, campus, and professor's name. The processed data, including the institution's name, campus, department, semester, professor's name, course, and the table of students' information, is then written to a new file named "output.csv".
## 🛠️ Installation

This project was developed in Python 3.10.12 and requires Python 3.10.12 or newer.

### Python 3 Installation

1. **Python 3.10.12 Download**
   - Visit the [official Python website](https://www.python.org/downloads/) to download Python 3.10.12. Ensure you download the version appropriate for your operating system (Windows, macOS, Linux/UNIX).

2. **Run the installer**.
   - Make sure to check the box that says "Add Python 3.x to PATH" to ensure that the Python interpreter can be found by your system. (If done, you can skip the Enviroment Variable Set-up)

3. Follow the installation prompts and finish the setup.

4. To verify the installation, open Command Prompt and type `python --version`. You should see the Python version you installed.

For a visual guide on installing Python3, you can watch this [YouTube video](https://www.youtube.com/watch?v=9o4gDQvVkLU).

### Enviroment Variable Set-up

1. Open the System Properties (Right click Computer in the start menu, or use the keyboard shortcut Win+Pause)

2. Click Advanced system settings

3. Click Environment Variables

4. Under System Variables, find and select the Path variable

5. Click Edit

6. In the Edit System Variable window, click New

7. Type the path to the Python3 bin folder (e.g., `C:\Python3???`)

8. Click OK in all windows to apply the changes

You may need to restart any open command prompt windows for changes to take effect.

### Testing Installation

After installing Python3, you can test whether the installation was successful by running the following commands in the command prompt:

```cmd
python3 --version
```

## 🏃‍♂️How to Run

### Running in Visual Studio Code
1. Install Visual Studio Code and/or Python3
   - If you haven't already, install Visual Studio Code and/or Python3. Make sure to add Python3 to your system's PATH if you haven't.

2. Install the Python extension in VS Code
   - Go to the Extensions view (`View > Extensions`), search for `python`, and then install the `python` extension provided by Microsoft.

3. Open the project in Visual Studio Code
   - Open Visual Studio Code, then go to `File > Open Folder` and select the project folder.

4. Run the code: 
   - Click `Run Python File` or `Debug Python File` in the top right corner to execute the code.

For a visual guide on setting up the Visual Studio Code environment and running a Python file, you can watch this [YouTube video](https://www.youtube.com/watch?v=9o4gDQvVkLU).

## 🔧 Usage

### How to Use

This program is designed to process student data from a text file and output it in a CSV format. Here are the steps to use this program:

1. **Run the Program**
   - To start the program, you can use a command-line interface (CLI). Navigate to the project's directory and run the Python script using the following command:

      ```bash
      python3 main.py
      ```

   - If you're using an Integrated Development Environment (IDE) like PyCharm or Visual Studio Code, you can run the script by opening `main.py` and using the IDE's run functionality.


2. **Input File Path**
   - After starting the program, it will ask you to enter the path of the input text file. This file should contain the student data that you want to process. You can enter just the file name if the file is in the same directory as the program, or the full path to the file. If the file has a `.txt` extension, include it in your input.

      ```
      Ingrese la ruta del archivo: 
      ```
     
      - Valid input file formats:
      
         > C:\Users\user\Documents\student_data.txt
         
         > student_data.txt
         
         > student_data

3. **Enter Additional Information**
   - The program will then prompt you to enter additional information not included in the input file. This includes the name of the institution, the campus, the department, and the professor's name. Please enter these details as prompted.

      ```
      Ingrese el nombre de la universidad:
      Ingrese el recinto de la universidad:
      Ingrese el departamento de la universidad:
      Ingrese el nombre del profesor:
      ```
   
      - Valid input file formats:
      
         > Universidad Interamericana de Puerto Rico
         >
         > Recinto de Aguadilla
         > 
         > Ciencias en Computadoras
         >
         > Jose Detal

         > (Press Enter to use default values)

4. **Output File Path**
   - Finally, the program will ask you to enter the path and name of the output CSV file. This is where the processed data will be written. As with the input file, you can enter just the file name if you want the file to be created in the same directory as the program, or the full path to the file. If the file has a `.csv` extension, include it in your input.

      ```
      Ingrese la ruta del archivo de salida: student_output.csv
      ```
     
      - Valid output file formats:
      
         > C:\Users\user\Documents\student_output.csv
         
         > student_output.csv
         
         > student_output

5. **Check the Output**
   - Once you've entered all the required information, the program will process the data and write it to the output file. It will then print a message informing you that the data has been exported. You can now open the output file to view the processed data.

      ```
      El archivo ha sido creado exitosamente.
      ```

Please note that this program assumes the input file is formatted correctly and that all the data is valid. If the program encounters an error while reading the file, it will print an error message and terminate.

## 📂 File Structure

The project is organized in a simple folder structure. Here is the file structure of the project:

```
Project
│   Project Documentation.html
│   main.py
│   README.md
│
└───Resources
    │
    └───Data
    │   │   student_data.txt
    │
    └───Output
        │   student_output.csv
```

- Project Documentation.html: Project documentation in HTML format.
- main.py: Main Python script that processes student data.
- README.md: Project README file.
- Resources: Folder that contains the input and output data files.
  - Data: Folder that contains the input data file.
    - student_data.txt: Input data file.
  - Output: Folder that contains the output data file.
    - student_output.csv: Output data file.

## 📋 Characteristics

- **Input File Format**: The input file should be a text file containing student data. Each line in the file should represent a student and contain the student's number, name, and ID, separated by commas. The file should not contain any headers or additional information.

   - Example input file format:
   
      ```
      Course Information
      NEURAL NETWORKS - COMP 1234 0
      CRN:	12345
      Duration:	22 Jan, 2024 - 18 May, 2024
      Status:	Open
      
      Enrollment Counts
          Maximum	Actual	Remaining
      Enrollment:	29	11	18
      Cross List: 	0	0	0
      
      Summary Class List
      Record
      Number	Student Name	ID	Reg Status	Level	Credits	Midterm	Final	Grade Detail
        1	John Doe	Z00123456	** Registered **	UNDERGRADUATE	3.000	Enter	Enter	Available
        2	Jane Smith	Z00987654	** Registered **	UNDERGRADUATE	3.000	Enter	Enter	Available
        3	Alice Johnson	Z00543210	** Registered **	UNDERGRADUATE	3.000	Enter	Enter	Available
      ```

- **Output File Format**: The output file is a CSV file that contains the processed student data. The file includes the institution's name, campus, department, professor's name, semester, course, and a table of student information. The student information includes the student's number, name, and ID, separated by commas.

    - Example output file format:
    
        ```
        , Universidad Interamericana de Puerto Rico
        , Recinto de Aguadilla
        , Ciencias en Computadoras
        
        SEMESTRE: ENERO-MAYO 2022
        PROF: Jose Detal
        CURSO: Programación en Python
        
        Num, Nombre, Matrícula
        "1", "Jon Doe", "Z00123456"
        "2", "Jane Smith", "Z00987654"
        "3", "Alice Johnson", "Z00543210"
        ```
      
- **University Information**: The program prompts the user to enter the institution's name, campus, department, and professor's name. If the user does not provide this information, the program uses default values.

- **Semester Parsing**: The program parses the semester information from the input file and converts it to a standard format (e.g., "January-May 2022" to "ENERO-MAYO 2022").

- **Course Parsing**: The program parses the course and section information from the input file and combines them into a single course name (e.g., "Programming - Section 1" to "Programación").

- **Student Class**: The program defines a `Student` class to represent student information. The class has attributes for the student's number, name, and ID, and a method to return a string representation of the student.

- **CSV Output**: The program writes the processed data to a CSV file with the institution's information, semester, professor's name, course, and a table of student information.

- **Error Handling**: The program includes error handling to check for invalid file paths and input data. If an error occurs, the program prints an error message and exits.

- **User Interaction**: The program interacts with the user through the command line interface (CLI). It prompts the user to enter the input file path, institution information, and output file path.

## 📦 Code Structure

The Python code for this project is organized into several functions that handle different aspects of the program. Here is an overview of the code structure:

1. `if __name__ == '__main__':` - This line checks if the script is being run directly or imported as a module. The code inside this block will only run if the script is run directly.

   - `path_to_file = path_verifier(0)` - This line calls the `path_verifier` function with an argument of `0`, which prompts the user to enter the path of the input file. The function verifies the path and returns it. The path is then stored in the `path_to_file` variable.

   - `header, students = read_file(path_to_file)` - This line calls the `read_file` function with the `path_to_file` as an argument. The function reads the file, processes the header and student data, and returns them. The returned data is then stored in the `header` and `students` variables.

   - `output_path = path_verifier(1)` - This line calls the `path_verifier` function with an argument of `1`, which prompts the user to enter the path of the output file. The function verifies the path and returns it. The path is then stored in the `output_path` variable.

   - `write_file(output_path, header, students)` - This line calls the `write_file` function with the `output_path`, `header`, and `students` as arguments. The function writes the processed data to the output file.

   - `exit(0)` - This line terminates the program.


2. `path_verifier()` - This function prompts the user to enter a file path and verifies that the path is valid. It takes an argument `mode` that determines whether the function is verifying the input file path (`mode = 0`) or the output file path (`mode = 1`). The function returns the verified file path.

   - `if check == 0:` - This block of code is executed when the function is called with an argument of 0. It prompts the user to enter the path of the input file. The function verifies the path and returns it. If the user fails to provide a valid path after 3 attempts, the program exits.  

   - `elif check == 1:` - This block of code is executed when the function is called with an argument of 1. It prompts the user to enter the path of the output file. The function verifies the path and returns it. If the user fails to provide a valid path after 3 attempts, the program exits.  

   - `exit(0)` - This line is executed if none of the above conditions are met, causing the program to exit.

   
3. `read_file(path_to_file)` - This function reads the input file, processes the header and student data, and returns them. It takes the `path_to_file` as an argument and returns the `header` and `students` data.
    
    - `header = []`, `students = []`, `header_text = ""`, `counter = 0` - These lines initialize the variables that will be used in the function.

   - `with open(path_to_file, "r") as file:` - This line opens the file at the path specified by `path_to_file` in read mode.

   - The for loop `for line in file:` iterates over each line in the file.

   - `if line.strip() != "" and counter < 12:` - This block of code is executed if the line is not empty and the counter is less than 12. It appends the line to the `header` list and increments the counter.

   - `elif line.strip() != "" and counter > 11:` - This block of code is executed if the line is not empty and the counter is greater than 11. It splits the line into values, creates a new `Student` object with these values, and appends the student to the `students` list.

   - `header_text = header_builder(header)` - This line calls the `header_builder` function with the `header` as an argument. The function processes the header and returns it. The returned header is then stored in the `header_text` variable.

   - `return header_text, students` - This line returns the processed header and the list of students.


4. `header_builder(header)` - This function processes the header data and returns it as a single string. It takes the `header` as an argument and returns the processed header text.

    - The for loop `for line in header:` iterates over each line in the header.

    - `if line.find("Course Information") == -1 and counter < 3:` - This block of code is executed if the line does not contain "Course Information" and the counter is less than 3. It assigns the line to the corresponding variable (`course`, `section`, or `semester`) and increments the counter.

    - `semester = semester_parser(semester)` - This line calls the `semester_parser` function with the `semester` as an argument. The function processes the semester and returns it. The returned semester is then stored in the `semester` variable.

    - `course = course_parser(course, section)` - This line calls the `course_parser` function with the `course` and `section` as arguments. The function processes the course and section and returns it. The returned course is then stored in the `course` variable.

    - The next few lines prompt the user to enter the university information (name, campus, department, professor name). If the user does not enter any information, the function uses the default values.

    - The function then converts the university information to uppercase.

    - `header_text = "," + university_name + "\n," + university_campus + "\n," + university_department + "\n\nSEMESTRE: " + semester + "\nPROF: " + professor_name + "\nCURSO: " + course + "\n\n\n" + defaults["table_header"] + "\n"` - This line builds the header text using the processed university information, semester, professor name, course, and table header.

    - `return header_text` - This line returns the processed header text.


5. `semester_parser(semester)` - This function processes the semester data and returns it. It takes the `semester` as an argument and returns the processed semester.

   - `month_status = False`, `input_dates = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]`, `output_dates = ["ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"]`, `month_one = ""`, `month_two = ""`, `year = ""` - These lines initialize the variables that will be used in the function.

   - `semester = semester.replace("\t", " ").replace(",", "")` - This line replaces the tabulation characters and commas in the semester with spaces.

   - The for loop `for line in semester.split(" ")` iterates over each word in the semester.

   - `if line in input_dates and month_status == False:` - This block of code is executed if the word is a month and the first month has not been assigned yet. It assigns the word to `month_one` and sets `month_status` to `True`.

   - `elif line in input_dates and month_status == True:` - This block of code is executed if the word is a month and the first month has been assigned. It assigns the word to `month_two` and breaks the loop.

   - `if line.isdigit() and len(line) == 4:` - This block of code is executed if the word is a year. It assigns the word to `year`.

   - `semester = month_one + "-" + month_two + " " + year` - This line builds the semester using the processed months and year.

   - `return semester` - This line returns the processed semester.


6. `course_parser(course, section)` - This function processes the course and section data and returns it. It takes the `course` and `section` as arguments and returns the processed course.

    - `course_status = False`, `course_name = ""` - These lines initialize the variables that will be used in the function.

    - The first for loop `for line in course.split(" ")` iterates over each word in the course.

    - `if line.find("-") > -1 or line.find("0") > -1:` - This block of code is executed if the word contains "-" or "0". It toggles the `course_status` variable.

    - `elif course_status == True and not line.isdigit():` - This block of code is executed if `course_status` is `True` and the word is not a number. It appends the word to `course_name`.

    - `elif course_status == True and line.isdigit():` - This block of code is executed if `course_status` is `True` and the word is a number. It appends the word to `course_name`.

    - `course_status = False` - This line resets the `course_status` variable.

    - The second for loop `for line in section.split("\t"):` iterates over each word in the section.

    - `if course_status == False:` - This block of code is executed if `course_status` is `False`. It sets `course_status` to `True`.

    - `else:` - This block of code is executed if `course_status` is `True`. It appends the section to `course_name` and breaks the loop.

    - `return course_name` - This line returns the processed course name.


7. `Student Class` - This class defines the `Student` object, which represents a student's information. It has three attributes: `num`, `name`, and `id`.

   - `def __init__(self, num, name, id):` - This is the initializer method for the `Student` class. It takes three arguments: `num`, `name`, and `id`. These arguments are used to initialize the `num`, `name`, and `id` attributes of the `Student` instance.

   - `self.num = num`, `self.name = name`, `self.id = id` - These lines assign the values of the arguments `num`, `name`, and `id` to the corresponding attributes of the `Student` instance.

   - `def __str__(self):` - This is the string representation method for the `Student` class. It returns a string that represents the `Student` instance.

   - `return f"{self.num}, {self.name}, {self.id}"` - This line returns a string that contains the `num`, `name`, and `id` attributes of the `Student` instance, separated by commas.


8. `write_file(output_path, header, students)` - This function writes the processed data to the output file. It takes the `output_path`, `header`, and `students` as arguments and does not return anything.

   - `with open(output_path, "w") as file:` - This line opens the file at the path specified by `output_path` in write mode.

   - `file.write(header)` - This line writes the processed header to the file.

   - The for loop `for student in students:` iterates over each student in the `students` list.

   - `file.write(str(student) + "\n")` - This line writes the string representation of the student to the file, followed by a newline character.

   - `print('\033[92m' + "\nEl archivo ha sido creado exitosamente.")` - This line prints a success message indicating that the file has been created successfully.

   - `return` - This line ends the function and returns control to the caller.

## 📝 Authors

This section lists the authors who contributed to the different files in the project:

- `if __name__ == '__main__'`: Eduardo A. Sosa Torres
- `path_verifier()`: Ian P. Roman
- `read_file()`: Azkaria L. Rosado Rodriguez
- `header_builder()`: Eduardo A. Sosa Torres
- `semester_parser()`: Eduardo A. Sosa Torres
- `course_parser()`: Eduardo A. Sosa Torres
- `Student Class`: Christian J. Santiago Rivera
- `write_file()`: Javier Santos Babilonia
- `README.md`: Eduardo A. Sosa Torres
- `Project Documentation.html`: Eduardo A. Sosa Torres