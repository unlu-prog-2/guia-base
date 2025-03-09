#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep {
    struct Nodo *frente;
    struct Nodo *final;
};

int c_longitud(Cola cola);

Cola c_crear(void) {
}

bool c_encolar(Cola cola, TipoElemento elemento) {
}

TipoElemento c_desencolar(Cola cola) {
}

bool c_es_vacia(Cola cola) {
}

bool c_es_llena(Cola cola) {
}

TipoElemento c_recuperar(Cola cola) {
}

void c_mostrar(Cola cola) {
}

//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la pila
//-----------------------------------------------------------
int c_longitud(Cola cola) {
    int i = 0;
    struct Nodo *nodo = cola->frente;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

char *c_to_string(Cola cola) {
    const int cantidad = c_longitud(cola);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = cola->frente;
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
