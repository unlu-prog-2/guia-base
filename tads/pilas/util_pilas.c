#include <stdlib.h>
#include <string.h>

#include "tipo_elemento/tipo_elemento.h"
#include "pilas.h"
#include "util_pilas.h"

Pila crear_pila_desde_array(const int *vector, const int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        p_apilar(p, te_crear(vector[i]));
    }

    return p;
}

void destruir_pila(Pila p) {
    while (!p_es_vacia(p)) {
        TipoElemento te = p_desapilar(p);
        free(te);
    }
    free(p);
}

char *pila_como_string(Pila pila, char *(*toStringTipoElemento)(TipoElemento te)) {
    char *result = (char *) malloc(sizeof(char) * 3);
    strcpy(result, "[");

    Pila auxiliar = p_crear();

    while (!p_es_vacia(pila)) {
        TipoElemento te = p_desapilar(pila);
        p_apilar(auxiliar, te);

        char *cadena = toStringTipoElemento != NULL ? toStringTipoElemento(te) : toStringTipoElementoDefault(te);
        result = realloc(result, sizeof(char) * (strlen(result) + strlen(cadena) + 3));
        strcat(result, cadena);
        free(cadena);
        if (!p_es_vacia(pila)) {
            strcat(result, ", ");
        }
    }
    strcat(result, "]");

    // Se restaura la pila original
    while (!p_es_vacia(auxiliar)) {
        p_apilar(pila, p_desapilar(auxiliar));
    }

    return result;
}
