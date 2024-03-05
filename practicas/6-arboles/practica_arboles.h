#ifndef PRACTICA_ARBOLES_H
#define PRACTICA_ARBOLES_H

#include "arboles/arbol-binario.h"
#include "arboles/arbol-binario-busqueda.h"
#include "arboles/arbol-avl.h"
#include "listas/listas.h"


// Árboles Binarios: Analizando los árboles binarios

Lista a_nodos_terminales(ArbolBinario a);

Lista a_nodos_interiores(ArbolBinario a);

bool a_hojas_mismo_nivel(ArbolBinario a);

Lista a_posiciones_ocurrencias(ArbolBinario a, int clave);

// Árboles Binarios: Conociendo los nodos

NodoArbol a_nodo_padre(ArbolBinario a, NodoArbol nodo);

Lista a_nodo_hijos(ArbolBinario a, NodoArbol nodo);

Lista a_nodo_hermanos(ArbolBinario a, NodoArbol nodo);

int a_nodo_nivel(ArbolBinario a, NodoArbol nodo);

int a_nodo_altura_rama(ArbolBinario a, NodoArbol nodo);

Lista a_nodo_mismo_nivel(ArbolBinario a, int nivel);

bool a_equivalentes(ArbolBinario a1, ArbolBinario a2);

// Árboles N-arios: Analizando los árboles

int an_altura(ArbolBinario a);

int an_nivel(ArbolBinario a, NodoArbol nodo);

Lista an_nodos_interiores(ArbolBinario a);

bool an_hojas_mismo_nivel(ArbolBinario a);

Lista an_recorrido_anchura(ArbolBinario a);

int an_cantidad_nodos(ArbolBinario a);

bool an_similares(ArbolBinario a1, ArbolBinario a2);

NodoArbol an_nodo_padre(ArbolBinario a, NodoArbol nodo);

Lista an_nodo_hermanos(ArbolBinario a, NodoArbol nodo);

ArbolAVL arbolAvlDesdeArbolBinario(ArbolBinario ab);

#endif // PRACTICA_ARBOLES_H
