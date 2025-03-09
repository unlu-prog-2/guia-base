#include "tipo_elemento.h"
#include <stdlib.h>
#include <stdio.h>

TipoElemento te_crear(int clave) {
    TipoElemento te = (TipoElemento) malloc(sizeof(struct TipoElementoRep));
    te->clave = clave;
    te->valor = NULL;
    return te;
}

TipoElemento te_crear_con_valor(int clave, void *valor) {
    TipoElemento te = (TipoElemento) malloc(sizeof(struct TipoElementoRep));
    te->clave = clave;
    te->valor = valor;
    return te;
}

char *toStringTipoElementoDefault(TipoElemento te) {
    char *cadena = (char *) malloc(sizeof(char) * 10);
    sprintf(cadena, "%d", te->clave);
    return cadena;
}
