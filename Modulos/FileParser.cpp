/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "FileParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileParser::CourseInfo FileParser::parseFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    CourseInfo courseInfo;

    while (std::getline(file, line)) {
        if (line.find("Course Information") != std::string::npos) {
            std::getline(file, line);
            std::istringstream iss(line);
            std::string courseName;

            std::getline(iss, courseName, '\t');

            courseName.erase(0, courseName.find(" - ") + 3);
            courseName.erase(courseName.end() - 1, courseName.end());

            courseInfo.courseName = courseName;
        } else if (line.find("CRN:") != std::string::npos) {
            std::istringstream iss(line);
            std::string crn;

            std::getline(iss, crn, '\t'); // read until the colon
            std::getline(iss, crn); // read the rest of the line

            courseInfo.crn = crn;
        } else if (line.find("Duration:") != std::string::npos) {
            std::istringstream iss(line);
            std::string duration;

            std::getline(iss, duration, '\t'); // read until the colon
            std::getline(iss, duration); // read the rest of the line

            courseInfo.duration = modifyDuration(duration);
        }
    }

    return courseInfo;
}

std::string FileParser::modifyDuration(std::string duration) {
    std::istringstream iss(duration);
    std::string startDate, endDate;

    std::getline(iss, startDate, '-');
    std::getline(iss, endDate);

    startDate.erase(startDate.find(','), 1);
    endDate.erase(endDate.find(','), 1);

    std::istringstream startIss(startDate);
    std::istringstream endIss(endDate);

    std::string startDay, startMonth, startYear;
    std::string endDay, endMonth, endYear;

    startIss >> startDay >> startMonth >> startYear;
    endIss >> endDay >> endMonth >> endYear;

    for (auto & c: startMonth) c = toupper(c);
    for (auto & c: endMonth) c = toupper(c);

    startMonth = monthTranslator(startMonth);
    endMonth = monthTranslator(endMonth);

    return startMonth + "-" + endMonth + " " + startYear;
}

std::string FileParser::monthTranslator(std::string month) {
    if (month == "JAN") {
        return "ENERO";
    } else if (month == "FEB") {
        return "FEBRERO";
    } else if (month == "MAR") {
        return "MARZO";
    } else if (month == "APR") {
        return "ABRIL";
    } else if (month == "MAY") {
        return "MAYO";
    } else if (month == "JUN") {
        return "JUNIO";
    } else if (month == "JUL") {
        return "JULIO";
    } else if (month == "AUG") {
        return "AGOSTO";
    } else if (month == "SEP") {
        return "SEPTIEMBRE";
    } else if (month == "OCT") {
        return "OCTUBRE";
    } else if (month == "NOV") {
        return "NOVIEMBRE";
    } else if (month == "DEC") {
        return "DICIEMBRE";
    }
    return {};
}
