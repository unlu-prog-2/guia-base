#ifndef NUMERO_RACIONAL_H
#define NUMERO_RACIONAL_H

#include <stdbool.h>

struct NumeroRacional {
    int numerador;
    int denominador;
};

bool nr_inicializar(int numerador, int denominador, struct NumeroRacional *numeroRacional);

void nr_simplificar(struct NumeroRacional *numeroRacional);

struct NumeroRacional nr_sumar(struct NumeroRacional f1, struct NumeroRacional f2);

struct NumeroRacional nr_restar(struct NumeroRacional f1, struct NumeroRacional f2);

struct NumeroRacional nr_multiplicar(struct NumeroRacional f1, struct NumeroRacional f2);

struct NumeroRacional nr_dividir(struct NumeroRacional f1, struct NumeroRacional f2);

enum NRComparacion {
    MAYOR, MENOR, IGUAL
};

enum NRComparacion nr_comparar(struct NumeroRacional f1, struct NumeroRacional f2);

char *comparacion_to_string(enum NRComparacion comparacion);

char *nr_to_string(struct NumeroRacional numeroRacional);

#endif //NUMERO_RACIONAL_H
