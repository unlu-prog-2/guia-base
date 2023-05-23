#include "arbol-binario-busqueda.h"
#include "nodo.h"

struct ArbolBinarioBusquedaRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinarioBusqueda abb_crear() {
}

bool abb_es_vacio(ArbolBinarioBusqueda a) {
}

int abb_cantidad_elementos(ArbolBinarioBusqueda a) {
}

NodoArbol abb_raiz(ArbolBinarioBusqueda a) {
}


NodoArbol abb_insertar_recursivo(ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te) {
}

void abb_insertar(ArbolBinarioBusqueda a, TipoElemento te) {
    abb_insertar_recursivo(a, abb_raiz(a), te);
}

NodoArbol abb_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}

NodoArbol abb_eliminar_recursivo(ArbolBinarioBusqueda arbol, NodoArbol root, int claveABorrar) {
}

void abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar) {
    a->raiz = abb_eliminar_recursivo(a, abb_raiz(a), claveABorrar);
}

TipoElemento abb_buscar_recursivo(NodoArbol nodoArbol, int clave) {
}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave) {
    return abb_buscar_recursivo(abb_raiz(a), clave);
}
