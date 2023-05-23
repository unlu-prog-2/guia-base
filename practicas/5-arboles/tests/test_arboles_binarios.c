#include <assert.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "arboles/arbol-binario.h"
#include "arboles/util_arboles.h"

void test_operaciones_varias() {
    ArbolBinario arbol = a_crear();
    assert(bool_true(a_es_vacio(arbol)));

    Iterador it = iterador_in_orden(a_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_pre_orden(a_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_post_orden(a_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_bfs(a_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    NodoArbol raiz = a_establecer_raiz(arbol, te_crear(1));
    NodoArbol hi = a_conectar_hi(arbol, raiz, te_crear(2));
    a_conectar_hd(arbol, raiz, te_crear(3));
    a_conectar_hd(arbol, hi, te_crear(7));
    mostrar_arbol_binario_ascii(a_raiz(arbol));

    assert(bool_false(a_es_vacio(arbol)));

    mostrar_arbol_binario(a_raiz(arbol), IN_ORDEN);
    it = iterador_in_orden(a_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(a_raiz(arbol), PRE_ORDEN);
    it = iterador_pre_orden(a_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(a_raiz(arbol), POST_ORDEN);
    it = iterador_post_orden(a_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(a_raiz(arbol), BFS);
    it = iterador_bfs(a_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_false(hay_siguiente(it)));
    free(it);
}

int main() {
    imprimir_titulo("Tests de Árboles Binarios");

//    test_operaciones_varias();

    return 0;
}
