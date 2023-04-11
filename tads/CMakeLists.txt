project(tads)

add_library(tads STATIC
        tipo_elemento.c
        listas/listas_arreglos.c
        listas/listas_cursores.c
        listas/listas_punteros.c
        )

target_include_directories(tads PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
