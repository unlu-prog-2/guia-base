#include <stdio.h>
#include <stdlib.h>
#include "arbol-binario-busqueda.h"
#include "nodo.h"

static const int TAMANIO_MAXIMO = 1000;

struct ArbolBinarioBusquedaRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinarioBusqueda abb_crear() {
}

bool abb_es_vacio(ArbolBinarioBusqueda a) {
}

bool abb_es_lleno(ArbolBinarioBusqueda a) {
}

int abb_cantidad_elementos(ArbolBinarioBusqueda a) {
}

bool abb_es_rama_nula(NodoArbol pa) {
}

NodoArbol abb_raiz(ArbolBinarioBusqueda a) {
}

NodoArbol abb_insertar_recursivo(ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te, bool *inserto) {
}

bool abb_insertar(ArbolBinarioBusqueda a, TipoElemento te) {
    bool inserto = false;
    abb_insertar_recursivo(a, abb_raiz(a), te, &inserto);
    return inserto;
}

// Función interna
NodoArbol abb_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}

NodoArbol abb_eliminar_recursivo(ArbolBinarioBusqueda arbol, NodoArbol nodoArbol, int claveABorrar, bool *borre) {
}

bool abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar) {
    bool borre = false;
    a->raiz = abb_eliminar_recursivo(a, abb_raiz(a), claveABorrar, &borre);
    return borre;
}

TipoElemento abb_buscar_recursivo(NodoArbol nodoArbol, int clave) {
}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave) {
    return abb_buscar_recursivo(abb_raiz(a), clave);
}
