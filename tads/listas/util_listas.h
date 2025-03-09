#ifndef UTIL_LISTAS_H
#define UTIL_LISTAS_H

#include "listas.h"
#include "tipo_elemento/tipo_elemento.h"

Lista crear_lista_desde_array(const int *vector, int tamano);

void destruir_lista(Lista l);

char *lista_como_string(Lista lista, char *(*toStringTipoElemento)(TipoElemento te));

#endif // UTIL_LISTAS_H
