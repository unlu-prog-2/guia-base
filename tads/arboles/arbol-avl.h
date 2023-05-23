#ifndef ARBOL_AVL_H_INCLUDED
#define ARBOL_AVL_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

struct ArbolAVLRep;
typedef struct ArbolAVLRep *ArbolAVL;

ArbolAVL avl_crear();

bool avl_es_vacio(ArbolAVL a);

NodoArbol avl_raiz(ArbolAVL a);

int avl_cantidad_elementos(ArbolAVL a);

void avl_insertar(ArbolAVL a, TipoElemento te);

void avl_eliminar(ArbolAVL a, int claveABorrar);

TipoElemento avl_buscar(ArbolAVL a, int clave);

#endif // ARBOL_AVL_H_INCLUDED
