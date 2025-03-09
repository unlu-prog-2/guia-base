#ifndef ASERCIONES_COLAS_H
#define ASERCIONES_COLAS_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "tipo_elemento/tipo_elemento.h"
#include "colas.h"

bool colas_eq(Cola real, Cola esperado);

bool colas_eq_fn(Cola real, Cola esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te));


#endif // ASERCIONES_COLAS_H
