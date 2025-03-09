project(tads)

add_library(tipo_elemento STATIC
        tipo_elemento/tipo_elemento.c
)

add_library(aserciones_tipo_elemento STATIC
        tipo_elemento/aserciones_tipo_elemento.c
)

add_library(listas_arreglos STATIC
        tipo_elemento/tipo_elemento.c
        listas/listas_arreglos.c
        listas/util_listas.c
)

add_library(listas_punteros STATIC
        tipo_elemento/tipo_elemento.c
        listas/listas_punteros.c
        listas/util_listas.c
)

add_library(listas_cursores STATIC
        tipo_elemento/tipo_elemento.c
        listas/listas_cursores.c
        listas/util_listas.c
)

add_library(aserciones_listas STATIC
        tipo_elemento/tipo_elemento.c
        tipo_elemento/aserciones_tipo_elemento.c
        listas/aserciones_listas.c
)

add_library(pilas_arreglos STATIC
        pilas/pilas_arreglos.c
        pilas/util_pilas.c
)

add_library(pilas_punteros STATIC
        pilas/pilas_punteros.c
        pilas/util_pilas.c
)

add_library(aserciones_pilas STATIC
        tipo_elemento/tipo_elemento.c
        tipo_elemento/aserciones_tipo_elemento.c
        pilas/aserciones_pilas.c
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

add_library(aserciones_colas STATIC
        tipo_elemento/tipo_elemento.c
        tipo_elemento/aserciones_tipo_elemento.c
        colas/aserciones_colas.c
)

add_library(arboles STATIC
        arboles/arbol-avl.c
        arboles/arbol-binario.c
        arboles/arbol-binario-busqueda.c
        arboles/nodo.c
        arboles/util_arboles.c
)

add_library(tablas_hash_lista_colisiones STATIC
        tabla-hash/tabla-hash-lista-colisiones.c
)

add_library(tablas_hash_zona_overflow STATIC
        tabla-hash/tabla-hash-zona-overflow.c
)

add_library(conjuntos_listas STATIC
        conjuntos/conjuntos-listas.c
)

add_library(conjuntos_avl STATIC
        conjuntos/conjuntos-avl.c
)


target_include_directories(tipo_elemento PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(aserciones_tipo_elemento PUBLIC
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

target_include_directories(aserciones_listas PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(pilas_arreglos PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(pilas_punteros PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(aserciones_pilas PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(colas_arreglos PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(colas_punteros PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(colas_arreglos_circular PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(aserciones_colas PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(arboles PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(tablas_hash_lista_colisiones PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(tablas_hash_zona_overflow PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(conjuntos_listas PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(conjuntos_avl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
