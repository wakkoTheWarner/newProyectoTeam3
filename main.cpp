/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Modulos/FileParser.h"
#include "Modulos/HeaderMaker.h"
#include "Modulos/FileReader.h"
#include "Modulos/FileWriter.h"
#include "Modulos/FileParser.cpp"
#include "Modulos/HeaderMaker.cpp"
#include "Modulos/FileReader.cpp"
#include "Modulos/FileWriter.cpp"

std::string filePathVerifier(std::string filePath);

std::string outputFilePathVerifier(std::string outputFilePath);

int main() {
    // Establecer el idioma local.
    setlocale(LC_ALL, "Spanish");

    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string departamento;
    std::string profesor;
    std::string outputFilePath;

    std::cout << "Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

    filePath = filePathVerifier(filePath);

    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    FileReader fileReader;
    std::vector<Student> students = fileReader.readFile(filePath);

    FileParser fileParser;
    FileParser::CourseInfo courseInfo = fileParser.parseFile(filePath);

    std::cout << "Nombre de Institucion: ";
    std::getline(std::cin, nombreInstitucion);
    std::cout << "Recinto: ";
    std::getline(std::cin, recinto);
    std::cout << "Departamento: ";
    std::getline(std::cin, departamento);
    std::cout << "Profesor: ";
    std::getline(std::cin, profesor);

    // Solicitar al usuario la ruta y nombre del archivo de salida.
    std::cout << "Ingresa la ruta y nombre del archivo de salida: ";
    std::getline(std::cin, outputFilePath);

    outputFilePath = outputFilePathVerifier(outputFilePath);

    HeaderMaker headerMaker;
    std::string header = headerMaker.makeHeader(nombreInstitucion, recinto, departamento, courseInfo.duration, profesor, courseInfo.courseName, courseInfo.crn);

    FileWriter fileWriter;
    fileWriter.writeToFile(students, outputFilePath, header);

    // Informar al usuario que los datos se han exportado.
    std::cout << "Los datos se han exportado al archivo " + outputFilePath << std::endl;

    return 0;
}

std::string filePathVerifier(std::string filePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (filePath.empty()) {
        filePath = "../Resources/Data/ejemploDatos.txt";
    } else if (filePath.find('/') == std::string::npos && filePath.find('\\') == std::string::npos) {
        if (filePath.find(".txt") == std::string::npos) {
            // El usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
            filePath = "../Resources/Data/" + filePath + ".txt";
        } else {
            filePath = "../Resources/Data/" + filePath;
        }
    } else {
        if (filePath.find(".txt") == std::string::npos) {
            // El usuario ha proporcionado una ruta completa, anteponer la ruta del directorio predeterminado
            filePath += ".txt";
        }
    }

    if (filePath.find('\"') != std::string::npos) {
        filePath.erase(std::remove(filePath.begin(), filePath.end(), '\"'), filePath.end());
    }

    return filePath;
}

std::string outputFilePathVerifier(std::string outputFilePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (outputFilePath.empty()) {
        outputFilePath = "../Resources/Output/ejemploDatos.csv";
    } else if (outputFilePath.find('/') == std::string::npos && outputFilePath.find('\\') == std::string::npos) {
        if (outputFilePath.find(".csv") == std::string::npos) {
            // El usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
            outputFilePath = "../Resources/Output/" + outputFilePath + ".csv";
        } else {
            outputFilePath = "../Resources/Output/" + outputFilePath;
        }
    } else {
        if (outputFilePath.find(".csv") == std::string::npos) {
            // El usuario ha proporcionado una ruta completa, anteponer la ruta del directorio predeterminado
            outputFilePath += ".csv";
        }
    }

    if (outputFilePath.find('\"') != std::string::npos) {
        outputFilePath.erase(std::remove(outputFilePath.begin(), outputFilePath.end(), '\"'), outputFilePath.end());
    }

    return outputFilePath;
}
