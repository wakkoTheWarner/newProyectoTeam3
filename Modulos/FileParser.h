/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_FILEPARSER_H
#define NEWPROYECTOTEAM3_FILEPARSER_H


#include <string>

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

#endif //NEWPROYECTOTEAM3_FILEPARSER_H
