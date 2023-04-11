project(tads)

add_library(tipo_elemento STATIC
        tipo_elemento.c
        )

add_library(listas_arreglos STATIC
        listas/listas_arreglos.c
        )

add_library(listas_punteros STATIC
        listas/listas_punteros.c
        )

add_library(listas_cursores STATIC
        listas/listas_cursores.c
        )

target_include_directories(tipo_elemento PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(listas_arreglos PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(listas_punteros PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(listas_cursores PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
