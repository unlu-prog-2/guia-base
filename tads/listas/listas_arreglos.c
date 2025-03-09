#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct ListaRep {
    TipoElemento *valores;
    int cantidad;
};

struct IteradorRep {
    Lista lista;
    int posicionActual;
};


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del TAD
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

Lista l_crear() {
}

bool l_es_vacia(Lista lista) {
}

bool l_es_llena(Lista lista) {
}

int l_longitud(Lista lista) {
}

bool l_agregar(Lista lista, TipoElemento elemento) {
}

bool l_borrar(Lista lista, int clave) {
}

TipoElemento l_buscar(Lista lista, int clave) {
}

bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
}

bool l_eliminar(Lista lista, int pos) {
}

TipoElemento l_recuperar(Lista lista, int pos) {
}

void l_mostrar(Lista lista) {
}

char *l_to_string(Lista lista) {
    char *resultado = (char *) malloc(sizeof(char) * (lista->cantidad * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < lista->cantidad; i++) {
        char num_str[10];
        sprintf(num_str, "%d", lista->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (lista->cantidad - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
// Rutinas del Iterador
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
Iterador iterador(Lista lista) {
}

bool hay_siguiente(Iterador iterador) {
}

TipoElemento siguiente(Iterador iterador) {
}
