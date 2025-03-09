#ifndef ASERCIONES_LISTAS_H
#define ASERCIONES_LISTAS_H

#include <stdbool.h>
#include "tipo_elemento/tipo_elemento.h"
#include "listas.h"

bool listas_eq(Lista real, Lista esperado);

bool listas_eq_fn(Lista real, Lista esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                  char *(*toStringTipoElemento)(TipoElemento te));

#endif // ASERCIONES_LISTAS_H
