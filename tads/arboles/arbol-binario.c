#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arbol-binario.h"
#include "nodo.h"

static const int TAMANIO_MAXIMO = 1000;

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinario a_crear() {
}

bool a_es_vacio(ArbolBinario a) {
}

bool a_es_lleno(ArbolBinario a) {
}

int a_cantidad_elementos(ArbolBinario a) {
}

bool a_es_rama_nula(NodoArbol pa) {
}

NodoArbol a_raiz(ArbolBinario a) {
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te) {
    assert(a->raiz == NULL);

    // ...
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    assert(pa != NULL);
    // TODO Acá tenemos que chequear que la posición árbol efectivamente esté en el árbol

    // Chequeamos que la posición árbol no tenga ya la rama que están solicitando insertar
    assert(pa->hi == NULL);

    // TODO Chequear que la posición árbol no tenga ya la rama que están solicitando insertar
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    assert(pa != NULL);
    // TODO Acá deberíamos chequear que la posición árbol efectivamente esté en el árbol

    // Chequeamos que la posición árbol no tenga ya la rama que están solicitando l_insertar
    assert(pa->hd == NULL);
}


