#include <assert.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "arboles/arbol-avl.h"
#include "arboles/util_arboles.h"

void test_operaciones_varias() {
    ArbolAVL arbol = avl_crear();
    assert(bool_true(avl_es_vacio(arbol)));
    assert(int_eq(avl_cantidad_elementos(arbol), 0));

    Iterador it = iterador_in_orden(avl_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_pre_orden(avl_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_post_orden(avl_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    it = iterador_bfs(avl_raiz(arbol));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    avl_insertar(arbol, te_crear(1));
    avl_insertar(arbol, te_crear(2));
    avl_insertar(arbol, te_crear(3));
    avl_insertar(arbol, te_crear(7));
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 4));
    assert(bool_false(avl_es_vacio(arbol)));

    mostrar_arbol_binario(avl_raiz(arbol), IN_ORDEN);
    it = iterador_in_orden(avl_raiz(arbol));
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

    mostrar_arbol_binario(avl_raiz(arbol), PRE_ORDEN);
    it = iterador_pre_orden(avl_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(avl_raiz(arbol), POST_ORDEN);
    it = iterador_post_orden(avl_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    mostrar_arbol_binario(avl_raiz(arbol), BFS);
    it = iterador_bfs(avl_raiz(arbol));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 2));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 1));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 3));
    assert(bool_true(hay_siguiente(it)));
    assert(int_eq(siguiente(it)->clave, 7));
    assert(bool_false(hay_siguiente(it)));
    free(it);

    // Búsquedas
    assert(int_eq(avl_buscar(arbol, 2)->clave, 2));
    assert(int_eq(avl_buscar(arbol, 3)->clave, 3));
    assert(int_eq(avl_buscar(arbol, 1)->clave, 1));
    assert(int_eq(avl_buscar(arbol, 7)->clave, 7));

    // Eliminación de la raíz
    avl_eliminar(arbol, 2);
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 3));
    assert(bool_false(avl_es_vacio(arbol)));
    assert(int_eq(avl_raiz(arbol)->datos->clave, 3));
    assert(int_eq(avl_raiz(arbol)->hi->datos->clave, 1));
    assert(int_eq(avl_raiz(arbol)->hd->datos->clave, 7));
    assert(ptr_null(avl_buscar(arbol, 2)));
    assert(int_eq(avl_buscar(arbol, 3)->clave, 3));
    assert(int_eq(avl_buscar(arbol, 1)->clave, 1));
    assert(int_eq(avl_buscar(arbol, 7)->clave, 7));

    // Eliminación de una clave que no existe, queda igual
    avl_eliminar(arbol, 2);
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 3));
    assert(bool_false(avl_es_vacio(arbol)));
    assert(int_eq(avl_raiz(arbol)->datos->clave, 3));
    assert(int_eq(avl_raiz(arbol)->hi->datos->clave, 1));
    assert(int_eq(avl_raiz(arbol)->hd->datos->clave, 7));
    assert(ptr_null(avl_buscar(arbol, 2)));
    assert(int_eq(avl_buscar(arbol, 3)->clave, 3));
    assert(int_eq(avl_buscar(arbol, 1)->clave, 1));
    assert(int_eq(avl_buscar(arbol, 7)->clave, 7));

    // Eliminación de una hoja
    avl_eliminar(arbol, 7);
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 2));
    assert(bool_false(avl_es_vacio(arbol)));
    assert(int_eq(avl_raiz(arbol)->datos->clave, 3));
    assert(int_eq(avl_raiz(arbol)->hi->datos->clave, 1));
    assert(ptr_null(avl_buscar(arbol, 2)));
    assert(int_eq(avl_buscar(arbol, 3)->clave, 3));
    assert(int_eq(avl_buscar(arbol, 1)->clave, 1));
    assert(ptr_null(avl_buscar(arbol, 7)));

    // Eliminación de la raíz
    avl_eliminar(arbol, 3);
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 1));
    assert(bool_false(avl_es_vacio(arbol)));
    assert(int_eq(avl_raiz(arbol)->datos->clave, 1));
    assert(ptr_null(avl_buscar(arbol, 2)));
    assert(ptr_null(avl_buscar(arbol, 3)));
    assert(int_eq(avl_buscar(arbol, 1)->clave, 1));
    assert(ptr_null(avl_buscar(arbol, 7)));

    // Eliminación de la raíz
    avl_eliminar(arbol, 1);
    mostrar_arbol_binario_ascii(avl_raiz(arbol));
    assert(int_eq(avl_cantidad_elementos(arbol), 0));
    assert(bool_true(avl_es_vacio(arbol)));
    assert(ptr_null(avl_raiz(arbol)));
    assert(ptr_null(avl_buscar(arbol, 2)));
    assert(ptr_null(avl_buscar(arbol, 3)));
    assert(ptr_null(avl_buscar(arbol, 1)));
    assert(ptr_null(avl_buscar(arbol, 7)));
}

int main() {
    imprimir_titulo("Tests de Árboles AVL");

//    test_operaciones_varias();

    return 0;
}
