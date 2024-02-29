/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <iostream>
#include <fstream>
#include "Modulos/FileParser.h"
#include "Modulos/HeaderMaker.h"
#include "Modulos/FileReader.h"
#include "Modulos/FileWriter.h"

int main() {
    // Establecer el idioma local.
    setlocale(LC_ALL, "Spanish");

    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string departamento;
    std::string profesor;
    std::string outputFilePath;

    std::wcout << L"Ingresa la ruta del archivo: ";
    std::wstring wFilePath;
    std::getline(std::wcin, wFilePath);

    filePath = std::string(wFilePath.begin(), wFilePath.end());

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

    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    FileReader fileReader;
    std::vector<Student> students = fileReader.readFile(filePath);

    // Create a FileParser object and parse the file
    FileParser fileParser;
    fileParser.parseFile(filePath);

    // Get the semester and course number from the FileParser
    std::wstring semesterW = fileParser.getDate();
    std::wstring courseNameW = fileParser.getCourse();
    std::wstring crnW = fileParser.getCRN();

    // Convert the semester and course number from wide string to string
    std::string semester(semesterW.begin(), semesterW.end());
    std::string courseName(courseNameW.begin(), courseNameW.end());
    std::string crn(crnW.begin(), crnW.end());

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

    HeaderMaker headerMaker;
    std::string header = headerMaker.makeHeader(nombreInstitucion, recinto, departamento, semester, profesor, courseName, crn);

    FileWriter fileWriter;
    fileWriter.writeToFile(students, outputFilePath, header);

    // Informar al usuario que los datos se han exportado.
    std::wstring outputFilePathW(outputFilePath.begin(), outputFilePath.end());
    std::wcout << L"Los datos se han exportado al archivo " + outputFilePathW << std::endl;

    return 0;
}
