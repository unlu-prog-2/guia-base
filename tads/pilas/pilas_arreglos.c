#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pilas.h"

static const int TAMANIO_MAXIMO = 1000;

struct PilaRep {
    TipoElemento *valores;
    unsigned int tope;
};

Pila p_crear() {
}

bool p_apilar(Pila pila, TipoElemento elemento) {
}

TipoElemento p_desapilar(Pila pila) {
}

TipoElemento p_tope(Pila pila) {
}

bool p_es_vacia(Pila pila) {
}

bool p_es_llena(Pila pila) {
}

void p_mostrar(Pila pila) {
}

char *p_to_string(Pila pila) {
    char *resultado = (char *) malloc(sizeof(char) * (pila->tope * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < pila->tope; i++) {
        char num_str[10];
        sprintf(num_str, "%d", pila->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (pila->tope - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
