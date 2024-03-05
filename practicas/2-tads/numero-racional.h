#ifndef NUMERO_RACIONAL_H
#define NUMERO_RACIONAL_H

#include <stdbool.h>

struct NRacional {
    int numerador;
    int denominador;
};

bool nRacional_inicializar(int numerador, int denominador, struct NRacional *numero);

void nRacional_simplificar(struct NRacional *f1);

struct nRacional nRacional_sumar(struct NRacional f1, struct NRacional f2);

struct nRacional nRacional_restar(struct NRacional f1, struct NRacional f2);

struct nRacional nRacional_multiplicar(struct NRacional f1, struct NRacional f2);

struct nRacional nRacional_dividir(struct NRacional f1, struct NRacional f2);

struct nRacional nRacional_potencia(struct NRacional f1, struct NRacional f2);

enum COMPARACION {
    MAYOR, MENOR, IGUAL
};

enum COMPARACION nRacional_comparar(struct NRacional f1, struct NRacional f2);

#endif //NUMERO_RACIONAL_H
