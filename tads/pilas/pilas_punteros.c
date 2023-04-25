#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "pilas.h"

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct PilaRep {
    struct Nodo *tope;
};

Pila p_crear() {
}

void p_apilar(Pila pila, TipoElemento elemento) {
}

TipoElemento p_desapilar(Pila pila) {
}

TipoElemento p_tope(Pila pila) {
}

bool p_es_vacia(Pila pila) {
}

//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la pila
//-----------------------------------------------------------
int longitud(Pila pila) {
    int i = 0;
    struct Nodo *nodo = pila->tope;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

void p_mostrar(Pila pila) {
}

char *p_to_string(Pila pila) {
    int cantidad = longitud(pila);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = pila->tope;
    int i = 0;
    while (temp != NULL) {
        char num_str[10];
        sprintf(num_str, "%d", temp->datos->clave);
        strcat(resultado, num_str);
        if (i < (cantidad - 1)) {
            strcat(resultado, ", ");
        }
        temp = temp->siguiente;
        i++;
    }
    strcat(resultado, "]");

    return resultado;
}