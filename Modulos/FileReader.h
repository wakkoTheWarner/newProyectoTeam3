/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_FILEREADER_H
#define NEWPROYECTOTEAM3_FILEREADER_H


#include <vector>
#include <string>
#include "Students.h"
#include "Students.cpp"

class FileReader {
public:
    std::vector<Student> readFile(const std::string& filePath);
};


#endif //NEWPROYECTOTEAM3_FILEREADER_H
