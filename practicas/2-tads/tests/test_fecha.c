#include <assert.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../fecha.h"

void probar_inicializar(int dia, int mes, int anio, bool esperado) {
    Fecha f1 = fecha_inicializar(dia, mes, anio);
    if (esperado) {
        assert(ptr_not_null(f1));
        assert(int_eq(fecha_dia(f1), dia));
        assert(int_eq(fecha_mes(f1), mes));
        assert(int_eq(fecha_anio(f1), anio));
    } else {
        assert(ptr_null(f1));
    }
    free(f1);
}

void probar_sumar_dias(unsigned short dia, unsigned short mes, unsigned int anio, int dias, unsigned short dia_esperado,
                       unsigned short mes_esperado, unsigned int anio_esperado) {
}

void probar_distancia_en_dias(unsigned short f1_dia, unsigned short f1_mes, unsigned int f1_anio, unsigned short f2_dia,
                              unsigned short f2_mes, unsigned int f2_anio, int esperado) {
}

void probar_comparar(unsigned short f1_dia, unsigned short f1_mes, unsigned int f1_anio, unsigned short f2_dia,
                     unsigned short f2_mes, unsigned int f2_anio, enum FechaComparacion esperado) {
}

void probar_anio_bisiesto(unsigned short f1_dia, unsigned short f1_mes, unsigned int f1_anio, bool esperado) {
}

void probar_to_string(unsigned short f1_dia, unsigned short f1_mes, unsigned int f1_anio, char *esperado) {
}

void probar_nombre_mes(unsigned short f1_dia, unsigned short f1_mes, unsigned int f1_anio, char *esperado) {
}

int main() {
    imprimir_titulo("Tests para Fecha");

    // probar_inicializar(20, 1, 2023, true);
    // probar_inicializar(30, 1, 2023, true);
    // probar_inicializar(31, 2, 2023, false);
    // probar_inicializar(29, 2, 2024, true);
    //
    // probar_sumar_dias(20, 1, 2023, 2, 22, 1, 2023);
    // probar_sumar_dias(29, 1, 2023, 4, 2, 2, 2023);
    // probar_sumar_dias(29, 2, 2024, 4, 4, 3, 2024);
    // probar_sumar_dias(29, 2, 2024, -365, 1, 3, 2023);
    // probar_sumar_dias(15, 11, 10, 365, 15, 11, 11);
    // probar_sumar_dias(15, 9, 10, 39810, 13, 9, 119);
    //
    // probar_distancia_en_dias(20, 1, 2023, 22, 1, 2023, 2);
    // probar_distancia_en_dias(1, 3, 2023, 22, 2, 2023, -7);
    // probar_distancia_en_dias(1, 1, 0, 1, 1, 10, 3653);
    // probar_distancia_en_dias(1, 1, 10, 1, 1, 0, -3653);
    // probar_distancia_en_dias(31, 12, 0, 1, 1, 1, 1);
    // probar_distancia_en_dias(15, 9, 10, 13, 9, 119, 39810);
    //
    // probar_comparar(20, 1, 2023, 22, 1, 2023, ANTERIOR);
    // probar_comparar(1, 3, 2023, 22, 2, 2023, POSTERIOR);
    // probar_comparar(1, 1, 2023, 1, 1, 2023, IGUAL);
    //
    // probar_anio_bisiesto(29, 2, 2020, true);
    // probar_anio_bisiesto(28, 2, 2021, false);
    // probar_anio_bisiesto(28, 2, 2022, false);
    // probar_anio_bisiesto(28, 2, 2023, false);
    // probar_anio_bisiesto(29, 2, 2024, true);
    //
    // probar_to_string(20, 1, 2023, "20/01/2023");
    // probar_to_string(1, 3, 2023, "01/03/2023");
    // probar_to_string(1, 1, 10, "01/01/0010");
    // probar_to_string(1, 1, 0, "01/01/0000");
    // probar_to_string(31, 12, 0, "31/12/0000");
    // probar_to_string(15, 9, 99, "15/09/0099");
    //
    // probar_nombre_mes(15, 1, 2024, "Enero");
    // probar_nombre_mes(15, 2, 2024, "Febrero");
    // probar_nombre_mes(15, 3, 2024, "Marzo");
    // probar_nombre_mes(15, 4, 2024, "Abril");
    // probar_nombre_mes(15, 5, 2024, "Mayo");
    // probar_nombre_mes(15, 6, 2024, "Junio");
    // probar_nombre_mes(15, 7, 2024, "Julio");
    // probar_nombre_mes(15, 8, 2024, "Agosto");
    // probar_nombre_mes(15, 9, 2024, "Septiembre");
    // probar_nombre_mes(15, 10, 2024, "Octubre");
    // probar_nombre_mes(15, 11, 2024, "Noviembre");
    // probar_nombre_mes(15, 12, 2024, "Diciembre");

    return 0;
}
