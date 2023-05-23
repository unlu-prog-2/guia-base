cmake_minimum_required(VERSION 3.24)
project(empty_project C)

set(CMAKE_C_STANDARD 11)

# Habilitar todas las advertencias
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(tads)
add_subdirectory(utilidades)

add_subdirectory(practicas/0-repaso)
add_subdirectory(practicas/1-recursividad)
add_subdirectory(practicas/2-listas)
add_subdirectory(practicas/3-pilas)
add_subdirectory(practicas/4-colas)
add_subdirectory(practicas/5-arboles)

enable_testing()
