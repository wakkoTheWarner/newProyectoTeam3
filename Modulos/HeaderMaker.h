/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_HEADERMAKER_H
#define NEWPROYECTOTEAM3_HEADERMAKER_H


#include <string>

class HeaderMaker {
public:
    // Función para crear el encabezado con los datos proporcionados
    std::string makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseName, const std::string& crn);
};


#endif //NEWPROYECTOTEAM3_HEADERMAKER_H
