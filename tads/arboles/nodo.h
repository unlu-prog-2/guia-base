#ifndef NODO_H
#define NODO_H

#include "tipo_elemento/tipo_elemento.h"

struct NodoArbolRep {
    TipoElemento datos;
    struct NodoArbolRep *hi;
    struct NodoArbolRep *hd;
    int fe;   //Factor de Equilibro de Cada nodo para el autobalanceo
};
typedef struct NodoArbolRep *NodoArbol;

// retorna el hijo izquierdo
NodoArbol n_hijo_izquierdo(NodoArbol nodo);

// retorna el hijo derecho
NodoArbol n_hijo_derecho(NodoArbol nodo);

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// Crea un Nodo y lo retorna
TipoElemento n_recuperar(NodoArbol nodo);

#endif // NODO_H
