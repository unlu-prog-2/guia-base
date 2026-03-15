#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"

// Función para imprimir los nombres de los jugadores
void imprimirJugadores(struct Jugador jugadores[]) {
    for (int i = 0; i < CANT_JUGADORES; i++) {
        printf("%-20s\t%d\t%d\n", jugadores[i].nombre, jugadores[i].edad, jugadores[i].partidosJugados);
    }
}

static void cargarEquipoBase(struct Jugador equipo[CANT_JUGADORES]) {
    struct Jugador base[CANT_JUGADORES] = {
            {"Messi",       34, 800},
            {"Ronaldo",     37, 900},
            {"Neymar Jr.",  29, 500},
            {"Mbappe",      22, 200},
            {"Lewandowski", 33, 700},
            {"Salah",       29, 400},
            {"De Bruyne",   30, 600},
            {"van Dijk",    30, 400},
            {"Ramos",       35, 650},
            {"Neuer",       35, 800},
            {"Davies",      20, 100}
    };

    memcpy(equipo, base, sizeof(base));
}

static void test_jugadores_ordenados_por_partidos(void) {
    struct Jugador equipo[CANT_JUGADORES];
    cargarEquipoBase(equipo);

    struct Jugador *ordenado = jugadoresOrdenadosPorCantDePartidos(equipo);
    printf("Jugadores ordenados por partidos jugados:\n");
    imprimirJugadores(ordenado);
    assert(ptr_not_null(ordenado));

    int max = ordenado[0].partidosJugados;
    for (size_t i = 1; i < CANT_JUGADORES; i++) {
        assert(int_lte(ordenado[i].partidosJugados, max));
        max = ordenado[i].partidosJugados;
    }

    assert(int_eq(ordenado[0].partidosJugados, 900));
    assert(int_eq(ordenado[CANT_JUGADORES - 1].partidosJugados, 100));
}

static void test_jugadores_ordenados_por_edad(void) {
    struct Jugador equipo[CANT_JUGADORES];
    cargarEquipoBase(equipo);

    struct Jugador *ordenado = jugadoresOrdenadosPorEdad(equipo);
    printf("Jugadores ordenados por edad:\n");
    imprimirJugadores(ordenado);

    assert(ptr_not_null(ordenado));

    int min = ordenado[0].edad;
    for (size_t i = 1; i < CANT_JUGADORES; i++) {
        assert(int_gte(ordenado[i].edad, min));
        min = ordenado[i].edad;
    }

    assert(int_eq(ordenado[0].edad, 20));
    assert(int_eq(ordenado[CANT_JUGADORES - 1].edad, 37));
}

static void test_promedio_partidos_jugados_con_datos(void) {
    struct Jugador equipo[CANT_JUGADORES];
    cargarEquipoBase(equipo);

    float promedio = promedioDePartidosJugados(equipo, 35);
    assert(float_eq(promedio, 725.0f));
}

static void test_promedio_partidos_jugados_sin_datos(void) {
    struct Jugador equipo[CANT_JUGADORES];
    cargarEquipoBase(equipo);

    float promedio = promedioDePartidosJugados(equipo, 99);
    assert(float_eq(promedio, 0.0f));
}

int main() {
    imprimir_titulo("Tests de Ejercicio 4");
    // test_jugadores_ordenados_por_partidos();
    // test_jugadores_ordenados_por_edad();
    // test_promedio_partidos_jugados_con_datos();
    // test_promedio_partidos_jugados_sin_datos();

    return 0;
}
