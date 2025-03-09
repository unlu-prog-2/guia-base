#include <stdlib.h>
#include "pilas.h"
#include "aserciones_pilas.h"

#include "util_pilas.h"
#include "tipo_elemento/aserciones_tipo_elemento.h"

#define ERROR "\x1b[31m Error \x1b[0m"

bool pilas_eq(Pila real, Pila esperado) {
    return pilas_eq_fn(real, esperado, compararPorClaves, NULL);
}

void print_pilas_distintas(Pila real, Pila esperado, char *(*toStringTipoElemento)(TipoElemento te)) {
    char *cadenaReal = pila_como_string(real, toStringTipoElemento);
    char *cadenaEsperado = pila_como_string(esperado, toStringTipoElemento);
    printf("%s Valor recibido %s es distinto al esperado %s.\n", ERROR, cadenaReal, cadenaEsperado);
    free(cadenaReal);
    free(cadenaEsperado);
}

bool pilas_eq_fn(Pila real, Pila esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te)) {
    if (real == esperado) {
        return true;
    }

    if (p_es_vacia(real) && p_es_vacia(esperado)) {
        return true;
    }
    if (p_es_vacia(real) != p_es_vacia(esperado)) {
        print_pilas_distintas(real, esperado, toStringTipoElemento);
        return false;
    }
    TipoElemento te_real = p_desapilar(real);
    TipoElemento te_esperado = p_desapilar(esperado);
    const bool resComparacion = compararTipoElemento(te_real, te_esperado) &&
                          pilas_eq_fn(real, esperado, compararTipoElemento, toStringTipoElemento);

    p_apilar(real, te_real);
    p_apilar(esperado, te_esperado);

    if (!resComparacion) {
        print_pilas_distintas(real, esperado, toStringTipoElemento);
    }

    return resComparacion;
}
