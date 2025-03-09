#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 1000;

struct ColaRep {
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};

// Función interna que hace avanzar el frente y el final hacia adelante
unsigned int paso(unsigned int posicion);

Cola c_crear() {
}

bool c_encolar(Cola cola, TipoElemento elemento) {
}

TipoElemento c_desencolar(Cola cola) {
}

bool c_es_vacia(Cola cola) {
}

TipoElemento c_recuperar(Cola cola) {
}

bool c_es_llena(Cola cola) {
}

void c_mostrar(Cola cola) {
}


//-----------------
// Rutinas internas
//-----------------
unsigned int paso(unsigned int posicion) {
    return posicion % TAMANIO_MAXIMO + 1;
}

unsigned int c_longitud(Cola cola) {
    unsigned i = 0;
    unsigned pos = cola->frente;
    while (pos != cola->final) {
        i++;
        pos = paso(pos);
    }
    return i;
}

char *c_to_string(Cola cola) {
    char *resultado = (char *) malloc(sizeof(char) * (c_longitud(cola) * 10 + 3));
    strcpy(resultado, "[");
    for (unsigned int i = cola->frente; i <= cola->final; i = paso(i)) {
        char num_str[10];
        sprintf(num_str, "%d", cola->valores[i]->clave);
        strcat(resultado, num_str);
        if (i != cola->final) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
