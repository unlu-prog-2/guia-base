#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fecha.h"

struct FechaRep {
    double juliano;
};

const unsigned short dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Fecha fecha_inicializar(const unsigned short dia, const unsigned short mes, const unsigned int anio) {
}

void fecha_desde_juliano(double juliano, unsigned short *dia, unsigned short *mes, unsigned int *anio);

unsigned short fecha_dia(Fecha f) {
}

unsigned short fecha_mes(Fecha f) {
}

unsigned int fecha_anio(Fecha f) {
}

Fecha fecha_sumar_dias(Fecha f, int dias) {
}

int fecha_distancia_en_dias(Fecha f1, Fecha f2) {
}

enum FechaComparacion fecha_comparar(Fecha f1, Fecha f2) {
}

bool fecha_en_bisiesto(Fecha fecha) {
}

char *meses[] = {
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
};

char *fecha_nombre_mes(Fecha fecha) {
}

char *fecha_comparacion_to_string(const enum FechaComparacion comparacion) {
}

char *fecha_to_string(Fecha fecha) {
    const unsigned short dia = fecha_dia(fecha);
    const unsigned short mes = fecha_mes(fecha);
    const unsigned int anio = fecha_anio(fecha);
    char *str = (char *) malloc(11 * sizeof(char));
    sprintf(str, "%02d/%02d/%04d", dia, mes, anio);
    return str;
}

void fecha_desde_juliano(double juliano, unsigned short *dia, unsigned short *mes, unsigned int *anio) {
}
