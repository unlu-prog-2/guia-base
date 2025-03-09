#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

// retorna el hijo izquierdo
NodoArbol n_hijo_izquierdo(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    } else {
        return nodo->hi;
    }
};

// retorna el hijo derecho
NodoArbol n_hijo_derecho(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    } else {
        return nodo->hd;
    }
};

// Crea el Nodo y lo retorna
NodoArbol n_crear(TipoElemento te) {
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->fe = 0;
    return na;
}

// retorno el tipo elemento de un nodo o NULL si no existe
TipoElemento n_recuperar(NodoArbol nodo) {
    if (nodo == NULL) {
        return NULL;
    }

    return nodo->datos;
}
