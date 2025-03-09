#ifndef UTIL_ARBOLES_H
#define UTIL_ARBOLES_H

#include "nodo.h"
#include "listas/listas.h"

enum Recorrido {
    PRE_ORDEN,
    IN_ORDEN,
    POST_ORDEN,
    BFS,
};

void mostrar_arbol_binario_ascii(NodoArbol);

void mostrar_arbol_binario(NodoArbol, enum Recorrido);

Iterador iterador_pre_orden(NodoArbol);

Iterador iterador_in_orden(NodoArbol);

Iterador iterador_post_orden(NodoArbol);

Iterador iterador_bfs(NodoArbol nodo_arbol);

#endif // UTIL_ARBOLES_H
