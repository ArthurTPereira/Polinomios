cmake_minimum_required(VERSION 3.10)
project(Polinomios C)

set(CMAKE_C_STANDARD 99)

add_executable(Polinomios
        polinomioD.c
        polinomioD.h
        polinomioLI.c
        polinomioLI.h
        main.c)