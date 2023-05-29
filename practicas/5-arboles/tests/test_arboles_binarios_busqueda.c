#include <assert.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "arboles/arbol-binario-busqueda.h"
#include "arboles/util_arboles.h"

void test_operaciones_varias() {
    ArbolBinarioBusqueda arbol = abb_crear();
    assert(bool_true(abb_es_vacio(arbol)));
    assert(int_eq(abb_cantidad_elementos(arbol), 0));

    Iterador it = iterador_in_orden(abb_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_pre_orden(abb_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_post_orden(abb_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_bfs(abb_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    abb_insertar(arbol, te_crear(1));
    abb_insertar(arbol, te_crear(2));
    abb_insertar(arbol, te_crear(3));
    abb_insertar(arbol, te_crear(7));
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 4));
    assert(bool_false(abb_es_vacio(arbol)));

    mostrar_arbol_binario(abb_raiz(arbol), IN_ORDEN);
    it = iterador_in_orden(abb_raiz(arbol));
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

    mostrar_arbol_binario(abb_raiz(arbol), PRE_ORDEN);
    it = iterador_pre_orden(abb_raiz(arbol));
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

    mostrar_arbol_binario(abb_raiz(arbol), POST_ORDEN);
    it = iterador_post_orden(abb_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(abb_raiz(arbol), BFS);
    it = iterador_bfs(abb_raiz(arbol));
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

    // Búsquedas
    assert(int_eq(abb_buscar(arbol, 2)->clave, 2));
    assert(int_eq(abb_buscar(arbol, 3)->clave, 3));
    assert(int_eq(abb_buscar(arbol, 1)->clave, 1));
    assert(int_eq(abb_buscar(arbol, 7)->clave, 7));

    // Eliminación de un nodo intermedio
    abb_eliminar(arbol, 2);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 3));
    assert(bool_false(abb_es_vacio(arbol)));
    assert(int_eq(abb_raiz(arbol)->datos->clave, 1));
    assert(int_eq(abb_raiz(arbol)->hd->datos->clave, 3));
    assert(int_eq(abb_raiz(arbol)->hd->hd->datos->clave, 7));
    assert(ptr_null(abb_buscar(arbol, 2)));
    assert(int_eq(abb_buscar(arbol, 3)->clave, 3));
    assert(int_eq(abb_buscar(arbol, 1)->clave, 1));
    assert(int_eq(abb_buscar(arbol, 7)->clave, 7));

    // Eliminación de una clave que no existe, queda igual
    abb_eliminar(arbol, 2);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 3));
    assert(bool_false(abb_es_vacio(arbol)));
    assert(int_eq(abb_raiz(arbol)->datos->clave, 1));
    assert(int_eq(abb_raiz(arbol)->hd->datos->clave, 3));
    assert(int_eq(abb_raiz(arbol)->hd->hd->datos->clave, 7));
    assert(ptr_null(abb_buscar(arbol, 2)));
    assert(int_eq(abb_buscar(arbol, 3)->clave, 3));
    assert(int_eq(abb_buscar(arbol, 1)->clave, 1));
    assert(int_eq(abb_buscar(arbol, 7)->clave, 7));

    // Eliminación de una hoja
    abb_eliminar(arbol, 7);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 2));
    assert(bool_false(abb_es_vacio(arbol)));
    assert(int_eq(abb_raiz(arbol)->datos->clave, 1));
    assert(int_eq(abb_raiz(arbol)->hd->datos->clave, 3));
    assert(ptr_null(abb_buscar(arbol, 2)));
    assert(int_eq(abb_buscar(arbol, 3)->clave, 3));
    assert(int_eq(abb_buscar(arbol, 1)->clave, 1));
    assert(ptr_null(abb_buscar(arbol, 7)));

    // Eliminación de la raíz
    abb_eliminar(arbol, 1);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 1));
    assert(bool_false(abb_es_vacio(arbol)));
    assert(int_eq(abb_raiz(arbol)->datos->clave, 3));
    assert(ptr_null(abb_buscar(arbol, 2)));
    assert(int_eq(abb_buscar(arbol, 3)->clave, 3));
    assert(ptr_null(abb_buscar(arbol, 1)));
    assert(ptr_null(abb_buscar(arbol, 7)));

    // Eliminación de la raíz
    abb_eliminar(arbol, 3);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_cantidad_elementos(arbol), 0));
    assert(bool_true(abb_es_vacio(arbol)));
    assert(ptr_null(abb_raiz(arbol)));
    assert(ptr_null(abb_buscar(arbol, 2)));
    assert(ptr_null(abb_buscar(arbol, 3)));
    assert(ptr_null(abb_buscar(arbol, 1)));
    assert(ptr_null(abb_buscar(arbol, 7)));
}

void test_operaciones_varias2() {
    ArbolBinarioBusqueda arbol = abb_crear();
    abb_insertar(arbol, te_crear(2));
    abb_insertar(arbol, te_crear(1));
    abb_insertar(arbol, te_crear(5));
    abb_insertar(arbol, te_crear(4));
    abb_insertar(arbol, te_crear(7));
    mostrar_arbol_binario_ascii(abb_raiz(arbol));

    abb_eliminar(arbol, 5);
    mostrar_arbol_binario_ascii(abb_raiz(arbol));
    assert(int_eq(abb_raiz(arbol)->datos->clave, 2));
    assert(int_eq(abb_raiz(arbol)->hi->datos->clave, 1));
    assert(int_eq(abb_raiz(arbol)->hd->datos->clave, 7));
    assert(int_eq(abb_raiz(arbol)->hd->hi->datos->clave, 4));
}

int main() {
    imprimir_titulo("Tests de Árboles Binarios de Búsqueda");

//    test_operaciones_varias();
//    test_operaciones_varias2();

    return 0;
}
