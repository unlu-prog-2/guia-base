project(Conjuntos)

# Habilitar la opción Werror
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

enable_testing()

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

foreach (IMPLEMENTACION listas avl)
    add_library(practica_conjuntos_${IMPLEMENTACION} practica_conjuntos.c)
    target_link_libraries(practica_conjuntos_${IMPLEMENTACION} conjuntos_${IMPLEMENTACION})

    foreach (TEST_SOURCE ${TEST_SOURCES})
        # Extraer el nombre del archivo de prueba (sin extensión)
        get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

        # Agregar un ejecutable para cada archivo de prueba encontrado
        add_executable(${TEST_NAME}_${IMPLEMENTACION} ${TEST_SOURCE})
        target_link_libraries(${TEST_NAME}_${IMPLEMENTACION} practica_conjuntos_${IMPLEMENTACION} conjuntos_${IMPLEMENTACION} aserciones cadenas m)
        add_test(NAME ${TEST_NAME}_${IMPLEMENTACION} COMMAND ${TEST_NAME}_${IMPLEMENTACION})
    endforeach ()
endforeach ()
