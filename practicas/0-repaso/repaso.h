#ifndef REPASO_H
#define REPASO_H

#include <stdbool.h>

enum Referencia {
    INTERNO = -1,
    EN_CIRCUNFERENCIA,
    EXTERNO
};

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp);

bool digitoEnNumero(long n, short d);


struct Punto {
    int x, y;
};

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p);

#define TAMANO_STRING 50
#define CANT_JUGADORES 11

struct Jugador {
    char nombre[TAMANO_STRING];
    int edad, partidosJugados;
};

struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[CANT_JUGADORES]);

struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[CANT_JUGADORES]);

float promedioDePartidosJugados(struct Jugador equipo[CANT_JUGADORES], int edad);

#define CANT_PISOS 8
#define CANT_DEPARTAMENTOS 5

typedef struct ViviendaRep {
    short piso;
    char depto;
} Vivienda;

int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

void cantidadDeViviendasVaciasPorPiso(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS], int vaciasPorPiso[CANT_PISOS]);

void viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS],
                     Vivienda viviendasVacias[CANT_PISOS * CANT_DEPARTAMENTOS]);


#define CANT_MAX_ANIOS 100
#define CANT_MAX_CLIENTES 10000
#define ANIO_INICIO 2013

struct Cliente {
    int id;
    int totalesPorAnio[CANT_MAX_ANIOS];
};

void procesarArchivo(const char *nombreArchivo);

#endif // REPASO_H
