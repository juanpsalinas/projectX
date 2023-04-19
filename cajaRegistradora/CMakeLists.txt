cmake_minimum_required(VERSION 3.25)
project(cajaRegistradora C)

set(CMAKE_C_STANDARD 11)

add_executable(cajaRegistradora main.c imprimir.c registro.c utils.c)
