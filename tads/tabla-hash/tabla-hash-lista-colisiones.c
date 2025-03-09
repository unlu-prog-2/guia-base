#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla-hash.h"
#include "listas/listas.h"

struct TipoRegistroTabla {
    TipoElemento tipo_elemento;
    bool ocupado;
    Lista lista_colisiones;
};

struct TablaHashRep {
    int (*hash_function)(int);

    int capacidad;
    struct TipoRegistroTabla *tabla;
};

TablaHash th_crear(int capacidad, int (*hash_function)(int)) {
}

bool th_insertar(TablaHash th, TipoElemento te) {
}

bool th_eliminar(TablaHash th, int clave) {
}

TipoElemento th_recuperar(TablaHash th, int clave) {
}

void th_mostrar_interna(TablaHash th, bool soloOcupados) {
    printf("Contenido de la tabla hash:\n");
    for (int i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->tabla[i];
        if (registroTabla.ocupado) {
            printf("  tabla[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            Iterador iter = iterador(registroTabla.lista_colisiones);
            while (hay_siguiente(iter)) {
                TipoElemento e = siguiente(iter);
                printf(" -> %i ", e->clave);
            }
            free(iter);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
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
