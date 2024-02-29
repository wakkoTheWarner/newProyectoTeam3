/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "TableHeaderExtractor.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <string>
#include <codecvt>
#include <clocale>
#include <iostream>
#include <algorithm>

std::vector<std::wstring> TableHeaderExtractor::extractHeader(const std::string& filePath) {
    // Establecer la configuración regional a la predeterminada del sistema
    std::setlocale(LC_ALL, "");

    // Crear un objeto de archivo de entrada de flujo ancho
    std::wifstream file(filePath);

    // Si el archivo no se puede abrir, imprimir un mensaje de error y devolver un vector vacío
    if (!file.is_open()) {
        std::wcout << L"No se puede abrir el archivo" << std::endl;
        return std::vector<std::wstring>();
    }

    // Crear un objeto de configuración regional que soporte UTF-8
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());

    // Aplicar la configuración regional al archivo
    file.imbue(utf8_locale);

    // Crear una cadena de caracteres ancha para almacenar cada línea del archivo
    std::wstring line;

    // Crear un vector para almacenar el encabezado
    std::vector<std::wstring> header;

    // Leer el archivo línea por línea
    while (std::getline(file, line)) {
        // Si la línea comienza con "Number"
        if (line.substr(0, 6) == L"Number") {
            // Crear un objeto de flujo de entrada de cadena ancha con la línea
            std::wistringstream iss(line);

            // Crear una cadena de caracteres ancha para almacenar cada palabra
            std::wstring word;

            // Inserta la cadena "NUM" en el vector de encabezado
            header.push_back(L"NUM");
            // Inserta la cadena "NOMBRE" en el vector de encabezado
            header.push_back(L"NOMBRE");
            // Inserta la cadena "ID" en el vector de encabezado
            header.push_back(L"ID");
            // Inserta la cadena "Email" en el vector de encabezado
            header.push_back(L"Email");
            // Inserta la cadena "Telefono" en el vector de encabezado
            header.push_back(L"Telefono");

            // Salir del bucle una vez que se ha encontrado el encabezado
            break;
        }
    }

    // Cerrar el archivo
    file.close();

    // Devolver el encabezado
    return header;
}

std::wstring TableHeaderExtractor::trimTrailingSpaces(const std::wstring& str) {
    // Crear una copia de la cadena
    std::wstring s = str;
    // Eliminar los espacios al final de la cadena
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        // Devolver si el carácter no es un espacio
        return !std::isspace(ch);
    }).base(), s.end());
    // Devolver la cadena modificada
    return s;
}