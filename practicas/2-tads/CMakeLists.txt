project(TiposAbstractosDeDatos)

enable_testing()

add_library(numero-racional numero-racional.c)
add_library(fecha-juliano fecha-juliano.c)
add_library(fecha-struct fecha-struct.c)

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

add_executable(test_numero_racional tests/test_racional.c)
target_link_libraries(test_numero_racional numero-racional utilidades)
add_test(NAME test_numero_racional COMMAND test_numero_racional)

#add_executable(test_fecha_struct tests/test_fecha.c)
#target_link_libraries(test_fecha_struct fecha-struct utilidades)
#add_test(NAME test_fecha_struct COMMAND test_fecha_struct)

add_executable(test_fecha_juliano tests/test_fecha.c)
target_link_libraries(test_fecha_juliano fecha-juliano utilidades m)
add_test(NAME test_fecha_juliano COMMAND test_fecha_juliano)
