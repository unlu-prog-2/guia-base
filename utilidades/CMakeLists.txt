project(utilidades)

add_library(utilidades STATIC aserciones.c cadenas.c util_listas.c)
target_link_libraries(utilidades tads)

target_include_directories(utilidades PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
