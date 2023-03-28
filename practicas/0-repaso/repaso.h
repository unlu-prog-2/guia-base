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
    int piso;
    char depto;
} Vivienda;


int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);

// Viviendas viviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]);


#endif // REPASO_H
