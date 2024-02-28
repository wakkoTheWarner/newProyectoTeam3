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
    // Establecer el idioma local.
    std::setlocale(LC_ALL, "");

    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string profesor;

    // Solicitar al usuario la ruta del archivo.
    std::cout << "Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

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

    // Crear un escritor de archivos.
    FileWriter writer;
    // Crear un objeto de configuración regional para UTF-8.
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    // Escribir los datos en un archivo de salida.
    writer.writeToFile("output.csv", filePath, utf8_locale, parser, header, content, nombreInstitucion, recinto, profesor);

    // Informar al usuario que los datos se han exportado.
    std::wcout << L"Los datos se han exportado al archivo ejemploDatos.csv" << std::endl;

    return 0;
}