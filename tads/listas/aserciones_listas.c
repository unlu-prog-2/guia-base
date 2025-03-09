#include <stdlib.h>
#include "listas.h"
#include "aserciones_listas.h"

#include <stdio.h>

#include "util_listas.h"
#include "tipo_elemento/aserciones_tipo_elemento.h"

#define ERROR "\x1b[31m Error \x1b[0m"

bool listas_eq(Lista real, Lista esperado) {
    return listas_eq_fn(real, esperado, compararPorClaves, NULL);
}

bool listas_eq_fn(Lista real, Lista esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                  char *(*toStringTipoElemento)(TipoElemento te)) {
    if (real == esperado) {
        return true;
    }

    if (l_longitud(real) != l_longitud(esperado)) {
        printf("%s Valor recibido tiene %d elementos, mientras que el esperado tiene %d.\n", ERROR, l_longitud(real),
               l_longitud(esperado));
        return false;
    }

    Iterador itReal = iterador(real);
    Iterador itEsperado = iterador(esperado);

    bool bIguales = true;
    while (hay_siguiente(itReal) && bIguales) {
        TipoElemento te_real = siguiente(itReal);
        TipoElemento te_esperado = siguiente(itEsperado);
        bIguales = te_eq_valor(te_real, te_esperado, compararTipoElemento);
    }
    free(itReal);
    free(itEsperado);

    if (!bIguales) {
        char *cadenaReal = lista_como_string(real, toStringTipoElemento);
        char *cadenaEsperado = lista_como_string(esperado, toStringTipoElemento);
        printf("%s Valor recibido %s es distinto al esperado %s.\n", ERROR, cadenaReal, cadenaEsperado);
        free(cadenaReal);
        free(cadenaEsperado);
    }

    return bIguales;
}
