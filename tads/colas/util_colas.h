#ifndef UTIL_COLAS_H
#define UTIL_COLAS_H

#include "../tipo_elemento.h"
#include "colas.h"

Cola crear_cola_desde_array(int *vector, int tamano);

void destruir_cola(Cola cola);

char *cola_como_string(Cola cola, char *(*toStringTipoElemento)(TipoElemento te));

#endif // UTIL_COLAS_H
