#include <stdlib.h>
#include <string.h>
#include "tipo_elemento/tipo_elemento.h"
#include "listas/listas.h"

Lista crear_lista_desde_array(const int *vector, const int tamano) {
    Lista l = l_crear();

    for (int i = 0; i < tamano; i++) {
        l_agregar(l, te_crear(vector[i]));
    }

    return l;
}

void destruir_lista(const Lista l) {
    Iterador iter = iterador(l);
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        free(te);
    }
    free(iter);
    free(l);
}

char *lista_como_string(const Lista lista, char *(*toStringTipoElemento)(TipoElemento te)) {
    char *result = (char *) malloc(sizeof(char) * 3);
    strcpy(result, "[");

    Iterador iter = iterador(lista);
    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        char *cadena = toStringTipoElemento != NULL ? toStringTipoElemento(te) : toStringTipoElementoDefault(te);
        result = realloc(result, sizeof(char) * (strlen(result) + strlen(cadena) + 3));
        strcat(result, cadena);
        free(cadena);
        if (hay_siguiente(iter)) {
            strcat(result, ", ");
        }
    }
    free(iter);
    strcat(result, "]");
    return result;
}
