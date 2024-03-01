/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Descripción de argumentos:
 * Autor:
 * Fecha de finalización:
 **/

#include <fstream>
#include "FileWriter.h"
#include "Students.h"

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
