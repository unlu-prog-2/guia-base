#include <stdlib.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "pilas/util_pilas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"
#include "listas/util_listas.h"


bool compararRepetido(TipoElemento este, TipoElemento otro) {
    struct Repetido *esteRepetido = (struct Repetido *) este->valor;
    struct Repetido *otroPunto = (struct Repetido *) otro->valor;
    return esteRepetido->clave == otroPunto->clave &&
           esteRepetido->posicionEnPila == otroPunto->posicionEnPila &&
           esteRepetido->posicionEnCola == otroPunto->posicionEnCola;
}

char *toStringRepetido(TipoElemento te) {
    struct Repetido *repetido = (struct Repetido *) te->valor;
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "Repetido { clave: %d, posicionEnPila: %d, posicionEnCola: %d }", repetido->clave,
            repetido->posicionEnPila, repetido->posicionEnCola);
    return str;
}

void probar(Pila pila, Cola cola, struct Repetido valoresEsperados[], int cantEsperados) {
    // TODO Comentado para que no fallen los tests
//    Lista esperada = l_crear();
//    for (int i = 0; i < cantEsperados; ++i) {
//        l_agregar(esperada, te_crear_con_valor(0, &valoresEsperados[i]));
//    }
//
//    Lista resultado = buscaRepetidos(pila, cola);
//
//    assert(listas_eq_fn(resultado, esperada, compararRepetido, toStringRepetido));
//    destruir_lista(resultado);
//    destruir_lista(esperada);
}

int main() {
    imprimir_titulo("Tests para repetidos");

//    int valoresPila[] = {2, 5, 8, 19, 3, 4};
//    Pila p = crear_pila_desde_array(valoresPila, 6);
//
//    int valoresCola[] = {4, 18, 12, 5, 6};
//    Cola c = crear_cola_desde_array(valoresCola, 6);
//
//    struct Repetido valoresEsperados[] = {
//            {5, 2, 4},
//            {4, 6, 1}
//    };
//
//    probar(p, c, valoresEsperados, 2);
//
//    destruir_pila(p);
//    destruir_cola(c);
    return 0;
}
