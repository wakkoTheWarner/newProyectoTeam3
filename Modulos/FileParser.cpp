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
    // Set the locale to accept special characters
    std::setlocale(LC_ALL, "");

    std::wifstream file(filePath);
    if (!file.is_open()) {
        std::wcout << L"Unable to open file" << std::endl;
        return;
    }

    // Use UTF-8
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    file.imbue(utf8_locale);

    std::wstring line;
    std::vector<std::vector<std::wstring>> table;

    std::wregex course_re(L"([A-Z]+\\s\\d+)"), crn_re(L"CRN:\\s*(\\d+)"), date_re(L"Duration:\\s*(.+)");

    while (std::getline(file, line)) {
        std::wsmatch match;
        if (std::regex_search(line, match, course_re) && match.size() > 1) {
            course = match.str(1);
        }
        if (std::regex_search(line, match, crn_re) && match.size() > 1) {
            crn = match.str(1);
        }
        if (std::regex_search(line, match, date_re) && match.size() > 1) {
            std::wstring date_str = match.str(1);
            std::tm start_date = {}, end_date = {};
            std::wistringstream ss(date_str);
            //ss >> std::get_time(&start_date, L"%d %b, %Y") >> std::get_time(&end_date, L"- %d %b, %Y");

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
        if (!course.empty() && !crn.empty() && !date.empty()) {
            break;
        }
    }
}

std::wstring FileParser::getCourse() const {
    return course;
}

std::wstring FileParser::getCRN() const {
    return crn;
}

std::wstring FileParser::getDate() const {
    return date;
}