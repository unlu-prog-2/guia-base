cmake_minimum_required(VERSION 3.24)
project(empty_project C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(tads)
add_subdirectory(utilidades)

add_subdirectory(practicas/0-repaso)
add_subdirectory(practicas/1-recursividad)
add_subdirectory(practicas/2-listas)

enable_testing()
