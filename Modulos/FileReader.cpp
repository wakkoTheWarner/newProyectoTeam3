/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/

#include <fstream>
#include <sstream>
#include "FileReader.h"
#include "Students.h"

std::vector<Student> FileReader::readFile(const std::string& filePath) {
    // Crea un vector para almacenar los estudiantes
    std::vector<Student> students;
    // Abre el archivo en la ruta proporcionada
    std::ifstream file(filePath);
    std::string line;

    // Lee el archivo línea por línea
    while (std::getline(file, line)) {
        // Si la primera caracter de la línea no es un dígito, continúa con la siguiente línea
        if (!isdigit(line[0])) {
            continue;
        }

        // Crea un flujo de entrada a partir de la línea
        std::istringstream iss(line);
        std::string numString, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail;
        int num;

        // Lee el número, el nombre, la identificación del estudiante, el estado de registro, el nivel, los créditos, la calificación de mitad de período, la calificación final y los detalles de la calificación de la línea
        std::getline(iss, numString, '\t');
        std::getline(iss, name, '\t');
        std::getline(iss, studentId, '\t');
        std::getline(iss, registrationStatus, '\t');
        std::getline(iss, level, '\t');
        std::getline(iss, credits, '\t'); // lee los créditos como cadena
        std::getline(iss, midterm, '\t');
        std::getline(iss, final, '\t');
        std::getline(iss, gradeDetail, '\t');

        // Convierte el número a entero
        num = std::stoi(numString);

        // Añade el estudiante al vector de estudiantes
        students.push_back(Student(num, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail));
    }

    // Devuelve el vector de estudiantes
    return students;
}
