/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <fstream>
#include <vector>
#include <locale>
#include <regex>
#include "FileWriter.h"
#include "TableHeaderExtractor.h"
#include "FileParser.h"

void FileWriter::writeToFile(const std::string& filename, const std::string& filePath, const std::locale utf8_locale, const FileParser& parser, const std::vector<std::wstring>& header, const std::vector<std::vector<std::wstring>>& content) {
    // Open a new CSV file for writing
    std::wofstream out(filename);
    // Set the locale of the output file to UTF-8
    // to ensure that special characters are written correctly
    out.imbue(utf8_locale);
    // Add the title and subtitles to the file
    out << L",UNIVERSIDAD ABC123\n";
    out << L",RECINTO DE ISLA MONA\n";
    out << L",DEPARTAMENTO DE CIENCIAS EN COMPUTADORAS\n";
    out << L"\n";
    out << L"SEMESTRE: " + parser.getDate() + L"\n";
    out << L"PROF: PEPITO PEREZ\n";
    out << L"CURSO: " + parser.getCourse() + L" (" + parser.getCRN() + L")\n";
    out << L"\n";
    out << L"\n";
    // Write the headers to the file
    for (size_t i = 0; i < header.size(); ++i) {
        out << header[i];
        if (i < header.size() - 1) {
            out << L',';
        }
    }
    out << '\n';
    // Regular expression to match one or more spaces at the end of a string
    std::wregex trailing_spaces(L"\\s+$");
    // Loop through the content and write each row to the file
    for (const auto &row : content) {
        size_t cell_count = 0;
        for (const auto &cell : row) {
            // If the cell contains a space, it's a name. Remove trailing spaces and add quotes around it.
            if (cell.find(L' ') != std::wstring::npos) {
                std::wstring trimmed_cell = std::regex_replace(cell, trailing_spaces, L"");
                out << L'"' << trimmed_cell << L'"';
            } else {
                out << cell;
            }
            if (++cell_count < row.size()) {
                out << L',';
            }
        }
        out << '\n';
    }
    // Close the output file after writing
    out.close();
}