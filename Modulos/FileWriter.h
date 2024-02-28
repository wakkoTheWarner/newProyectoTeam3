//
// Created by eduar on 2/27/2024.
//

#ifndef NEWPROYECTOTEAM3_FILEWRITER_H
#define NEWPROYECTOTEAM3_FILEWRITER_H

#include <fstream>
#include <vector>
#include <locale>
#include <regex>
#include "FileParser.h"

class FileWriter {
public:
    void writeToFile(const std::string& filename, const std::string& filePath, const std::locale utf8_locale, const FileParser& parser, const std::vector<std::wstring>& header, const std::vector<std::vector<std::wstring>>& content);
};

#endif //NEWPROYECTOTEAM3_FILEWRITER_H
