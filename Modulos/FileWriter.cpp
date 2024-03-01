/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <fstream>
#include "FileWriter.h"
#include "Students.h"

void FileWriter::writeToFile(const std::vector<Student>& students, const std::string& filePath, const std::string& header) {
    std::ofstream file(filePath);

    // Write the header to the file
    file << header;

    // Write the student data to the file
    for (const Student& student : students) {
        file << "\"" << student.getNum() << "\","
             << "\"" << student.getName() << "\","
             << "\"" << student.getId() << "\"\n";
    }

    file.close();
}
