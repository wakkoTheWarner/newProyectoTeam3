//
// Created by eduar on 2/27/2024.
//

#ifndef NEWPROYECTOTEAM3_FILEREADER_H
#define NEWPROYECTOTEAM3_FILEREADER_H

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <codecvt>

class FileReader {
public:
    std::vector<std::vector<std::wstring>> readFile(const std::string& filePath);
};

#endif //NEWPROYECTOTEAM3_FILEREADER_H
