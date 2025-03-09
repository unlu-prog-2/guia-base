#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "colas.h"

static const int TAMANIO_MAXIMO = 1000;

struct ColaRep {
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};

Cola c_crear() {
}

bool c_es_llena(Cola cola) {
    return cola->final == TAMANIO_MAXIMO;
}

bool c_encolar(Cola cola, TipoElemento elemento) {
}

TipoElemento c_desencolar(Cola cola) {
}

bool c_es_vacia(Cola cola) {
}

TipoElemento c_recuperar(Cola cola) {
}

void c_mostrar(Cola cola) {
}

char *c_to_string(Cola cola) {
    char *resultado = (char *) malloc(sizeof(char) * (cola->final * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < cola->final; i++) {
        char num_str[10];
        sprintf(num_str, "%d", cola->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (cola->final - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
