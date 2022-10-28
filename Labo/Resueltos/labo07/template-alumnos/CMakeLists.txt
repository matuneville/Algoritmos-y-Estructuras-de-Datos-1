cmake_minimum_required(VERSION 3.23)
project(template_alumnos)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(template_alumnos
        cases.cpp
        cases.h
        ejercicios.cpp
        ejercicios.h
        main.cpp)
