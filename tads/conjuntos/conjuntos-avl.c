#include <stdlib.h>
#include <stdio.h>
#include "conjuntos.h"
#include "arboles/arbol-avl.h"
#include "listas/listas.h"
#include "arboles/util_arboles.h"

struct ConjuntoRep {
    ArbolAVL arbolAvl;
};

Conjunto cto_crear() {
}

bool cto_es_vacio(Conjunto conjunto) {
}

bool cto_es_lleno(Conjunto conjunto) {
}

int cto_cantidad_elementos(Conjunto conjunto) {
}

bool cto_agregar(Conjunto conjunto, TipoElemento elemento) {
}

bool cto_borrar(Conjunto conjunto, int clave) {
}

bool cto_pertenece(Conjunto conjunto, int clave) {
}

Conjunto cto_union(Conjunto conjunto_a, Conjunto conjunto_b) {
}

Conjunto cto_interseccion(Conjunto conjunto_a, Conjunto conjunto_b) {
}

Conjunto cto_diferencia(Conjunto conjunto_a, Conjunto conjunto_b) {
}

TipoElemento cto_recuperar(Conjunto conjunto, int posicion_ordinal) {
}

void cto_mostrar(Conjunto conjunto) {
}
