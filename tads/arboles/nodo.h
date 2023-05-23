#ifndef NODO_H
#define NODO_H
#include "../tipo_elemento.h"

struct NodoArbolRep {
    TipoElemento datos;
    struct NodoArbolRep *hi;
    struct NodoArbolRep *hd;
    int altura;
};
typedef struct NodoArbolRep *NodoArbol;

// retorna el hijo izquierdo
NodoArbol hijo_izquierdo(NodoArbol nodo);

// retorna el hijo derecho
NodoArbol hijo_derecho(NodoArbol nodo);

// Crea un Nodo y lo retorna
NodoArbol crear_nodo_arbol(TipoElemento te);

// Retorna el dato guardado en un nodo
TipoElemento recuperar_nodo_arbol(NodoArbol nodo);

#endif // NODO_H
