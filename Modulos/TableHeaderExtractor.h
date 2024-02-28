//
// Created by eduar on 2/27/2024.
//

#ifndef NEWPROYECTOTEAM3_TABLEHEADEREXTRACTOR_H
#define NEWPROYECTOTEAM3_TABLEHEADEREXTRACTOR_H

#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <string>
#include <codecvt>
#include <clocale>
#include <iostream>

class TableHeaderExtractor {
public:
    std::vector<std::wstring> extractHeader(const std::string& filePath);
    std::wstring trimTrailingSpaces(const std::wstring& str);
};

#endif //NEWPROYECTOTEAM3_TABLEHEADEREXTRACTOR_H
