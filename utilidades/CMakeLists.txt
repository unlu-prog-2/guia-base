project(utilidades)

# Habilitar la opción Werror
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")

add_library(aserciones STATIC aserciones.c)
target_link_libraries(aserciones)
target_include_directories(aserciones PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(cadenas STATIC cadenas.c)
target_link_libraries(cadenas)
target_include_directories(cadenas PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
