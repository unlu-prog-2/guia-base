#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "aserciones.h"
#include "../repaso.h"
#include "cadenas.h"


int main() {
    imprimir_titulo("Tests de Ejercicio 5");

    int edificio[CANT_PISOS][CANT_DEPARTAMENTOS] = {
            {3, 5, 2, 1, 0},
            {2, 4, 3, 0, 4},
            {1, 0, 1, 2, 1},
            {0, 1, 0, 0, 0},
            {1, 3, 2, 1, 1},
            {2, 2, 0, 1, 3},
            {1, 0, 0, 2, 1},
            {0, 0, 1, 1, 1}
    };

    return 0;
}
