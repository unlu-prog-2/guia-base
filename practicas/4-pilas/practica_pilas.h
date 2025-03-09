#ifndef PRACTICA_PILAS_H
#define PRACTICA_PILAS_H

#include "pilas/pilas.h"

bool buscarElemento(Pila p, TipoElemento e);

void insertarElemento(Pila p, TipoElemento e, int pos);

void eliminarElemento(Pila p, int clave);

void intercambiarElementos(Pila p, int pos1, int pos2);

Pila copiar(Pila p);

int contarElementos(Pila p);

bool compararPilas(Pila p1, Pila p2);

char *cambioDeBase(int numero, int base);

Pila invertirPila(Pila p);

Pila eliminarTodasOcurrencias(Pila p, int clave);

Pila elementosEnComun(Pila p1, Pila p2);

Pila eliminarRepetidos(Pila p);

#endif // PRACTICA_PILAS_H
