/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "FileParser.h"
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

void FileParser::parseFile(const std::string& filePath) {
    // Establecer la configuración regional para aceptar caracteres especiales
    std::setlocale(LC_ALL, "");

    // Abrir el archivo
    std::wifstream file(filePath);
    // Si no se puede abrir el archivo, mostrar un mensaje de error y terminar la función
    if (!file.is_open()) {
        std::wcout << L"No se puede abrir el archivo" << std::endl;
        return;
    }

    // Usar UTF-8
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    file.imbue(utf8_locale);

    // Crear una línea y una tabla para almacenar los datos
    std::wstring line;
    std::vector<std::vector<std::wstring>> table;

    // Crear expresiones regulares para buscar el curso, el CRN y la fecha
    std::wregex course_re(L"([A-Z]+\\s\\d+)"), crn_re(L"CRN:\\s*(\\d+)"), date_re(L"Duration:\\s*(.+)");

    // Leer el archivo línea por línea
    while (std::getline(file, line)) {
        std::wsmatch match;
        // Si la línea contiene el curso, almacenarlo
        if (std::regex_search(line, match, course_re) && match.size() > 1) {
            course = match.str(1);
        }
        // Si la línea contiene el CRN, almacenarlo
        if (std::regex_search(line, match, crn_re) && match.size() > 1) {
            crn = match.str(1);
        }
        // Si la línea contiene la fecha, almacenarla
        if (std::regex_search(line, match, date_re) && match.size() > 1) {
            std::wstring date_str = match.str(1);
            std::tm start_date = {}, end_date = {};

            // Crear una expresión regular para buscar el año
            std::wregex year_re(L"\\d{4}");
            std::wsmatch year_match;

            // Crear una expresión regular para buscar el año
            if (std::regex_search(date_str, year_match, year_re) && year_match.size() > 0) {
                // Almacenar el año en la fecha de inicio y fin
                end_date.tm_year = std::stoi(year_match.str(0)) - 1900;
            }

            // Crear variables para los meses de inicio y fin
            std::wstring start_month, end_month;
            switch (start_date.tm_mon) {
                case 0: start_month = L"ENERO"; break;
                case 1: start_month = L"FEBRERO"; break;
                case 2: start_month = L"MARZO"; break;
                case 3: start_month = L"ABRIL"; break;
                case 4: start_month = L"MAYO"; break;
                case 5: start_month = L"JUNIO"; break;
                case 6: start_month = L"JULIO"; break;
                case 7: start_month = L"AGOSTO"; break;
                case 8: start_month = L"SEPTIEMBRE"; break;
                case 9: start_month = L"OCTUBRE"; break;
                case 10: start_month = L"NOVIEMBRE"; break;
                case 11: start_month = L"DICIEMBRE"; break;
            }
            switch (end_date.tm_mon) {
                case 0: end_month = L"ENERO"; break;
                case 1: end_month = L"FEBRERO"; break;
                case 2: end_month = L"MARZO"; break;
                case 3: end_month = L"ABRIL"; break;
                case 4: end_month = L"MAYO"; break;
                case 5: end_month = L"JUNIO"; break;
                case 6: end_month = L"JULIO"; break;
                case 7: end_month = L"AGOSTO"; break;
                case 8: end_month = L"SEPTIEMBRE"; break;
                case 9: end_month = L"OCTUBRE"; break;
                case 10: end_month = L"NOVIEMBRE"; break;
                case 11: end_month = L"DICIEMBRE"; break;
            }
            date = start_month + L"-" + end_month + L" " + std::to_wstring(end_date.tm_year + 1900);
        }
        // Si se han encontrado el curso, el CRN y la fecha, terminar el bucle
        if (!course.empty() && !crn.empty() && !date.empty()) {
            break;
        }
    }
}

// Devolver el curso
std::wstring FileParser::getCourse() const {
    return course;
}

// Devolver el CRN
std::wstring FileParser::getCRN() const {
    return crn;
}

// Devolver la fecha
std::wstring FileParser::getDate() const {
    return date;
}