/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <iostream>
#include "Modulos/FileParser.h"
#include "Modulos/TableHeaderExtractor.h"
#include "Modulos/FileReader.h"
#include "Modulos/FileWriter.h"

int main() {
    std::setlocale(LC_ALL, "");
    std::string filePath;
    std::cout << "Enter the file path: ";
    std::getline(std::cin, filePath);

    FileReader reader;
    std::vector<std::vector<std::wstring>> content = reader.readFile(filePath);

    FileParser parser;
    parser.parseFile(filePath);

    TableHeaderExtractor extractor;
    std::vector<std::wstring> header = extractor.extractHeader(filePath);

    FileWriter writer;
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    writer.writeToFile("output.csv", filePath, utf8_locale, parser, header, content);

    // Inform user of successful data export
    std::wcout << L"Data exported to ejemploDatos.csv file." << std::endl;

    // END OF PROGRAM
    return 0;
}