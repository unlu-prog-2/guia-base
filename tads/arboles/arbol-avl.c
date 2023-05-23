#include "nodo.h"
#include "arbol-avl.h"

struct ArbolAVLRep {
    NodoArbol raiz;
    int cantidad_elementos;
};


NodoArbol avl_rotar_derecha(NodoArbol nodo);

NodoArbol avl_rotar_izquierda(NodoArbol nodo);

int avl_altura_izq(NodoArbol nodo);

int avl_altura_der(NodoArbol nodo);

int avl_max(int a, int b);

enum Balanceo {
    DESBALANCEADO_DERECHA,
    APENAS_DESBALANCEADO_DERECHA,
    BALANCEADO,
    APENAS_DESBALANCEADO_IZQUIERDA,
    DESBALANCEADO_IZQUIERDA
};

ArbolAVL avl_crear() {
}

bool avl_es_vacio(ArbolAVL a) {
}

int avl_cantidad_elementos(ArbolAVL a) {
}

NodoArbol avl_raiz(ArbolAVL a) {
}

enum Balanceo avl_calcular_balanceo(NodoArbol nodo) {
    int diferenciaAltura = avl_altura_izq(nodo) - avl_altura_der(nodo);
    switch (diferenciaAltura) {
        case -2:
            return DESBALANCEADO_DERECHA;
        case -1:
            return APENAS_DESBALANCEADO_DERECHA;
        case 1:
            return APENAS_DESBALANCEADO_IZQUIERDA;
        case 2:
            return DESBALANCEADO_IZQUIERDA;
        default:
            return BALANCEADO;
    }
}

NodoArbol avl_insertar_recursivo(ArbolAVL a, TipoElemento te, NodoArbol pa) {
}

void avl_insertar(ArbolAVL a, TipoElemento te) {
    a->raiz = avl_insertar_recursivo(a, te, avl_raiz(a));
}

NodoArbol avl_buscar_minimo(NodoArbol nodoArbol) {
}

NodoArbol avl_eliminar_recursivo(ArbolAVL arbol, NodoArbol nodoArbol, int claveABorrar) {
}

void avl_eliminar(ArbolAVL a, int claveABorrar) {
    a->raiz = avl_eliminar_recursivo(a, avl_raiz(a), claveABorrar);
}

TipoElemento avl_buscar_recursivo(NodoArbol nodoArbol, int clave) {
}

TipoElemento avl_buscar(ArbolAVL a, int clave) {
    return avl_buscar_recursivo(avl_raiz(a), clave);
}


////////////////////////////////////
///  Funciones para el balanceo  ///
////////////////////////////////////

int avl_altura_izq(NodoArbol nodo) {
    if (nodo->hi == NULL) {
        return -1;
    }
    return nodo->hi->altura;
}

int avl_altura_der(NodoArbol nodo) {
    if (nodo->hd == NULL) {
        return -1;
    }
    return nodo->hd->altura;
}

int avl_max(int a, int b) {
    return a > b ? a : b;
}

/**
 *  * Rotación izquierda
 *   a                                     b
 *  / \                                   / \
 * c   b  -> a.avl_rotar_izquierda() ->  a   e
 *    / \                               / \
 *   d   e                             c   d
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo) {
    NodoArbol otro = nodo->hd;
    nodo->hd = otro->hi;
    otro->hi = nodo;
    nodo->altura = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->altura = avl_max(avl_altura_der(otro), nodo->altura) + 1;

    return otro;
}

/**
 * Rotación derecha
 *     b                                 a
 *    / \                               / \
 *   a   e -> b.avl_rotar_derecha() -> c   b
 *  / \                                   / \
 * c   d                                 d   e
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo) {
    NodoArbol otro = nodo->hi;
    nodo->hi = otro->hd;
    otro->hd = nodo;
    nodo->altura = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->altura = avl_max(avl_altura_izq(otro), nodo->altura) + 1;

    return otro;
}
