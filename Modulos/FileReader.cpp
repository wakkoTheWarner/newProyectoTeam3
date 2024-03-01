/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <fstream>
#include <sstream>
#include "FileReader.h"
#include "Students.h"

std::vector<Student> FileReader::readFile(const std::string& filePath) {
    std::vector<Student> students;
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        if (!isdigit(line[0])) {
            continue;
        }

        std::istringstream iss(line);
        std::string numString, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail;
        int num;

        std::getline(iss, numString, '\t');
        std::getline(iss, name, '\t');
        std::getline(iss, studentId, '\t');
        std::getline(iss, registrationStatus, '\t');
        std::getline(iss, level, '\t');
        std::getline(iss, credits, '\t'); // read credits as string
        std::getline(iss, midterm, '\t');
        std::getline(iss, final, '\t');
        std::getline(iss, gradeDetail, '\t');

        num = std::stoi(numString);

        students.push_back(Student(num, name, studentId, registrationStatus, level, credits, midterm, final, gradeDetail));
    }

    return students;
}
