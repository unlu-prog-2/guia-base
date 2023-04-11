#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tipo_elemento.h"
#include "listas/listas.h"

Lista crear_lista_desde_array(int *vector, int tamano) {
    Lista l = l_crear();

    for (int i = 0; i < tamano; i++) {
        l_agregar(l, te_crear(vector[i]));
    }

    return l;
}

char *toStringTipoElementoDefault(TipoElemento te) {
    char *cadena = (char *) malloc(sizeof(char) * 10);
    sprintf(cadena, "%d", te->clave);
    return cadena;
}

char *lista_como_string(Lista lista, char *(*toStringTipoElemento)(TipoElemento te)) {
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

    result[strlen(result) - 2] = ']';
    result[strlen(result) - 1] = '\0';
    return result;
}
