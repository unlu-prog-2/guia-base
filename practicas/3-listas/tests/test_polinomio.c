#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../practica_listas.h"
#include "cadenas.h"
#include "aserciones.h"
#include "listas/util_listas.h"
#include "listas/aserciones_listas.h"

bool compararPuntoXY(TipoElemento este, TipoElemento otro) {
    struct PuntoXY *estePunto = (struct PuntoXY *) este->valor;
    struct PuntoXY *otroPunto = (struct PuntoXY *) otro->valor;
    return estePunto->x == otroPunto->x && estePunto->y == otroPunto->y;
}

char *toStringPuntoXY(TipoElemento te) {
    struct PuntoXY *punto = (struct PuntoXY *) te->valor;
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "P(%f, %f)", punto->x, punto->y);
    return str;
}

Lista crear_lista_puntos_desde_array(struct PuntoXY puntos[], int tamano) {
    Lista lista = l_crear();
    for (int i = 0; i < tamano; i++) {
        l_agregar(lista, te_crear_con_valor(0, &puntos[i]));
    }

    return lista;
}

int main() {
    imprimir_titulo("Tests para polinomio");

    return 0;
}
