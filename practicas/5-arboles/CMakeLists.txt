project(Arboles)

# Habilitar la opción Werror
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

enable_testing()

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

add_library(practica_arboles practica_arboles.c)
target_link_libraries(practica_arboles arboles utilidades m)

foreach (TEST_SOURCE ${TEST_SOURCES})
    # Extraer el nombre del archivo de prueba (sin extensión)
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # Agregar un ejecutable para cada archivo de prueba encontrado
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} practica_arboles arboles utilidades m)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach ()
