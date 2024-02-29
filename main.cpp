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

/**
 * La función principal del programa.
 * Maneja las operaciones de lectura, análisis y escritura de archivos.
 *
 * @return int - Devuelve 0 si el programa se ejecuta con éxito.
 */
int main() {
    // Establecer el idioma local.
    std::setlocale(LC_ALL, "");

    // Variables para almacenar las rutas de los archivos y las entradas del usuario.
    std::string filePath;
    std::string nombreInstitucion;
    std::string recinto;
    std::string profesor;
    std::string outputFilePath;

    // Solicitar al usuario la ruta del archivo.
    std::wcout << L"Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado.
    // Si el usuario ha proporcionado una ruta completa, agregar ".txt" si no está ya allí.

    // Abrir el archivo.
    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    // Crear un lector de archivos y leer el archivo.
    FileReader reader;
    std::vector<std::vector<std::wstring>> content = reader.readFile(filePath);

    // Crear un analizador de archivos y analizar el archivo.
    FileParser parser;
    parser.parseFile(filePath);

    // Crear un extractor de encabezados de tabla y extraer el encabezado del archivo.
    TableHeaderExtractor extractor;
    std::vector<std::wstring> header = extractor.extractHeader(filePath);

    // Solicitar las entradas del usuario.
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
    // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado.
    // Si el usuario ha proporcionado una ruta completa, agregar ".csv" si no está ya allí.

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