#ifndef UTIL_LISTAS_H
#define UTIL_LISTAS_H

#include "listas/listas.h"
#include "tipo_elemento.h"

Lista crear_lista_desde_array(int *vector, int tamano);

void destruir_lista(Lista l);

char *lista_como_string(Lista lista, char *(*toStringTipoElemento)(TipoElemento te));

#endif // UTIL_LISTAS_H
