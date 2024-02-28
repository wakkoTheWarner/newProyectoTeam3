//
// Created by eduar on 2/27/2024.
//

#ifndef NEWPROYECTOTEAM3_FILEPARSER_H
#define NEWPROYECTOTEAM3_FILEPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <string>
#include <codecvt>
#include <clocale>
#include <regex>
#include <iomanip>

class FileParser {
private:
    std::wstring course, crn, date;

public:
    void parseFile(const std::string& filePath);
    std::wstring getCourse() const;
    std::wstring getCRN() const;
    std::wstring getDate() const;
};

#endif //NEWPROYECTOTEAM3_FILEPARSER_H
