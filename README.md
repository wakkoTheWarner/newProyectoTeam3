
# C++ Investigation Project

This C++ project is a university student registration system. It reads student data from a file, processes it, and writes the processed data to another file. The data includes student names, IDs, registration status, level, and credits. The user is prompted to input the institution's name, campus, and professor's name. The processed data, including the institution's name, campus, department, semester, professor's name, course, and the table of students' information, is then written to a new file named "output.csv".


## 📕main.cpp

The `main.cpp` file is the entry point of the application. It is responsible for orchestrating the process of reading, parsing, and writing data from a file. The application is designed to read data from a file, parse the data, extract the header, and write the processed data to a new file.

### 🔖Detailed Description

The `main` function begins by setting the locale to the user's local setting. This is important for handling special characters in different languages correctly.

The function then declares several string variables to hold the file path and other information that will be used later.

The user is prompted to enter the file path of the file to be processed. This file path is used to create a `FileReader` object, which reads the file and stores its content in a 2D vector of wide strings.

Next, a `FileParser` object is created and used to parse the file. The parsing process involves extracting specific information from the file, such as the course, CRN, and date.

A `TableHeaderExtractor` object is then created and used to extract the header from the file. The header is stored in a vector of wide strings.

The user is then prompted to enter the name of the institution, the campus, and the professor. These details are used later when writing the processed data to a new file.

A `FileWriter` object is created to handle the writing of the processed data to a new file. The `writeToFile` method of the `FileWriter` object is called with the necessary parameters, including the name of the output file, the file path, the locale, the `FileParser` object, the header, the content, and the details entered by the user.

Finally, a message is displayed to the user indicating that the data has been exported to the output file.

### 🔖Classes Used

`FileReader`: This class is responsible for reading the content of a file and storing it in a 2D vector of wide strings.

`FileParser`: This class is responsible for parsing the file and extracting specific information such as the course, CRN, and date.

`TableHeaderExtractor`: This class is responsible for extracting the header from the file.

`FileWriter`: This class is responsible for writing the processed data to a new file.

### 🔖Functions Used

`std::setlocale`: This function is used to set the locale to the user's local setting.

`std::getline`: This function is used to get input from the user.

`FileReader::readFile`: This method is used to read the content of a file.

`FileParser::parseFile`: This method is used to parse a file and extract specific information.

`TableHeaderExtractor::extractHeader`: This method is used to extract the header from a file.

`FileWriter::writeToFile`: This method is used to write the processed data to a new file.
