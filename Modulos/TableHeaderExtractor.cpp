//
// Created by eduar on 2/27/2024.
//

#include "TableHeaderExtractor.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <string>
#include <codecvt>
#include <clocale>
#include <iostream>

std::vector<std::wstring> TableHeaderExtractor::extractHeader(const std::string& filePath) {
    std::setlocale(LC_ALL, "");
    std::wifstream file(filePath);
    if (!file.is_open()) {
        std::wcout << L"Unable to open file" << std::endl;
        return std::vector<std::wstring>();
    }

    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    file.imbue(utf8_locale);

    std::wstring line;
    std::vector<std::wstring> header;

    while (std::getline(file, line)) {
        if (line.substr(0, 6) == L"Number") {
            std::wistringstream iss(line);
            std::wstring word;
            while (std::getline(iss, word, L'\t')) {
                header.push_back(word);
            }
            break;
        }
    }

    file.close();

    return header;
}