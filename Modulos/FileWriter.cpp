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

void FileWriter::writeToFile(const std::string& filename, const std::string& filePath, const std::locale utf8_locale, const FileParser& parser, const std::vector<std::wstring>& header, const std::vector<std::vector<std::wstring>>& content, const std::string& nombreInstitucion, const std::string& recinto, const std::string& profesor) {
    // Crear un flujo de salida de archivo con el nombre de archivo dado.
    std::wofstream out(filename);
    // Establecer la configuración regional del flujo de salida en la configuración regional UTF-8.
    out.imbue(utf8_locale);
    // Escribir información fija en el archivo.
    out << L"," + capitalizeAll(std::wstring(nombreInstitucion.begin(), nombreInstitucion.end())) + L"\n";
    out << L"," + capitalizeAll(std::wstring(recinto.begin(), recinto.end())) + L"\n";
    out << L",DEPARTAMENTO DE CIENCIAS EN COMPUTADORAS\n";
    out << L"\n";
    // Escribir información procesada en el archivo.
    out << L"SEMESTRE: " + parser.getDate() + L"\n";
    out << L"PROFESOR: " + capitalizeAll(std::wstring(profesor.begin(), profesor.end())) + L"\n";
    out << L"CURSO: " + parser.getCourse() + L" (" + parser.getCRN() + L")\n";
    out << L"\n";
    out << L"\n";
    // Escribir los encabezados de la tabla en el archivo.
    for (size_t i = 0; i < header.size(); ++i) {
        out << header[i];
        if (i < header.size() - 1) {
            out << L',';
        }
    }
    out << '\n';
    // Crear una expresión regular para coincidir con los espacios al final de la cadena.
    std::wregex trailing_spaces(L"\\s+$");
    // Escribir el contenido de la tabla en el archivo.
    for (const auto &row : content) {
        size_t cell_count = 0;
        for (const auto &cell : row) {
            // Si la celda contiene un espacio, eliminar los espacios al final y escribir la celda entre comillas.
            if (cell.find(L' ') != std::wstring::npos) {
                std::wstring trimmed_cell = std::regex_replace(cell, trailing_spaces, L"");
                out << L'"' << trimmed_cell << L'"';
            } else {
                // Si la celda no contiene un espacio, escribir la celda tal cual.
                out << cell;
            }
            // Si no es la última celda de la fila, escribir una coma.
            if (++cell_count < row.size()) {
                out << L',';
            }
        }
        // Escribir un salto de línea al final de cada fila.
        out << '\n';
    }
    // Cerrar el archivo de salida.
    out.close();
}

std::wstring FileWriter::capitalizeAll(std::wstring s){
    std::transform(s.begin(), s.end(), s.begin(), [](wchar_t c){ return std::towupper(c); });
    return s;
}