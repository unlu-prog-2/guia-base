#ifndef PRACTICA_COLAS_H
#define PRACTICA_COLAS_H

#include "colas/colas.h"
#include "listas/listas.h"
#include "pilas/pilas.h"

bool buscarElemento(Cola c, TipoElemento e);

void insertarElemento(Cola c, TipoElemento e, int pos);

void eliminarElemento(Cola c, int clave);

int tamanoCola(Cola c);

Cola copia(Cola c);

Cola invertir(Cola c);

bool comparar(Cola c1, Cola c2);

bool mismosElementos(Cola c1, Cola c2);

Cola unicos(Cola c);

struct Divisores {
    int total;
    Lista parciales;
};

struct Divisores *buscaDivisores(Cola c);

struct Repetido {
    int clave;
    int posicionEnPila;
    int posicionEnCola;
};

Lista buscaRepetidos(Pila p, Cola c);

Lista procesar(int q, Cola c1, Cola c2, Cola c3);

#endif // PRACTICA_COLAS_H
