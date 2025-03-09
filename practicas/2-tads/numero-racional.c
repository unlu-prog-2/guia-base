#include <stdlib.h>
#include <stdio.h>
#include "numero-racional.h"

bool nr_inicializar(int numerador, int denominador, struct NumeroRacional *numeroRacional) {
}

void nr_simplificar(struct NumeroRacional *numeroRacional) {
}

struct NumeroRacional nr_sumar(struct NumeroRacional f1, struct NumeroRacional f2) {
}

struct NumeroRacional nr_restar(struct NumeroRacional f1, struct NumeroRacional f2) {
}

struct NumeroRacional nr_multiplicar(struct NumeroRacional f1, struct NumeroRacional f2) {
}

struct NumeroRacional nr_dividir(struct NumeroRacional f1, struct NumeroRacional f2) {
}

enum NRComparacion nr_comparar(struct NumeroRacional f1, struct NumeroRacional f2) {
}

char *comparacion_to_string(enum NRComparacion comparacion) {
    switch (comparacion) {
        case MAYOR:
            return "MAYOR";
        case MENOR:
            return "MENOR";
        case IGUAL:
        default:
            return "IGUAL";
    }
}

char *nr_to_string(struct NumeroRacional numeroRacional) {
    char *resultado = (char *) malloc(sizeof(char) * 20);
    if (numeroRacional.denominador == 1) {
        sprintf(resultado, "{%d}", numeroRacional.numerador);
    } else {
        sprintf(resultado, "{%d/%d}", numeroRacional.numerador, numeroRacional.denominador);
    }
    return resultado;
}
