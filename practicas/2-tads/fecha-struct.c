#include <stdlib.h>
#include <stdio.h>
#include "fecha.h"

struct FechaRep {
    unsigned short dia, mes;
    unsigned int anio;
};

const unsigned short dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Fecha fecha_inicializar(unsigned short dia, unsigned short mes, unsigned int anio) {
}

unsigned short fecha_dia(Fecha f) {
}

unsigned short fecha_mes(Fecha f) {
}

unsigned int fecha_anio(Fecha f) {
}
