#ifndef UTIL_PILAS_H
#define UTIL_PILAS_H

#include "pilas.h"
#include "tipo_elemento/tipo_elemento.h"

Pila crear_pila_desde_array(const int *vector, int tamano);

void destruir_pila(Pila p);

char *pila_como_string(Pila pila, char *(*toStringTipoElemento)(TipoElemento te));

#endif // UTIL_PILAS_H
