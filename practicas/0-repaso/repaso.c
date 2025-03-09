#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "repaso.h"

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp) {
}

bool digitoEnNumero(long n, short d) {
}

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p) {
}

// Función para ordenar jugadores por cantidad de partidos jugados
struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[CANT_JUGADORES]) {
}

// Función para ordenar jugadores por edad
struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[CANT_JUGADORES]) {
}

// Función para calcular el promedio de partidos jugados dada una edad
float promedioDePartidosJugados(struct Jugador equipo[CANT_JUGADORES], int edad) {
}

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el piso con más habitantes
int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el número de departamentos vacíos
int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

// Función que devuelve el promedio de habitantes por departamento
float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]) {
}

void cantidadDeViviendasVaciasPorPiso(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS], int vaciasPorPiso[CANT_PISOS]) {
}

void viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS],
                     Vivienda viviendasVacias[CANT_PISOS * CANT_DEPARTAMENTOS]) {
}

void procesarArchivo(const char *nombreArchivo) {
}
