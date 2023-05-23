#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "nodo.h"

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinario a_crear() {
}

bool a_es_vacio(ArbolBinario a) {
}

int a_cantidad_elementos(ArbolBinario a) {
}

bool a_es_rama_nula(NodoArbol pa) {
}

NodoArbol a_raiz(ArbolBinario a) {
}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te) {
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // TODO Acá tenemos que chequear que la posición árbol efectivamente esté en el árbol

    // TODO Chequeamos que la posición árbol no tenga ya la rama que están solicitando insertar
    if (pa->hi != NULL) {
        // TODO Deberíamos devolver error
    }
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // TODO Acá tenemos que chequear que la posición árbol efectivamente esté en el árbol

    // TODO Chequeamos que la posición árbol no tenga ya la rama que están solicitando insertar
    if (pa->hd != NULL) {
        // TODO Deberíamos devolver error
    }
}


