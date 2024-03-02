
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

/* -- Empieza Declaración de funciones -- */

std::string filePathVerifier(std::string filePath);

std::string outputFilePathVerifier(std::string outputFilePath);

/* -- Termina Declaración de funciones -- */

/* -- Empieza Declaración de clases -- */

class Student {
public:
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
    Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail);

    // Devuelve el número del estudiante.
    int getNum() const;

    // Establece el número del estudiante.
    void setNum(int num);

    // Devuelve el nombre del estudiante.
    const std::string &getName() const;

    // Establece el nombre del estudiante.
    void setName(const std::string &name);

    // Devuelve la identificación del estudiante.
    const std::string &getId() const;

    // Establece la identificación del estudiante.
    void setId(const std::string &id);

    // Devuelve el estado de registro del estudiante.
    const std::string &getRegistrationStatus() const;

    // Establece el estado de registro del estudiante.
    void setRegistrationStatus(const std::string &registrationStatus);

    // Devuelve el nivel del estudiante.
    const std::string &getLevel() const;

    // Establece el nivel del estudiante.
    void setLevel(const std::string &level);

    // Devuelve los créditos del estudiante.
    const std::string &getCredits() const;

    // Establece los créditos del estudiante.
    void setCredits(const std::string &credits);

    // Devuelve la calificación de mitad de período del estudiante.
    const std::string &getMidterm() const;

    // Establece la calificación de mitad de período del estudiante.
    void setMidterm(const std::string &midterm);

    // Devuelve la calificación final del estudiante.
    const std::string &getFinal() const;

    // Establece la calificación final del estudiante.
    void setFinal(const std::string &final);

    // Devuelve los detalles de la calificación del estudiante.
    const std::string &getGradeDetail() const;

    // Establece los detalles de la calificación del estudiante.
    void setGradeDetail(const std::string &gradeDetail);

private:
    // Número del estudiante.
    int num;
    // Nombre del estudiante.
    std::string name;
    // Identificación del estudiante.
    std::string studentId;
    // Estado de registro del estudiante.
    std::string registrationStatus;
    // Nivel del estudiante.
    std::string level;
    // Créditos del estudiante.
    std::string credits;
    // Calificación de mitad de período del estudiante.
    std::string midterm;
    // Calificación final del estudiante.
    std::string final;
    // Detalles de la calificación del estudiante.
    std::string gradeDetail;
};

class FileReader {
public:
    std::vector<Student> readFile(const std::string& filePath);
};

class FileParser {
public:
    // Estructura para almacenar la información del curso
    struct CourseInfo {
        std::string courseName; // Nombre del curso
        std::string crn; // Número de registro del curso (CRN)
        std::string duration; // Duración del curso
    };

    // Función para analizar el archivo y obtener la información del curso
    CourseInfo parseFile(const std::string& filePath);

    // Función para modificar la duración del curso
    std::string modifyDuration(std::string duration);

    // Función para traducir los meses al español
    std::string monthTranslator(std::string month);
};

class HeaderMaker {
public:
    // Función para crear el encabezado con los datos proporcionados
    std::string makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseName, const std::string& crn);
};

class FileWriter {
public:
    // Función para escribir en el archivo los datos de los estudiantes, la ruta del archivo y el encabezado
    void writeToFile(const std::vector<Student>& students, const std::string& filePath, const std::string& header);
};

/* -- Termina Declaración de clases -- */

/* -- Empieza main -- */

/**
 * Objetivo: El código de main() solicita al usuario la ruta de un archivo de entrada, lee y procesa los datos del archivo, solicita información adicional al usuario, y finalmente escribe los datos procesados y la información adicional en un archivo de salida.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de entrada cuando se le solicite. Esta cadena puede estar vacía, contener solo el nombre del archivo o la ruta completa del archivo.
 *                 El archivo de entrada debe existir en la ruta proporcionada y debe ser legible.
 *                 El usuario debe proporcionar información válida cuando se le solicite.
 *
 * Postcondiciones: Se crea un archivo de salida en la ruta especificada con los datos procesados y la información adicional.
 *                  Si el archivo de entrada no se puede abrir, el programa termina con un mensaje de error.
 *
 * Descripción de argumentos:
 *                 `filePath`: Una cadena que representa la ruta del archivo de entrada. Se solicita al usuario que introduzca esta ruta.
 *                 `nombreInstitucion`: Una cadena que representa el nombre de la institución. Se solicita al usuario que introduzca esta información.
 *                 `recinto`: Una cadena que representa el campus. Se solicita al usuario que introduzca esta información.
 *                 `departamento`: Una cadena que representa el departamento. Se solicita al usuario que introduzca esta información.
 *                 `profesor`: Una cadena que representa el nombre del profesor. Se solicita al usuario que introduzca esta información.
 *                 `outputFilePath`: Una cadena que representa la ruta del archivo de salida. Se solicita al usuario que introduzca esta ruta.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
 **/
int main() {
    // Establecer el idioma local.
    setlocale(LC_ALL, "Spanish");

    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string departamento;
    std::string profesor;
    std::string outputFilePath;

    // Solicitar al usuario la ruta del archivo de entrada.
    std::cout << "Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

    // Verificar la ruta del archivo proporcionada por el usuario.
    filePath = filePathVerifier(filePath);

    // Verificar si el archivo se abrió correctamente.
    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    // Leer los datos del archivo de entrada.
    FileReader fileReader;
    std::vector<Student> students = fileReader.readFile(filePath);

    // Procesar los datos del archivo de entrada.
    FileParser fileParser;
    FileParser::CourseInfo courseInfo = fileParser.parseFile(filePath);

    // Solicitar al usuario información adicional.
    std::cout << "Nombre de Institucion: ";
    std::getline(std::cin, nombreInstitucion);
    std::cout << "Recinto: ";
    std::getline(std::cin, recinto);
    std::cout << "Departamento: ";
    std::getline(std::cin, departamento);
    std::cout << "Profesor: ";
    std::getline(std::cin, profesor);

    // Solicitar al usuario la ruta y nombre del archivo de salida.
    std::cout << "Ingresa la ruta y nombre del archivo de salida: ";
    std::getline(std::cin, outputFilePath);

    // Verificar la ruta del archivo de salida proporcionada por el usuario.
    outputFilePath = outputFilePathVerifier(outputFilePath);

    // Crear el encabezado del archivo de salida.
    HeaderMaker headerMaker;
    std::string header = headerMaker.makeHeader(nombreInstitucion, recinto, departamento, courseInfo.duration, profesor, courseInfo.courseName, courseInfo.crn);

    // Escribir los datos procesados y la información adicional en el archivo de salida.
    FileWriter fileWriter;
    fileWriter.writeToFile(students, outputFilePath, header);

    // Informar al usuario que los datos se han exportado.
    std::cout << "Los datos se han exportado al archivo " + outputFilePath << std::endl;

    return 0;
}

/**
 * Objetivo: Esta función verifica y ajusta la ruta del archivo proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensión .txt, se añade la extensión.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo.
 *                 Esta cadena puede estar vacía, contener solo el nombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa la ruta completa del archivo con la extensión .txt.
 *                  Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
 **/
std::string filePathVerifier(std::string filePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (filePath.empty()) {
        filePath = "./Resources/Data/ejemploDatos.txt";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (filePath.find('/') == std::string::npos && filePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensión .txt, añadirla
        if (filePath.find(".txt") == std::string::npos) {
            filePath = "./Resources/Data/" + filePath + ".txt";
        } else {
            filePath = "./Resources/Data/" + filePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensión .txt, añadirla
        if (filePath.find(".txt") == std::string::npos) {
            filePath += ".txt";
        }
    }

    // Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, eliminarlas
    if (filePath.find('\"') != std::string::npos) {
        filePath.erase(std::remove(filePath.begin(), filePath.end(), '\"'), filePath.end());
    }

    return filePath;
}

/**
 * Objetivo: Esta función verifica y ajusta la ruta del archivo de salida proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensión .csv, se añade la extensión.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de salida.
 *                 Esta cadena puede estar vacía, contener solo el ombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa la ruta completa del archivo de salida con la extensión .csv.
 *                  Si la ruta del archivo de salida proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
 **/
std::string outputFilePathVerifier(std::string outputFilePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (outputFilePath.empty()) {
        outputFilePath = "./Resources/Output/ejemploDatos.csv";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (outputFilePath.find('/') == std::string::npos && outputFilePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensión .csv, añadirla
        if (outputFilePath.find(".csv") == std::string::npos) {
            outputFilePath = "./Resources/Output/" + outputFilePath + ".csv";
        } else {
            outputFilePath = "./Resources/Output/" + outputFilePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensión .csv, añadirla
        if (outputFilePath.find(".csv") == std::string::npos) {
            outputFilePath += ".csv";
        }
    }

    // Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, eliminarlas
    if (outputFilePath.find('\"') != std::string::npos) {
        outputFilePath.erase(std::remove(outputFilePath.begin(), outputFilePath.end(), '\"'), outputFilePath.end());
    }

    return outputFilePath;
}

/* -- Termina main -- */

/* -- Empieza FileReader Class -- */

/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/
std::vector<Student> FileReader::readFile(const std::string& filePath) {
    std::vector<Student> students;
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        if (!isdigit(line[0])) {
            continue;
        }

        std::istringstream iss(line);
        std::string numString, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail;
        int num;

        std::getline(iss, numString, '\t');
        std::getline(iss, name, '\t');
        std::getline(iss, studentId, '\t');
        std::getline(iss, registrationStatus, '\t');
        std::getline(iss, level, '\t');
        std::getline(iss, credits, '\t');
        std::getline(iss, midterm, '\t');
        std::getline(iss, final, '\t');
        std::getline(iss, gradeDetail, '\t');

        num = std::stoi(numString);

        students.push_back(Student(num, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail));
    }

    return students;
}

/* -- Termina FileReader Class -- */

/* -- Empieza FileParser Class -- */

/**
 * Objetivo: Esta función se utiliza para analizar un archivo y extraer información relevante del curso. La información extraída incluye el nombre del curso, el número de registro del curso (CRN) y la duración del curso.
 *
 * Precondiciones: La función recibe como argumento una cadena de texto que representa la ruta del archivo a analizar.
 *				   El archivo debe existir en la ruta proporcionada y debe ser legible.
 *
 * Postcondiciones: La función devuelve una estructura CourseInfo que contiene la información del curso extraída del archivo.
 *					Si el archivo no se puede abrir o leer, o si la información del curso no se puede encontrar o extraer correctamente, la función puede no comportarse como se espera.
 *
 * Descripción de argumentos:
 *					`filePath`: Una cadena que representa la ruta del archivo que se va a analizar. Esta ruta puede ser absoluta o relativa al directorio de trabajo actual.
 *
 * Autor: Ian P. Roman
 * Fecha de finalización: 02-28-2024
 **/
FileParser::CourseInfo FileParser::parseFile(const std::string& filePath) {
    // Abre el archivo en la ruta proporcionada
    std::ifstream file(filePath);
    std::string line;
    // Crea una estructura CourseInfo para almacenar la información del curso
    CourseInfo courseInfo;

    // Lee el archivo línea por línea
    while (std::getline(file, line)) {
        // Si la línea contiene "Course Information", procesa la información del curso
        if (line.find("Course Information") != std::string::npos) {
            // Lee la siguiente línea
            std::getline(file, line);
            std::istringstream iss(line);
            std::string courseName;

            // Lee el nombre del curso hasta la primera tabulación
            std::getline(iss, courseName, '\t');

            // Elimina la parte inicial y el último carácter del nombre del curso
            courseName.erase(0, courseName.find(" - ") + 3);
            courseName.erase(courseName.end() - 1, courseName.end());

            // Almacena el nombre del curso en la estructura CourseInfo
            courseInfo.courseName = courseName;
        }
            // Si la línea contiene "CRN:", procesa el CRN del curso
        else if (line.find("CRN:") != std::string::npos) {
            std::istringstream iss(line);
            std::string crn;

            // Lee el CRN del curso hasta la primera tabulación y luego el resto de la línea
            std::getline(iss, crn, '\t'); // lee hasta el colon
            std::getline(iss, crn); // lee el resto de la línea

            // Almacena el CRN en la estructura CourseInfo
            courseInfo.crn = crn;
        }
            // Si la línea contiene "Duration:", procesa la duración del curso
        else if (line.find("Duration:") != std::string::npos) {
            std::istringstream iss(line);
            std::string duration;

            // Lee la duración del curso hasta la primera tabulación y luego el resto de la línea
            std::getline(iss, duration, '\t'); // lee hasta el colon
            std::getline(iss, duration); // lee el resto de la línea

            // Modifica y almacena la duración en la estructura CourseInfo
            courseInfo.duration = modifyDuration(duration);
        }
    }

    // Devuelve la estructura CourseInfo con la información del curso
    return courseInfo;
}

/**
 * Objetivo: Esta función se utiliza para modificar la duración de un curso. La duración se proporciona en el formato "Fecha de inicio - Fecha de finalización", y la función la modifica para que esté en el formato "MES_INICIO-MES_FINAL AÑO". Además, traduce los nombres de los meses al español.
 *
 * Precondiciones: La función recibe como argumento una cadena de texto que representa la duración del curso en el formato "Fecha de inicio - Fecha de finalización".
 *                 Las fechas de inicio y finalización deben estar en el formato "Día Mes, Año".
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa la duración del curso en el formato "MES_INICIO-MES_FINAL AÑO".
 *                  Los nombres de los meses están en español y en mayúsculas.
 *
 * Descripción de argumentos:
 *                  `duration`: Una cadena que representa la duración del curso en el formato "Fecha de inicio - Fecha de finalización". Esta cadena se modifica para que esté en el formato "MES_INICIO-MES_FINAL AÑO" y los nombres de los meses se traducen al español.
 * Autor: Ian P. Roman
 * Fecha de finalización: 02-28-2024
 **/
std::string FileParser::modifyDuration(std::string duration) {
    // Crea un flujo de entrada a partir de la duración
    std::istringstream iss(duration);
    std::string startDate, endDate;

    // Lee la fecha de inicio y la fecha de finalización de la duración
    std::getline(iss, startDate, '-');
    std::getline(iss, endDate);

    // Elimina las comas de las fechas
    startDate.erase(startDate.find(','), 1);
    endDate.erase(endDate.find(','), 1);

    // Crea flujos de entrada para las fechas de inicio y finalización
    std::istringstream startIss(startDate);
    std::istringstream endIss(endDate);

    std::string startDay, startMonth, startYear;
    std::string endDay, endMonth, endYear;

    // Lee el día, el mes y el año de las fechas de inicio y finalización
    startIss >> startDay >> startMonth >> startYear;
    endIss >> endDay >> endMonth >> endYear;

    // Convierte los meses a mayúsculas
    for (auto & c: startMonth) c = toupper(c);
    for (auto & c: endMonth) c = toupper(c);

    // Traduce los meses al español
    startMonth = monthTranslator(startMonth);
    endMonth = monthTranslator(endMonth);

    // Devuelve la duración modificada en el formato "MES_INICIO-MES_FINAL AÑO"
    return startMonth + "-" + endMonth + " " + startYear;
}

/**
 * Objetivo: Esta función se utiliza para traducir los nombres de los meses al español. La función recibe un nombre de mes en inglés y devuelve el nombre correspondiente en español.
 *
 * Precondiciones: La función recibe como argumento una cadena de texto que representa el nombre de un mes en inglés.
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa el nombre del mes en español.
 *                  Si el nombre del mes no coincide con ninguno de los nombres de los meses en inglés, la función devuelve una cadena vacía.
 *
 * Descripción de argumentos:
 *                  `month`: Una cadena que representa el nombre del mes en inglés y en mayúsculas. Esta cadena se traduce al español.
 *
 * Autor: Ian P. Roman
 * Fecha de finalización: 02-28-2024
 **/
std::string FileParser::monthTranslator(std::string month) {
    // Si el mes es "JAN", devuelve "ENERO"
    if (month == "JAN") {
        return "ENERO";
    }
        // Si el mes es "FEB", devuelve "FEBRERO"
    else if (month == "FEB") {
        return "FEBRERO";
    }
        // Si el mes es "MAR", devuelve "MARZO"
    else if (month == "MAR") {
        return "MARZO";
    }
        // Si el mes es "APR", devuelve "ABRIL"
    else if (month == "APR") {
        return "ABRIL";
    }
        // Si el mes es "MAY", devuelve "MAYO"
    else if (month == "MAY") {
        return "MAYO";
    }
        // Si el mes es "JUN", devuelve "JUNIO"
    else if (month == "JUN") {
        return "JUNIO";
    }
        // Si el mes es "JUL", devuelve "JULIO"
    else if (month == "JUL") {
        return "JULIO";
    }
        // Si el mes es "AUG", devuelve "AGOSTO"
    else if (month == "AUG") {
        return "AGOSTO";
    }
        // Si el mes es "SEP", devuelve "SEPTIEMBRE"
    else if (month == "SEP") {
        return "SEPTIEMBRE";
    }
        // Si el mes es "OCT", devuelve "OCTUBRE"
    else if (month == "OCT") {
        return "OCTUBRE";
    }
        // Si el mes es "NOV", devuelve "NOVIEMBRE"
    else if (month == "NOV") {
        return "NOVIEMBRE";
    }
        // Si el mes es "DEC", devuelve "DICIEMBRE"
    else if (month == "DEC") {
        return "DICIEMBRE";
    }
    // Si el mes no coincide con ninguno de los anteriores, devuelve una cadena vacía
    return {};
}

/* -- Termina FileParser Class -- */

/* -- Empieza HeaderMaker Class -- */

/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/
std::string HeaderMaker::makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseName, const std::string& crn) {
    // Si el semestre, el nombre del curso o el CRN están vacíos, muestra un error
    if (semester.empty() || courseName.empty() || crn.empty()) {
        std::cerr << "Error: No se han proporcionado todos los datos necesarios para crear el encabezado. Falta el semestre, el nombre del curso o el seccion." << std::endl;
    }

    // Crea copias de los datos proporcionados
    std::string universityNameUpper = universityName;
    std::string campusLocationUpper = campusLocation;
    std::string departmentNameUpper = departmentName;
    std::string semesterUpper = semester;
    std::string professorNameUpper = professorName;
    std::string courseNameUpper = courseName;
    std::string crnUpper = crn;

    // Si el nombre de la universidad, la ubicación del campus, el nombre del departamento o el nombre del profesor están vacíos, usa valores predeterminados
    if (universityName.empty() || campusLocation.empty() || departmentName.empty() || professorName.empty()) {
        std::cout << "! -- ADVERTENCIA: No se han proporcionado todos los datos necesarios para crear el encabezado. -- !" << std::endl;
        std::cout << "! -- Se usaran valores predeterminados para los datos faltantes. -- !\n" << std::endl;
        std::string defaultUniversityName = "Universidad ABC123";
        std::string defaultCampusLocation = "Recinto de Isla Mona";
        std::string defaultDepartmentName = "Departamento De Ciencias En Computadoras";
        std::string defaultProfessorName = "Pepito Perez";

        // Si el nombre de la universidad está vacío, usa el valor predeterminado
        if (universityName.empty()) {
            universityNameUpper = defaultUniversityName;
        }

        // Si la ubicación del campus está vacía, usa el valor predeterminado
        if (campusLocation.empty()) {
            campusLocationUpper = defaultCampusLocation;
        }

        // Si el nombre del departamento está vacío, usa el valor predeterminado
        if (departmentName.empty()) {
            departmentNameUpper = defaultDepartmentName;
        }

        // Si el nombre del profesor está vacío, usa el valor predeterminado
        if (professorName.empty()) {
            professorNameUpper = defaultProfessorName;
        }
    }

    // Convierte todos los datos a mayúsculas
    std::transform(universityNameUpper.begin(), universityNameUpper.end(), universityNameUpper.begin(), ::toupper);
    std::transform(campusLocationUpper.begin(), campusLocationUpper.end(), campusLocationUpper.begin(), ::toupper);
    std::transform(departmentNameUpper.begin(), departmentNameUpper.end(), departmentNameUpper.begin(), ::toupper);
    std::transform(semesterUpper.begin(), semesterUpper.end(), semesterUpper.begin(), ::toupper);
    std::transform(professorNameUpper.begin(), professorNameUpper.end(), professorNameUpper.begin(), ::toupper);
    std::transform(courseNameUpper.begin(), courseNameUpper.end(), courseNameUpper.begin(), ::toupper);
    std::transform(crnUpper.begin(), crnUpper.end(), crnUpper.begin(), ::toupper);

    // Crea el encabezado con los datos proporcionados
    std::string header = "," + universityNameUpper + "\n"
                         + "," + campusLocationUpper + "\n"
                         + "," + departmentNameUpper + "\n\n"
                         + "SEMESTRE: " + semesterUpper + "\n"
                         + "PROF: " + professorNameUpper + "\n"
                         + "CURSO: " + courseNameUpper + " (" + crnUpper + ")\n\n"
                         + "NUM,NOMBRE,ID,Email,Telefono\n";
    // Devuelve el encabezado
    return header;
}

/* -- Termina HeaderMaker Class -- */

/* -- Empieza FileWriter Class -- */

/**
 * Objetivo: La clase FileWriter se utiliza para crear un archivo de texto en formato CSV (valores separados por comas), en el cual se escriben datos de estudiantes. Estos datos incluyen sus nombres, el número que se les asigna y su identificación. Esto simplifica el proceso de escribir datos en los archivos.
 *
 * Precondiciones: El vector 'students' debe estar compuesto de datos válidos relacionados a la clase Student.
 *                 La función de 'filePath' debe representar la ruta del archivo donde los datos serán escritos.
 *                 El 'header' debe representar el encabezado que tendrá el archivo al inicio.
 *
 * Postcondiciones: Cuando se crea un archivo, este tiene que estar contenido en la ruta que se especificó en el 'filePath'.
 *                  Los datos en el archivo deben estar escritos en el formato CSV.
 *                  El encabezado debe estar colocado al inicio del archivo.
 *                  El archivo debe cerrarse después de ingresar todos los datos.
 *
 * Descripción de argumentos:
 *                  'students': Un vector de objetos relacionados a los objetos de la clase Student que contiene los datos de los estudiantes que se escribirán en el archivo.
 *                  'filePath': Una cadena que representa la ruta del archivo donde los datos serán escritos.
 *                  'header': Una cadena que representa el encabezado que se escribirá al inicio del archivo. Este encabezado puede contener información como nombres de columnas para los diferentes tipos de información que tendrá el archivo sobre los estudiantes.
 * Autor: Javier Santos Babilonia
 * Fecha de finalización: 01-03-2024
 **/
void FileWriter::writeToFile(const std::vector<Student>& students, const std::string& filePath, const std::string& header) {
    // Crea un archivo en la ruta proporcionada
    std::ofstream file(filePath);

    // Escribe el encabezado en el archivo
    file << header;

    // Escribe los datos del estudiante en el archivo
    for (const Student& student : students) {
        file << "\"" << student.getNum() << "\","
             << "\"" << student.getName() << "\","
             << "\"" << student.getId() << "\"\n";
    }

    // Cierra el archivo
    file.close();
}

/* -- Termina FileWriter Class -- */

/* -- Empieza Student Class -- */

/**
 * Objetivo: Esta clase Student se utiliza para representar a un estudiante con varios atributos como número, nombre, identificación del
 *           estudiante, estado de registro, nivel, créditos, calificación de mitad de período, calificación final y detalles de la calificación.
 *           Proporciona métodos para obtener y establecer estos atributos.
 *
 * Precondiciones: Para el constructor de `Student`, todos los parámetros proporcionados deben ser válidos y no nulos.
 *                 Para los métodos `set`, los valores proporcionados deben ser válidos y no nulos.
 *
 * Postcondiciones: Después de la construcción, se crea un objeto `Student` con los atributos proporcionados.
 *                  Los métodos `get` devuelven el valor actual del atributo correspondiente.
 *                  Los métodos `set` actualizan el valor del atributo correspondiente.
 *
 * Descripción de argumentos:
 *                 num: Un entero que representa el número del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getNum y setNum.
 *                 name: Una cadena que representa el nombre del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getName y setName.
 *                 studentId: Una cadena que representa la ID del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getId y setId.
 *                 registrationStatus: Una cadena que representa el estado de registro del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getRegistrationStatus y setRegistrationStatus.
 *                 level: Una cadena que representa el nivel del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getLevel y setLevel.
 *                 credits: Una cadena que representa los créditos del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getCredits y setCredits.
 *                 midterm: Una cadena que representa la calificación de mitad de período del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getMidterm y setMidterm.
 *                 final: Una cadena que representa la calificación final del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getFinal y setFinal.
 *                 gradeDetail: Una cadena que representa los detalles de la calificación del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getGradeDetail y setGradeDetail.
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 28-02-2024
 **/
Student::Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail)
        : num(num), name(name), studentId(studentId), registrationStatus(registrationStatus), level(level), credits(credits), midterm(midterm), final(final), gradeDetail(gradeDetail) {
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
}

int Student::getNum() const {
    // Devuelve el número del estudiante.
    return num;
}

void Student::setNum(int num) {
    // Establece el número del estudiante.
    Student::num = num;
}

const std::string &Student::getName() const {
    // Devuelve el nombre del estudiante.
    return name;
}

void Student::setName(const std::string &name) {
    // Establece el nombre del estudiante.
    Student::name = name;
}

const std::string &Student::getId() const {
    // Devuelve la identificación del estudiante.
    return studentId;
}

void Student::setId(const std::string &id) {
    // Establece la identificación del estudiante.
    Student::studentId = id;
}

const std::string &Student::getRegistrationStatus() const {
    // Devuelve el estado de registro del estudiante.
    return registrationStatus;
}

void Student::setRegistrationStatus(const std::string &registrationStatus) {
    // Establece el estado de registro del estudiante.
    Student::registrationStatus = registrationStatus;
}

const std::string &Student::getLevel() const {
    // Devuelve el nivel del estudiante.
    return level;
}

void Student::setLevel(const std::string &level) {
    // Establece el nivel del estudiante.
    Student::level = level;
}

const std::string &Student::getCredits() const {
    // Devuelve los créditos del estudiante.
    return credits;
}

void Student::setCredits(const std::string &credits) {
    // Establece los créditos del estudiante.
    Student::credits = credits;
}

const std::string &Student::getMidterm() const {
    // Devuelve la calificación de mitad de período del estudiante.
    return midterm;
}

void Student::setMidterm(const std::string &midterm) {
    // Establece la calificación de mitad de período del estudiante.
    Student::midterm = midterm;
}

const std::string &Student::getFinal() const {
    // Devuelve la calificación final del estudiante.
    return final;
}

void Student::setFinal(const std::string &final) {
    // Establece la calificación final del estudiante.
    Student::final = final;
}

const std::string &Student::getGradeDetail() const {
    // Devuelve los detalles de la calificación del estudiante.
    return gradeDetail;
}

void Student::setGradeDetail(const std::string &gradeDetail) {
    // Establece los detalles de la calificación del estudiante.
    Student::gradeDetail = gradeDetail;
}

/* -- Termina Student Class -- */
