project(TablasHash)

# Habilitar la opción Werror
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

enable_testing()

# Copiar los archivos de datos
file(GLOB DATA_FILES "tests/archivos/*.dat")
foreach (DATA_FILE ${DATA_FILES})
    get_filename_component(FILE_NAME ${DATA_FILE} NAME)
    configure_file(${DATA_FILE} ${FILE_NAME} COPYONLY)
endforeach ()

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

foreach (IMPLEMENTACION lista_colisiones zona_overflow)
    add_library(practica_tablas_hash_${IMPLEMENTACION} practica_tablas_hash.c)
    target_link_libraries(practica_tablas_hash_${IMPLEMENTACION} tablas_hash_${IMPLEMENTACION})

    add_executable(tablas_hash_${IMPLEMENTACION}_vs_arboles_avl tests/tablas_hash_vs_arboles_avl.c)
    target_link_libraries(tablas_hash_${IMPLEMENTACION}_vs_arboles_avl practica_tablas_hash_${IMPLEMENTACION} tablas_hash_${IMPLEMENTACION} arboles listas_punteros aserciones cadenas m)

    foreach (TEST_SOURCE ${TEST_SOURCES})
        # Extraer el nombre del archivo de prueba (sin extensión)
        get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

        # Agregar un ejecutable para cada archivo de prueba encontrado
        add_executable(${TEST_NAME}_${IMPLEMENTACION} ${TEST_SOURCE})
        target_link_libraries(${TEST_NAME}_${IMPLEMENTACION} practica_tablas_hash_${IMPLEMENTACION} tablas_hash_${IMPLEMENTACION} arboles listas_punteros aserciones cadenas m)
        add_test(NAME ${TEST_NAME}_${IMPLEMENTACION} COMMAND ${TEST_NAME}_${IMPLEMENTACION})
    endforeach ()
endforeach ()
