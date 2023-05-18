#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 100;

struct ColaRep {
    TipoElemento *valores;
    int frente;
    int final;
};

/** Función interna que hace avanzar el frente o el final hacia adelante */
int paso(int posicion);

/** Función interna que calcula la cantidad de elementos de la cola */
int longitud(Cola cola);

/** Función interna que dice si hay lugar para almacenar más elementos o no */
bool c_es_llena(Cola cola);

//-----------------
// Rutinas internas
//-----------------
int paso(int posicion) {
    return posicion % TAMANIO_MAXIMO + 1;
}

bool c_es_llena(Cola cola) {
    return paso(paso(cola->final)) == cola->frente;
}

int longitud(Cola cola) {
    int i = 0;
    int pos = cola->frente;
    while (pos != cola->final) {
        i++;
        pos = paso(pos);
    }
    return i;
}

char *c_to_string(Cola cola) {
    char *resultado = (char *) malloc(sizeof(char) * (longitud(cola) * 10 + 3));
    strcpy(resultado, "[");
    for (int i = cola->frente; i <= cola->final; i = paso(i)) {
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
