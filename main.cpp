
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

/* -- Empieza Declaraci�n de funciones -- */

std::string filePathVerifier(std::string filePath);

std::string outputFilePathVerifier(std::string outputFilePath);

/* -- Termina Declaraci�n de funciones -- */

/* -- Empieza Declaraci�n de clases -- */

class Student {
public:
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
    Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail);

    // Devuelve el n�mero del estudiante.
    int getNum() const;

    // Establece el n�mero del estudiante.
    void setNum(int num);

    // Devuelve el nombre del estudiante.
    const std::string &getName() const;

    // Establece el nombre del estudiante.
    void setName(const std::string &name);

    // Devuelve la identificaci�n del estudiante.
    const std::string &getId() const;

    // Establece la identificaci�n del estudiante.
    void setId(const std::string &id);

    // Devuelve el estado de registro del estudiante.
    const std::string &getRegistrationStatus() const;

    // Establece el estado de registro del estudiante.
    void setRegistrationStatus(const std::string &registrationStatus);

    // Devuelve el nivel del estudiante.
    const std::string &getLevel() const;

    // Establece el nivel del estudiante.
    void setLevel(const std::string &level);

    // Devuelve los cr�ditos del estudiante.
    const std::string &getCredits() const;

    // Establece los cr�ditos del estudiante.
    void setCredits(const std::string &credits);

    // Devuelve la calificaci�n de mitad de per�odo del estudiante.
    const std::string &getMidterm() const;

    // Establece la calificaci�n de mitad de per�odo del estudiante.
    void setMidterm(const std::string &midterm);

    // Devuelve la calificaci�n final del estudiante.
    const std::string &getFinal() const;

    // Establece la calificaci�n final del estudiante.
    void setFinal(const std::string &final);

    // Devuelve los detalles de la calificaci�n del estudiante.
    const std::string &getGradeDetail() const;

    // Establece los detalles de la calificaci�n del estudiante.
    void setGradeDetail(const std::string &gradeDetail);

private:
    // N�mero del estudiante.
    int num;
    // Nombre del estudiante.
    std::string name;
    // Identificaci�n del estudiante.
    std::string studentId;
    // Estado de registro del estudiante.
    std::string registrationStatus;
    // Nivel del estudiante.
    std::string level;
    // Cr�ditos del estudiante.
    std::string credits;
    // Calificaci�n de mitad de per�odo del estudiante.
    std::string midterm;
    // Calificaci�n final del estudiante.
    std::string final;
    // Detalles de la calificaci�n del estudiante.
    std::string gradeDetail;
};

class FileReader {
public:
    std::vector<Student> readFile(const std::string& filePath);
};

class FileParser {
public:
    // Estructura para almacenar la informaci�n del curso
    struct CourseInfo {
        std::string courseName; // Nombre del curso
        std::string crn; // N�mero de registro del curso (CRN)
        std::string duration; // Duraci�n del curso
    };

    // Funci�n para analizar el archivo y obtener la informaci�n del curso
    CourseInfo parseFile(const std::string& filePath);

    // Funci�n para modificar la duraci�n del curso
    std::string modifyDuration(std::string duration);

    // Funci�n para traducir los meses al espa�ol
    std::string monthTranslator(std::string month);
};

class HeaderMaker {
public:
    // Funci�n para crear el encabezado con los datos proporcionados
    std::string makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseName, const std::string& crn);
};

class FileWriter {
public:
    // Funci�n para escribir en el archivo los datos de los estudiantes, la ruta del archivo y el encabezado
    void writeToFile(const std::vector<Student>& students, const std::string& filePath, const std::string& header);
};

/* -- Termina Declaraci�n de clases -- */

/* -- Empieza main -- */

/**
 * Objetivo: El c�digo de main() solicita al usuario la ruta de un archivo de entrada, lee y procesa los datos del archivo, solicita informaci�n adicional al usuario, y finalmente escribe los datos procesados y la informaci�n adicional en un archivo de salida.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de entrada cuando se le solicite. Esta cadena puede estar vac�a, contener solo el nombre del archivo o la ruta completa del archivo.
 *                 El archivo de entrada debe existir en la ruta proporcionada y debe ser legible.
 *                 El usuario debe proporcionar informaci�n v�lida cuando se le solicite.
 *
 * Postcondiciones: Se crea un archivo de salida en la ruta especificada con los datos procesados y la informaci�n adicional.
 *                  Si el archivo de entrada no se puede abrir, el programa termina con un mensaje de error.
 *
 * Descripci�n de argumentos:
 *                 `filePath`: Una cadena que representa la ruta del archivo de entrada. Se solicita al usuario que introduzca esta ruta.
 *                 `nombreInstitucion`: Una cadena que representa el nombre de la instituci�n. Se solicita al usuario que introduzca esta informaci�n.
 *                 `recinto`: Una cadena que representa el campus. Se solicita al usuario que introduzca esta informaci�n.
 *                 `departamento`: Una cadena que representa el departamento. Se solicita al usuario que introduzca esta informaci�n.
 *                 `profesor`: Una cadena que representa el nombre del profesor. Se solicita al usuario que introduzca esta informaci�n.
 *                 `outputFilePath`: Una cadena que representa la ruta del archivo de salida. Se solicita al usuario que introduzca esta ruta.
 *
 * Descripci�n de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalizaci�n: 29-02-2024
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

    // Verificar si el archivo se abri� correctamente.
    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abri� correctamente.
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

    // Solicitar al usuario informaci�n adicional.
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

    // Escribir los datos procesados y la informaci�n adicional en el archivo de salida.
    FileWriter fileWriter;
    fileWriter.writeToFile(students, outputFilePath, header);

    // Informar al usuario que los datos se han exportado.
    std::cout << "Los datos se han exportado al archivo " + outputFilePath << std::endl;

    return 0;
}

/**
 * Objetivo: Esta funci�n verifica y ajusta la ruta del archivo proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensi�n .txt, se a�ade la extensi�n.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo.
 *                 Esta cadena puede estar vac�a, contener solo el nombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La funci�n devuelve una cadena de texto que representa la ruta completa del archivo con la extensi�n .txt.
 *                  Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripci�n de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalizaci�n: 29-02-2024
 **/
std::string filePathVerifier(std::string filePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (filePath.empty()) {
        filePath = "./Resources/Data/ejemploDatos.txt";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (filePath.find('/') == std::string::npos && filePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensi�n .txt, a�adirla
        if (filePath.find(".txt") == std::string::npos) {
            filePath = "./Resources/Data/" + filePath + ".txt";
        } else {
            filePath = "./Resources/Data/" + filePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensi�n .txt, a�adirla
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
 * Objetivo: Esta funci�n verifica y ajusta la ruta del archivo de salida proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensi�n .csv, se a�ade la extensi�n.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de salida.
 *                 Esta cadena puede estar vac�a, contener solo el ombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La funci�n devuelve una cadena de texto que representa la ruta completa del archivo de salida con la extensi�n .csv.
 *                  Si la ruta del archivo de salida proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripci�n de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalizaci�n: 29-02-2024
 **/
std::string outputFilePathVerifier(std::string outputFilePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (outputFilePath.empty()) {
        outputFilePath = "./Resources/Output/ejemploDatos.csv";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (outputFilePath.find('/') == std::string::npos && outputFilePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensi�n .csv, a�adirla
        if (outputFilePath.find(".csv") == std::string::npos) {
            outputFilePath = "./Resources/Output/" + outputFilePath + ".csv";
        } else {
            outputFilePath = "./Resources/Output/" + outputFilePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensi�n .csv, a�adirla
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
 * Descripci�n de argumentos:
 * Autor:
 * Fecha de finalizaci�n:
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
 * Objetivo: Esta funci�n se utiliza para analizar un archivo y extraer informaci�n relevante del curso. La informaci�n extra�da incluye el nombre del curso, el n�mero de registro del curso (CRN) y la duraci�n del curso.
 *
 * Precondiciones: La funci�n recibe como argumento una cadena de texto que representa la ruta del archivo a analizar.
 *				   El archivo debe existir en la ruta proporcionada y debe ser legible.
 *
 * Postcondiciones: La funci�n devuelve una estructura CourseInfo que contiene la informaci�n del curso extra�da del archivo.
 *					Si el archivo no se puede abrir o leer, o si la informaci�n del curso no se puede encontrar o extraer correctamente, la funci�n puede no comportarse como se espera.
 *
 * Descripci�n de argumentos:
 *					`filePath`: Una cadena que representa la ruta del archivo que se va a analizar. Esta ruta puede ser absoluta o relativa al directorio de trabajo actual.
 *
 * Autor: Ian P. Roman
 * Fecha de finalizaci�n: 02-28-2024
 **/
FileParser::CourseInfo FileParser::parseFile(const std::string& filePath) {
    // Abre el archivo en la ruta proporcionada
    std::ifstream file(filePath);
    std::string line;
    // Crea una estructura CourseInfo para almacenar la informaci�n del curso
    CourseInfo courseInfo;

    // Lee el archivo l�nea por l�nea
    while (std::getline(file, line)) {
        // Si la l�nea contiene "Course Information", procesa la informaci�n del curso
        if (line.find("Course Information") != std::string::npos) {
            // Lee la siguiente l�nea
            std::getline(file, line);
            std::istringstream iss(line);
            std::string courseName;

            // Lee el nombre del curso hasta la primera tabulaci�n
            std::getline(iss, courseName, '\t');

            // Elimina la parte inicial y el �ltimo car�cter del nombre del curso
            courseName.erase(0, courseName.find(" - ") + 3);
            courseName.erase(courseName.end() - 1, courseName.end());

            // Almacena el nombre del curso en la estructura CourseInfo
            courseInfo.courseName = courseName;
        }
            // Si la l�nea contiene "CRN:", procesa el CRN del curso
        else if (line.find("CRN:") != std::string::npos) {
            std::istringstream iss(line);
            std::string crn;

            // Lee el CRN del curso hasta la primera tabulaci�n y luego el resto de la l�nea
            std::getline(iss, crn, '\t'); // lee hasta el colon
            std::getline(iss, crn); // lee el resto de la l�nea

            // Almacena el CRN en la estructura CourseInfo
            courseInfo.crn = crn;
        }
            // Si la l�nea contiene "Duration:", procesa la duraci�n del curso
        else if (line.find("Duration:") != std::string::npos) {
            std::istringstream iss(line);
            std::string duration;

            // Lee la duraci�n del curso hasta la primera tabulaci�n y luego el resto de la l�nea
            std::getline(iss, duration, '\t'); // lee hasta el colon
            std::getline(iss, duration); // lee el resto de la l�nea

            // Modifica y almacena la duraci�n en la estructura CourseInfo
            courseInfo.duration = modifyDuration(duration);
        }
    }

    // Devuelve la estructura CourseInfo con la informaci�n del curso
    return courseInfo;
}

/**
 * Objetivo: Esta funci�n se utiliza para modificar la duraci�n de un curso. La duraci�n se proporciona en el formato "Fecha de inicio - Fecha de finalizaci�n", y la funci�n la modifica para que est� en el formato "MES_INICIO-MES_FINAL A�O". Adem�s, traduce los nombres de los meses al espa�ol.
 *
 * Precondiciones: La funci�n recibe como argumento una cadena de texto que representa la duraci�n del curso en el formato "Fecha de inicio - Fecha de finalizaci�n".
 *                 Las fechas de inicio y finalizaci�n deben estar en el formato "D�a Mes, A�o".
 *
 * Postcondiciones: La funci�n devuelve una cadena de texto que representa la duraci�n del curso en el formato "MES_INICIO-MES_FINAL A�O".
 *                  Los nombres de los meses est�n en espa�ol y en may�sculas.
 *
 * Descripci�n de argumentos:
 *                  `duration`: Una cadena que representa la duraci�n del curso en el formato "Fecha de inicio - Fecha de finalizaci�n". Esta cadena se modifica para que est� en el formato "MES_INICIO-MES_FINAL A�O" y los nombres de los meses se traducen al espa�ol.
 * Autor: Ian P. Roman
 * Fecha de finalizaci�n: 02-28-2024
 **/
std::string FileParser::modifyDuration(std::string duration) {
    // Crea un flujo de entrada a partir de la duraci�n
    std::istringstream iss(duration);
    std::string startDate, endDate;

    // Lee la fecha de inicio y la fecha de finalizaci�n de la duraci�n
    std::getline(iss, startDate, '-');
    std::getline(iss, endDate);

    // Elimina las comas de las fechas
    startDate.erase(startDate.find(','), 1);
    endDate.erase(endDate.find(','), 1);

    // Crea flujos de entrada para las fechas de inicio y finalizaci�n
    std::istringstream startIss(startDate);
    std::istringstream endIss(endDate);

    std::string startDay, startMonth, startYear;
    std::string endDay, endMonth, endYear;

    // Lee el d�a, el mes y el a�o de las fechas de inicio y finalizaci�n
    startIss >> startDay >> startMonth >> startYear;
    endIss >> endDay >> endMonth >> endYear;

    // Convierte los meses a may�sculas
    for (auto & c: startMonth) c = toupper(c);
    for (auto & c: endMonth) c = toupper(c);

    // Traduce los meses al espa�ol
    startMonth = monthTranslator(startMonth);
    endMonth = monthTranslator(endMonth);

    // Devuelve la duraci�n modificada en el formato "MES_INICIO-MES_FINAL A�O"
    return startMonth + "-" + endMonth + " " + startYear;
}

/**
 * Objetivo: Esta funci�n se utiliza para traducir los nombres de los meses al espa�ol. La funci�n recibe un nombre de mes en ingl�s y devuelve el nombre correspondiente en espa�ol.
 *
 * Precondiciones: La funci�n recibe como argumento una cadena de texto que representa el nombre de un mes en ingl�s.
 *
 * Postcondiciones: La funci�n devuelve una cadena de texto que representa el nombre del mes en espa�ol.
 *                  Si el nombre del mes no coincide con ninguno de los nombres de los meses en ingl�s, la funci�n devuelve una cadena vac�a.
 *
 * Descripci�n de argumentos:
 *                  `month`: Una cadena que representa el nombre del mes en ingl�s y en may�sculas. Esta cadena se traduce al espa�ol.
 *
 * Autor: Ian P. Roman
 * Fecha de finalizaci�n: 02-28-2024
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
    // Si el mes no coincide con ninguno de los anteriores, devuelve una cadena vac�a
    return {};
}

/* -- Termina FileParser Class -- */

/* -- Empieza HeaderMaker Class -- */

/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripci�n de argumentos:
 * Autor:
 * Fecha de finalizaci�n:
 **/
std::string HeaderMaker::makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseName, const std::string& crn) {
    // Si el semestre, el nombre del curso o el CRN est�n vac�os, muestra un error
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

    // Si el nombre de la universidad, la ubicaci�n del campus, el nombre del departamento o el nombre del profesor est�n vac�os, usa valores predeterminados
    if (universityName.empty() || campusLocation.empty() || departmentName.empty() || professorName.empty()) {
        std::cout << "! -- ADVERTENCIA: No se han proporcionado todos los datos necesarios para crear el encabezado. -- !" << std::endl;
        std::cout << "! -- Se usaran valores predeterminados para los datos faltantes. -- !\n" << std::endl;
        std::string defaultUniversityName = "Universidad ABC123";
        std::string defaultCampusLocation = "Recinto de Isla Mona";
        std::string defaultDepartmentName = "Departamento De Ciencias En Computadoras";
        std::string defaultProfessorName = "Pepito Perez";

        // Si el nombre de la universidad est� vac�o, usa el valor predeterminado
        if (universityName.empty()) {
            universityNameUpper = defaultUniversityName;
        }

        // Si la ubicaci�n del campus est� vac�a, usa el valor predeterminado
        if (campusLocation.empty()) {
            campusLocationUpper = defaultCampusLocation;
        }

        // Si el nombre del departamento est� vac�o, usa el valor predeterminado
        if (departmentName.empty()) {
            departmentNameUpper = defaultDepartmentName;
        }

        // Si el nombre del profesor est� vac�o, usa el valor predeterminado
        if (professorName.empty()) {
            professorNameUpper = defaultProfessorName;
        }
    }

    // Convierte todos los datos a may�sculas
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
 * Objetivo: La clase FileWriter se utiliza para crear un archivo de texto en formato CSV (valores separados por comas), en el cual se escriben datos de estudiantes. Estos datos incluyen sus nombres, el n�mero que se les asigna y su identificaci�n. Esto simplifica el proceso de escribir datos en los archivos.
 *
 * Precondiciones: El vector 'students' debe estar compuesto de datos v�lidos relacionados a la clase Student.
 *                 La funci�n de 'filePath' debe representar la ruta del archivo donde los datos ser�n escritos.
 *                 El 'header' debe representar el encabezado que tendr� el archivo al inicio.
 *
 * Postcondiciones: Cuando se crea un archivo, este tiene que estar contenido en la ruta que se especific� en el 'filePath'.
 *                  Los datos en el archivo deben estar escritos en el formato CSV.
 *                  El encabezado debe estar colocado al inicio del archivo.
 *                  El archivo debe cerrarse despu�s de ingresar todos los datos.
 *
 * Descripci�n de argumentos:
 *                  'students': Un vector de objetos relacionados a los objetos de la clase Student que contiene los datos de los estudiantes que se escribir�n en el archivo.
 *                  'filePath': Una cadena que representa la ruta del archivo donde los datos ser�n escritos.
 *                  'header': Una cadena que representa el encabezado que se escribir� al inicio del archivo. Este encabezado puede contener informaci�n como nombres de columnas para los diferentes tipos de informaci�n que tendr� el archivo sobre los estudiantes.
 * Autor: Javier Santos Babilonia
 * Fecha de finalizaci�n: 01-03-2024
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
 * Objetivo: Esta clase Student se utiliza para representar a un estudiante con varios atributos como n�mero, nombre, identificaci�n del
 *           estudiante, estado de registro, nivel, cr�ditos, calificaci�n de mitad de per�odo, calificaci�n final y detalles de la calificaci�n.
 *           Proporciona m�todos para obtener y establecer estos atributos.
 *
 * Precondiciones: Para el constructor de `Student`, todos los par�metros proporcionados deben ser v�lidos y no nulos.
 *                 Para los m�todos `set`, los valores proporcionados deben ser v�lidos y no nulos.
 *
 * Postcondiciones: Despu�s de la construcci�n, se crea un objeto `Student` con los atributos proporcionados.
 *                  Los m�todos `get` devuelven el valor actual del atributo correspondiente.
 *                  Los m�todos `set` actualizan el valor del atributo correspondiente.
 *
 * Descripci�n de argumentos:
 *                 num: Un entero que representa el n�mero del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getNum y setNum.
 *                 name: Una cadena que representa el nombre del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getName y setName.
 *                 studentId: Una cadena que representa la ID del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getId y setId.
 *                 registrationStatus: Una cadena que representa el estado de registro del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getRegistrationStatus y setRegistrationStatus.
 *                 level: Una cadena que representa el nivel del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getLevel y setLevel.
 *                 credits: Una cadena que representa los cr�ditos del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getCredits y setCredits.
 *                 midterm: Una cadena que representa la calificaci�n de mitad de per�odo del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getMidterm y setMidterm.
 *                 final: Una cadena que representa la calificaci�n final del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getFinal y setFinal.
 *                 gradeDetail: Una cadena que representa los detalles de la calificaci�n del estudiante. Este es tanto un par�metro para el constructor como el sujeto de los m�todos getGradeDetail y setGradeDetail.
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalizaci�n: 28-02-2024
 **/
Student::Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail)
        : num(num), name(name), studentId(studentId), registrationStatus(registrationStatus), level(level), credits(credits), midterm(midterm), final(final), gradeDetail(gradeDetail) {
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
}

int Student::getNum() const {
    // Devuelve el n�mero del estudiante.
    return num;
}

void Student::setNum(int num) {
    // Establece el n�mero del estudiante.
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
    // Devuelve la identificaci�n del estudiante.
    return studentId;
}

void Student::setId(const std::string &id) {
    // Establece la identificaci�n del estudiante.
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
    // Devuelve los cr�ditos del estudiante.
    return credits;
}

void Student::setCredits(const std::string &credits) {
    // Establece los cr�ditos del estudiante.
    Student::credits = credits;
}

const std::string &Student::getMidterm() const {
    // Devuelve la calificaci�n de mitad de per�odo del estudiante.
    return midterm;
}

void Student::setMidterm(const std::string &midterm) {
    // Establece la calificaci�n de mitad de per�odo del estudiante.
    Student::midterm = midterm;
}

const std::string &Student::getFinal() const {
    // Devuelve la calificaci�n final del estudiante.
    return final;
}

void Student::setFinal(const std::string &final) {
    // Establece la calificaci�n final del estudiante.
    Student::final = final;
}

const std::string &Student::getGradeDetail() const {
    // Devuelve los detalles de la calificaci�n del estudiante.
    return gradeDetail;
}

void Student::setGradeDetail(const std::string &gradeDetail) {
    // Establece los detalles de la calificaci�n del estudiante.
    Student::gradeDetail = gradeDetail;
}

/* -- Termina Student Class -- */
