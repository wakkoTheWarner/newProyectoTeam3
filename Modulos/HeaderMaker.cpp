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
#include <iostream>

std::string HeaderMaker::makeHeader(const std::string& universityName, const std::string& campusLocation, const std::string& departmentName, const std::string& semester, const std::string& professorName, const std::string& courseNumber) {
    if (departmentName.empty() || semester.empty() || courseNumber.empty()) {
        std::cerr << "Error: No se han proporcionado todos los datos necesarios para crear el encabezado. Faltan los datos del departamento, el semestre o el numero del curso." << std::endl;
    }

    std::string universityNameUpper = universityName;
    std::string campusLocationUpper = campusLocation;
    std::string departmentNameUpper = departmentName;
    std::string semesterUpper = semester;
    std::string professorNameUpper = professorName;
    std::string courseNumberUpper = courseNumber;

    if (universityName.empty() || campusLocation.empty() || professorName.empty()) {
        std::cout << " ! -- ADVERTENCIA: No se han proporcionado todos los datos necesarios para crear el encabezado. -- !" << std::endl;
        std::cout << "! -- Se usaran valores predeterminados para los datos faltantes. -- !\n" << std::endl;
        std::string defaultUniversityName = "Universidad ABC123";
        std::string defaultCampusLocation = "Recinto de Isla Mona";
        std::string defaultProfessorName = "Pepito Perez";

        if (universityName.empty()) {
            universityNameUpper = defaultUniversityName;
        }

        if (campusLocation.empty()) {
            campusLocationUpper = defaultCampusLocation;
        }

        if (professorName.empty()) {
            professorNameUpper = defaultProfessorName;
        }
    }

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
