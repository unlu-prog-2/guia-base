project(utilidades)

add_library(utilidades STATIC aserciones.c cadenas.c)

target_include_directories(utilidades PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
