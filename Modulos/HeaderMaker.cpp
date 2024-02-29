/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "HeaderMaker.h"
#include <algorithm>
#include <cctype>

std::string HeaderMaker::makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseNumber) {
    std::string universityNameUpper = universityName;
    std::string campusLocationUpper = campusLocation;
    std::string departmentNameUpper = departmentName;
    std::string semesterUpper = semester;
    std::string professorNameUpper = professorName;
    std::string courseNumberUpper = courseNumber;

    std::transform(universityNameUpper.begin(), universityNameUpper.end(), universityNameUpper.begin(), ::toupper);
    std::transform(campusLocationUpper.begin(), campusLocationUpper.end(), campusLocationUpper.begin(), ::toupper);
    std::transform(departmentNameUpper.begin(), departmentNameUpper.end(), departmentNameUpper.begin(), ::toupper);
    std::transform(semesterUpper.begin(), semesterUpper.end(), semesterUpper.begin(), ::toupper);
    std::transform(professorNameUpper.begin(), professorNameUpper.end(), professorNameUpper.begin(), ::toupper);
    std::transform(courseNumberUpper.begin(), courseNumberUpper.end(), courseNumberUpper.begin(), ::toupper);

    std::string header = ", " + universityNameUpper + "\n"
                         + ", " + campusLocationUpper + "\n"
                         + ", " + departmentNameUpper + "\n\n"
                         + "SEMESTRE: " + semesterUpper + "\n"
                         + "PROF: " + professorNameUpper + "\n"
                         + "CURSO: " + courseNumberUpper + "\n\n"
                         + "NUM, NOMBRE, ID, Email, Telefono\n";
    return header;
}
