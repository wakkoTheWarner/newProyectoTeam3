/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "FileParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

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
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
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
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
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
