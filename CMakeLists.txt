cmake_minimum_required(VERSION 3.27)
project(newProyectoTeam3)

set(CMAKE_CXX_STANDARD 17)

add_executable(newProyectoTeam3 main.cpp
        Modulos/FileReader.cpp
        Modulos/FileReader.h
        Modulos/FileWriter.cpp
        Modulos/FileWriter.h
        Modulos/Students.cpp
        Modulos/Students.h
        Modulos/HeaderMaker.cpp
        Modulos/HeaderMaker.h
        Modulos/FileParser.cpp
        Modulos/FileParser.h
)
