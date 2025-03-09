#include <stdlib.h>
#include <string.h>

#include "tipo_elemento/tipo_elemento.h"
#include "colas.h"
#include "util_colas.h"

Cola crear_cola_desde_array(const int *vector, const int tamano) {
    Cola p = c_crear();

    for (int i = 0; i < tamano; i++) {
        c_encolar(p, te_crear(vector[i]));
    }

    return p;
}

void destruir_cola(Cola cola) {
    while (!c_es_vacia(cola)) {
        TipoElemento te = c_desencolar(cola);
        free(te);
    }
    free(cola);
}

char *cola_como_string(Cola cola, char *(*toStringTipoElemento)(TipoElemento te)) {
    char *result = (char *) malloc(sizeof(char) * 3);
    strcpy(result, "[");

    Cola auxiliar = c_crear();

    while (!c_es_vacia(cola)) {
        TipoElemento te = c_desencolar(cola);
        c_encolar(auxiliar, te);

        char *cadena = toStringTipoElemento != NULL ? toStringTipoElemento(te) : toStringTipoElementoDefault(te);
        result = realloc(result, sizeof(char) * (strlen(result) + strlen(cadena) + 3));
        strcat(result, cadena);
        free(cadena);
        if (!c_es_vacia(cola)) {
            strcat(result, ", ");
        }
    }
    strcat(result, "]");

    // Se restaura la cola original
    while (!c_es_vacia(auxiliar)) {
        c_encolar(cola, c_desencolar(auxiliar));
    }

    return result;
}
