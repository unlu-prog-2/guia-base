project(Colas)

enable_testing()

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

foreach (IMPLEMENTACION arreglos arreglos_circular punteros)
    add_library(practica_colas_${IMPLEMENTACION} practica_colas.c)
    target_link_libraries(practica_colas_${IMPLEMENTACION} colas_${IMPLEMENTACION})

    foreach (TEST_SOURCE ${TEST_SOURCES})
        # Extraer el nombre del archivo de prueba (sin extensión)
        get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

        # Agregar un ejecutable para cada archivo de prueba encontrado
        add_executable(${TEST_NAME}_${IMPLEMENTACION} ${TEST_SOURCE})
        if(${IMPLEMENTACION} STREQUAL "arreglos_circular")
            target_link_libraries(${TEST_NAME}_${IMPLEMENTACION} practica_colas_${IMPLEMENTACION} colas_${IMPLEMENTACION} aserciones_colas listas_punteros pilas_punteros aserciones cadenas m)
        else()
            target_link_libraries(${TEST_NAME}_${IMPLEMENTACION} practica_colas_${IMPLEMENTACION} colas_${IMPLEMENTACION} aserciones_colas listas_punteros pilas_punteros aserciones cadenas m)
        endif()
        add_test(NAME ${TEST_NAME}_${IMPLEMENTACION} COMMAND ${TEST_NAME}_${IMPLEMENTACION})
    endforeach ()
endforeach ()
