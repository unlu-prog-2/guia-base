#ifndef ASSERT_H
#define ASSERT_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <tipo_elemento.h>
#include "listas/listas.h"
#include "pilas/pilas.h"
#include "colas/colas.h"

bool bool_eq(bool real, bool esperado);

bool bool_true(bool real);

bool bool_false(bool real);

bool str_eq(char *real, char *esperado);

bool int_eq(int real, int esperado);

bool int_gt(int real, int esperado);

bool int_gte(int real, int esperado);

bool int_lt(int real, int esperado);

bool int_lte(int real, int esperado);

bool float_eq(float real, float esperado);

bool float_gt(float real, float esperado);

bool float_gte(float real, float esperado);

bool float_lt(float real, float esperado);

bool float_lte(float real, float esperado);

bool double_eq(double real, double esperado);

bool double_gt(double real, double esperado);

bool double_gte(double real, double esperado);

bool double_lt(double real, double esperado);

bool double_lte(double real, double esperado);

// ------
// Arrays
// ------
bool int_array_eq(int *real, int *esperado, int longReal, int longEsperado);

// ------------
// TipoElemento
// ------------
bool te_eq(TipoElemento real, TipoElemento esperado);

bool te_eq_valor(TipoElemento real, TipoElemento esperado,
                 bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro));

// ------------
// Listas
// ------------
bool listas_eq(Lista real, Lista esperado);

bool listas_eq_fn(Lista real, Lista esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                  char *(*toStringTipoElemento)(TipoElemento te));


// ------------
// Pilas
// ------------
bool pilas_eq(Pila real, Pila esperado);

bool pilas_eq_fn(Pila real, Pila esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te));

// ------------
// Colas
// ------------
bool colas_eq(Cola real, Cola esperado);

bool colas_eq_fn(Cola real, Cola esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te));

#endif // ASSERT_H
