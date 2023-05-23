#include <stdlib.h>
#include <string.h>
#include "nodo.h"

// retorna el hijo izquierdo
NodoArbol hijo_izquierdo(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    } else {
        return nodo->hi;
    }
};

// retorna el hijo derecho
NodoArbol hijo_derecho(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    } else {
        return nodo->hd;
    }
};

// Crea el Nodo y lo retorna
NodoArbol crear_nodo_arbol(TipoElemento te) {
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->altura = 0;
    return na;
};

// retorno el tipo elemento de un nodo o NULL si no existe
TipoElemento recuperar_nodo_arbol(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    }

    return nodo->datos;
};
