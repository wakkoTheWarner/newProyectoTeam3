/**
 * Objetivo: El código de main() solicita al usuario la ruta de un archivo de entrada, lee y procesa los datos del archivo, solicita información adicional al usuario, y finalmente escribe los datos procesados y la información adicional en un archivo de salida.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de entrada cuando se le solicite. Esta cadena puede estar vacía, contener solo el nombre del archivo o la ruta completa del archivo.
 *                 El archivo de entrada debe existir en la ruta proporcionada y debe ser legible.
 *                 El usuario debe proporcionar información válida cuando se le solicite.
 *
 * Postcondiciones: Se crea un archivo de salida en la ruta especificada con los datos procesados y la información adicional.
 *                  Si el archivo de entrada no se puede abrir, el programa termina con un mensaje de error.
 *
 * Descripción de argumentos:
 *                 `filePath`: Una cadena que representa la ruta del archivo de entrada. Se solicita al usuario que introduzca esta ruta.
 *                 `nombreInstitucion`: Una cadena que representa el nombre de la institución. Se solicita al usuario que introduzca esta información.
 *                 `recinto`: Una cadena que representa el campus. Se solicita al usuario que introduzca esta información.
 *                 `departamento`: Una cadena que representa el departamento. Se solicita al usuario que introduzca esta información.
 *                 `profesor`: Una cadena que representa el nombre del profesor. Se solicita al usuario que introduzca esta información.
 *                 `outputFilePath`: Una cadena que representa la ruta del archivo de salida. Se solicita al usuario que introduzca esta ruta.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
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

    // Solicitar al usuario la ruta del archivo de entrada.
    std::cout << "Ingresa la ruta del archivo: ";
    std::getline(std::cin, filePath);

    // Verificar la ruta del archivo proporcionada por el usuario.
    filePath = filePathVerifier(filePath);

    // Verificar si el archivo se abrió correctamente.
    std::ifstream ifile;
    ifile.open(filePath);

    // Verificar si el archivo se abrió correctamente.
    if (!ifile.is_open()){
        std::cerr << "Error al abrir el archivo \"" << filePath << "\". Por favor, verifica la ruta del archivo e intenta de nuevo.\n";
        return 0;
    }

    // Leer los datos del archivo de entrada.
    FileReader fileReader;
    std::vector<Student> students = fileReader.readFile(filePath);

    // Procesar los datos del archivo de entrada.
    FileParser fileParser;
    FileParser::CourseInfo courseInfo = fileParser.parseFile(filePath);

    // Solicitar al usuario información adicional.
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

    // Verificar la ruta del archivo de salida proporcionada por el usuario.
    outputFilePath = outputFilePathVerifier(outputFilePath);

    // Crear el encabezado del archivo de salida.
    HeaderMaker headerMaker;
    std::string header = headerMaker.makeHeader(nombreInstitucion, recinto, departamento, courseInfo.duration, profesor, courseInfo.courseName, courseInfo.crn);

    // Escribir los datos procesados y la información adicional en el archivo de salida.
    FileWriter fileWriter;
    fileWriter.writeToFile(students, outputFilePath, header);

    // Informar al usuario que los datos se han exportado.
    std::cout << "Los datos se han exportado al archivo " + outputFilePath << std::endl;

    return 0;
}

/**
 * Objetivo: Esta función verifica y ajusta la ruta del archivo proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensión .txt, se añade la extensión.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo.
 *                 Esta cadena puede estar vacía, contener solo el nombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa la ruta completa del archivo con la extensión .txt.
 *                  Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
 **/
std::string filePathVerifier(std::string filePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (filePath.empty()) {
        filePath = "../Resources/Data/ejemploDatos.txt";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (filePath.find('/') == std::string::npos && filePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensión .txt, añadirla
        if (filePath.find(".txt") == std::string::npos) {
            filePath = "../Resources/Data/" + filePath + ".txt";
        } else {
            filePath = "../Resources/Data/" + filePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensión .txt, añadirla
        if (filePath.find(".txt") == std::string::npos) {
            filePath += ".txt";
        }
    }

    // Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, eliminarlas
    if (filePath.find('\"') != std::string::npos) {
        filePath.erase(std::remove(filePath.begin(), filePath.end(), '\"'), filePath.end());
    }

    return filePath;
}

/**
 * Objetivo: Esta función verifica y ajusta la ruta del archivo de salida proporcionada por el usuario. Si el usuario no proporciona una ruta, se utiliza una ruta predeterminada. Si el usuario proporciona solo un nombre de archivo, se antepone la ruta del directorio predeterminado. Si el usuario proporciona una ruta completa sin la extensión .csv, se añade la extensión.
 *
 * Precondiciones: El usuario debe proporcionar una cadena de texto que represente la ruta del archivo de salida.
 *                 Esta cadena puede estar vacía, contener solo el ombre del archivo o la ruta completa del archivo.
 *
 * Postcondiciones: La función devuelve una cadena de texto que representa la ruta completa del archivo de salida con la extensión .csv.
 *                  Si la ruta del archivo de salida proporcionada por el usuario contiene comillas dobles, estas se eliminan.
 *
 * Descripción de argumentos:
 *
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 29-02-2024
 **/
std::string outputFilePathVerifier(std::string outputFilePath) {
    // Si el usuario no ha proporcionado una ruta, usar la ruta predeterminada.
    if (outputFilePath.empty()) {
        outputFilePath = "../Resources/Output/ejemploDatos.csv";
    }
        // Si el usuario solo ha proporcionado un nombre de archivo, anteponer la ruta del directorio predeterminado
    else if (outputFilePath.find('/') == std::string::npos && outputFilePath.find('\\') == std::string::npos) {
        // Si el nombre del archivo no tiene la extensión .csv, añadirla
        if (outputFilePath.find(".csv") == std::string::npos) {
            outputFilePath = "../Resources/Output/" + outputFilePath + ".csv";
        } else {
            outputFilePath = "../Resources/Output/" + outputFilePath;
        }
    } else {
        // Si el usuario ha proporcionado una ruta completa sin la extensión .csv, añadirla
        if (outputFilePath.find(".csv") == std::string::npos) {
            outputFilePath += ".csv";
        }
    }

    // Si la ruta del archivo proporcionada por el usuario contiene comillas dobles, eliminarlas
    if (outputFilePath.find('\"') != std::string::npos) {
        outputFilePath.erase(std::remove(outputFilePath.begin(), outputFilePath.end(), '\"'), outputFilePath.end());
    }

    return outputFilePath;
}
