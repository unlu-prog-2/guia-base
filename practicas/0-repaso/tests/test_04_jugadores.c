#include <stdio.h>
#include <assert.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 4");
    struct Jugador equipo[CANT_JUGADORES] = {
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

    return 0;
}
