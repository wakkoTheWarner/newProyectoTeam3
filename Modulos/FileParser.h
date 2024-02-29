/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_FILEPARSER_H
#define NEWPROYECTOTEAM3_FILEPARSER_H


#include <string>

class FileParser {
public:
    struct CourseInfo {
        std::string courseName;
        std::string crn;
        std::string duration;
    };

    CourseInfo parseFile(const std::string& filePath);
    std::string modifyDuration(std::string duration);
    std::string monthTranslator(std::string month);
};

#endif //NEWPROYECTOTEAM3_FILEPARSER_H
