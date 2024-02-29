/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include <string>
#include <fstream>
#include <iostream>
#include <codecvt>
#include <vector>
#include <regex>
#include "FileReader.h"

std::vector<std::vector<std::wstring>> FileReader::readFile(const std::string& filePath) {
    // Establecer la configuración regional en la configuración regional predeterminada del usuario.
    std::setlocale(LC_ALL, "");

    // Abrir el archivo con la ruta de archivo dada.
    std::wifstream file(filePath);

    // Si el archivo no se puede abrir, imprimir un mensaje de error y devolver un vector vacío.
    if (!file.is_open()) {
        std::wcout << L"No se puede abrir el archivo" << std::endl;
        return std::vector<std::vector<std::wstring>>();
    }

    // Establecer la configuración regional del flujo de archivo en una configuración regional UTF-8.
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    file.imbue(utf8_locale);

    // Declarar una cadena amplia para contener cada línea del archivo.
    std::wstring line;

    // Declarar un vector 2D para contener el contenido del archivo.
    std::vector<std::vector<std::wstring>> content;

    // Leer el archivo línea por línea.
    while (std::getline(file, line)) {

        // Si la línea contiene "** Registered **", omitir la parte de la línea que sigue a esta cadena.
        std::size_t pos = line.find(L"** Registered **");
        if (pos != std::wstring::npos) {
            line = line.substr(0, pos);
        }

        // Si la línea no está vacía y no comienza con un dígito, omitirla.
        if (!line.empty() && !iswdigit(line[0])) {
            continue;
        }

        // Si la línea no está vacía y comienza con un dígito o una letra,
        // dividirla por tabulaciones y agregarla al vector de contenido.
        if (!line.empty() && (iswdigit(line[0]) || iswalpha(line[0]))) {

            // Declarar un vector para contener las partes divididas de la línea.
            std::vector<std::wstring> row;

            // Declarar una expresión regular para coincidir con las tabulaciones que no están al final de la línea.
            std::wregex ws_re(L"\\t(?!$)");

            // Dividir la línea por la expresión regular y agregar las partes al vector de fila.
            std::copy(std::wsregex_token_iterator(line.begin(), line.end(), ws_re, -1),
                      std::wsregex_token_iterator(),
                      std::back_inserter(row));

            // Agregar la fila al vector de contenido.
            content.push_back(row);
        }
    }

    // Cerrar el archivo.
    file.close();

    // Devolver el contenido del archivo.
    return content;
}