#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tablas-hash.h"

struct TipoRegistroTabla {
    TipoElemento tipo_elemento;
    bool ocupado;
};

struct TablaHashRep {
    int (*hash_function)(int);

    int capacidad;
    struct TipoRegistroTabla *tabla;
    struct TipoRegistroTabla *zona_overflow;
};

TablaHash th_crear(int capacidad, int (*hash_function)(int)) {
}

void th_insertar(TablaHash th, TipoElemento te) {
}

void th_eliminar(TablaHash th, int clave) {
}

TipoElemento th_recuperar(TablaHash th, int clave) {
}

void th_mostrar_interna(TablaHash th, bool soloOcupados) {
    printf("Contenido de la tabla hash:\n");
    for (int i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->tabla[i];
        if (registroTabla.ocupado) {
            printf("  tabla[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
        }
    }
    printf(" Zona de overflow:\n");
    for (int i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->zona_overflow[i];
        if (registroTabla.ocupado) {
            printf("  zo[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  zo[%i] [ libre ]\n", i);
        }
    }
    printf("\n");
}

void th_mostrar(TablaHash th) {
    th_mostrar_interna(th, false);
}


void th_mostrar_solo_ocupados(TablaHash th) {
    th_mostrar_interna(th, true);
}
