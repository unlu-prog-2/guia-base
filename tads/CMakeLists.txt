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

add_library(pilas_arreglos STATIC
        pilas/pilas_arreglos.c
        pilas/util_pilas.c
        )

add_library(pilas_punteros STATIC
        pilas/pilas_punteros.c
        pilas/util_pilas.c
        )

add_library(colas_arreglos STATIC
        colas/colas_arreglos.c
        colas/util_colas.c
        )

add_library(colas_punteros STATIC
        colas/colas_punteros.c
        colas/util_colas.c
        )

add_library(colas_arreglos_circular STATIC
        colas/colas_arreglos_circular.c
        colas/util_colas.c
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

target_include_directories(pilas_arreglos PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(pilas_punteros PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(colas_arreglos PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(colas_arreglos_circular PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_include_directories(colas_punteros PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
