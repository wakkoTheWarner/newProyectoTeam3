/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_FILEWRITER_H
#define NEWPROYECTOTEAM3_FILEWRITER_H


#include <vector>
#include <string>
#include "Students.h"

class FileWriter {
public:
    void writeToFile(const std::vector<Student>& students, const std::string& filePath, const std::string& header);
};


#endif //NEWPROYECTOTEAM3_FILEWRITER_H
