project(utilidades)

add_library(utilidades STATIC aserciones.c cadenas.c util_listas.c)
target_link_libraries(utilidades tipo_elemento listas_arreglos pilas_arreglos)

target_include_directories(utilidades PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
