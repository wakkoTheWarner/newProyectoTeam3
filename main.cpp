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
#include "Modulos/TableHeaderExtractor.h"
#include "Modulos/FileReader.h"
#include "Modulos/FileWriter.h"

int main() {
    // Establecer el idioma local.
    std::setlocale(LC_ALL, "");

    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string profesor;
    std::string outputFilePath;

    // Solicitar al usuario la ruta del archivo.
    std::wcout << L"Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

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
        // El usuario ha proporcionado una ruta completa, anteponer la ruta del directorio predeterminado
        filePath;
    }

    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    // Crear un lector de archivos.
    FileReader reader;
    // Leer el archivo.
    std::vector<std::vector<std::wstring>> content = reader.readFile(filePath);

    // Crear un analizador de archivos.
    FileParser parser;
    // Analizar el archivo.
    parser.parseFile(filePath);

    // Crear un extractor de encabezados de tabla.
    TableHeaderExtractor extractor;
    // Extraer el encabezado del archivo.
    std::vector<std::wstring> header = extractor.extractHeader(filePath);

    std::cout << "Nombre de Institucion: ";
    std::getline(std::cin, nombreInstitucion);
    std::cout << "Recinto: ";
    std::getline(std::cin, recinto);
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
        // El usuario ha proporcionado una ruta completa, anteponer la ruta del directorio predeterminado
        outputFilePath;
    }

    // Crear un escritor de archivos.
    FileWriter writer;
    // Crear un objeto de configuración regional para UTF-8.
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    // Escribir los datos en un archivo de salida.
    writer.writeToFile(outputFilePath, filePath, utf8_locale, parser, header, content, nombreInstitucion, recinto, profesor);

    // Informar al usuario que los datos se han exportado.
    std::wstring outputFilePathW(outputFilePath.begin(), outputFilePath.end());
    std::wcout << L"Los datos se han exportado al archivo " + outputFilePathW << std::endl;

    return 0;
}
