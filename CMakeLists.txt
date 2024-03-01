cmake_minimum_required(VERSION 3.27)
project(newProyectoTeam3)

set(CMAKE_CXX_STANDARD 17)

add_executable(newProyectoTeam3 main.cpp
        Modulos/FileReader.h
        Modulos/FileWriter.h
        Modulos/Students.h
        Modulos/HeaderMaker.h
        Modulos/FileParser.h
)
