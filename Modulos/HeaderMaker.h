/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_HEADERMAKER_H
#define NEWPROYECTOTEAM3_HEADERMAKER_H


#include <string>

class HeaderMaker {
public:
    std::string makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseNumber);
    std::string centerText(const std::string& text, int width);
};


#endif //NEWPROYECTOTEAM3_HEADERMAKER_H