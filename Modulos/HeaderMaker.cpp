/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/

#include "HeaderMaker.h"
#include <algorithm>
#include <cctype>
#include <iostream>

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
