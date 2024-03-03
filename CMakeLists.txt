cmake_minimum_required(VERSION 3.27)
project(COMP3800ProyectoCpp03)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
set_target_properties(main PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_NAME main)
