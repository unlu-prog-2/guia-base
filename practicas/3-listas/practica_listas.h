#ifndef PRACTICA_LISTAS_H
#define PRACTICA_LISTAS_H

#include "listas/listas.h"

// Operaciones varias
Lista invertirLista(Lista l);

struct ElementoYPosicion {
    int valor;
    int ordinal;
};

struct ElementoYPosicion menorYPosicion(Lista l);

struct ElementoYOcurrencias {
    int valor;
    int ocurrencias;
};

struct ElementoYOcurrencias mayorYOcurrencias(Lista l);

double promedio(Lista l);

Lista numerosAlAzar(int cantidad);

Lista multiplos(Lista l, int n);

Lista reflejarLista(Lista l, bool ultimoDoble);


// Lista con números que son múltiplos
bool listaEsMultiplo(Lista l1, Lista l2);


// Comparación de listas
enum Comparacion {
    MENOR = -1,
    IGUAL = 0,
    MAYOR = 1
};

enum Comparacion compararListas(Lista l1, Lista l2);

// TAD Polinomio
struct Polinomio {
    Lista coeficientes;
};

struct PuntoXY {
    double x, y;
};

double evaluar(struct Polinomio p, double x);

Lista valores(struct Polinomio p, int desde, int hasta, double paso);

// Sublistas
bool subLista(Lista l1, Lista l2);

// Subconjuntos que suman N
Lista subConjuntosQueSumanN(Lista l1, int n);

#endif // PRACTICA_LISTAS_H
