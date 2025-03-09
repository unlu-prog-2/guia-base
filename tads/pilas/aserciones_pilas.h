#ifndef ASERCIONES_PILAS_H
#define ASERCIONES_PILAS_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento/tipo_elemento.h"
#include "pilas.h"

// ------------
// Pilas
// ------------
bool pilas_eq(Pila real, Pila esperado);

bool pilas_eq_fn(Pila real, Pila esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te));


#endif // ASERCIONES_PILAS_H
