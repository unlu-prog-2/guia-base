#ifndef FECHA_H
#define FECHA_H

#include <stdbool.h>

struct FechaRep;
typedef struct FechaRep *Fecha;

enum FechaComparacion {
    ANTERIOR, POSTERIOR, IGUAL
};

Fecha fecha_inicializar(unsigned short dia, unsigned short mes, unsigned int anio);

unsigned short fecha_dia(Fecha f);

unsigned short fecha_mes(Fecha f);

unsigned int fecha_anio(Fecha f);

Fecha fecha_sumar_dias(Fecha f, int dias);

int fecha_distancia_en_dias(Fecha f1, Fecha f2);

enum FechaComparacion fecha_comparar(Fecha f1, Fecha f2);

bool fecha_en_bisiesto(Fecha fecha);

char *fecha_nombre_mes(Fecha fecha);

char *fecha_comparacion_to_string(enum FechaComparacion comparacion);

char *fecha_to_string(Fecha fecha);

#endif // FECHA_H
