/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <string>
#include <fstream>
#include <iostream>
#include <codecvt>
#include <vector>
#include <regex>
#include "FileReader.h"

std::vector<std::vector<std::wstring>> FileReader::readFile(const std::string& filePath) {
    std::setlocale(LC_ALL, "");
    std::wifstream file(filePath);
    if (!file.is_open()) {
        std::wcout << L"Unable to open file" << std::endl;
        return std::vector<std::vector<std::wstring>>();
    }

    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    file.imbue(utf8_locale);

    std::wstring line;
    std::vector<std::vector<std::wstring>> content;
    while (std::getline(file, line)) {

        // If the line does not start with a digit, skip the line
        if (!line.empty() && !iswdigit(line[0])) {
            continue;
        }

        if (!line.empty() && (iswdigit(line[0]) || iswalpha(line[0]))) {

            // Split the line using tabs and store the values in a vector
            std::vector<std::wstring> row;
            std::wregex ws_re(L"\\t(?!$)"); // Regular expression to match tabs not at the end of the line
            std::copy(std::wsregex_token_iterator(line.begin(), line.end(), ws_re, -1),
                      std::wsregex_token_iterator(),
                      std::back_inserter(row));

            // Add the row to the content
            content.push_back(row);
        }
    }

    file.close();

    return content;
}