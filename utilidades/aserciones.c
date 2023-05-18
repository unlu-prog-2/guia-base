#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "listas/listas.h"
#include "util_listas.h"
#include "pilas/pilas.h"
#include "pilas/util_pilas.h"
#include "colas/colas.h"
#include "colas/util_colas.h"

#define ERROR "\x1b[31m Error \x1b[0m"

bool bool_eq(bool real, bool esperado) {
    if (real != esperado) {
        printf("%s Valor recibido '%d' es distinto al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool bool_true(bool real) {
    if (real != true) {
        printf("%s Valor recibido 'false' es distinto al esperado 'true'.\n", ERROR);
        return false;
    }
    return true;
}

bool bool_false(bool real) {
    if (real != false) {
        printf("%s Valor recibido 'true' es distinto al esperado 'false'.\n", ERROR);
        return false;
    }
    return true;
}

bool str_eq(char *real, char *esperado) {
    if (strcmp(real, esperado) != 0) {
        printf("%s Valor recibido '%s' es distinto al esperado '%s'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool int_eq(int real, int esperado) {
    if (real != esperado) {
        printf("%s Valor recibido '%d' es distinto al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool int_gt(int real, int esperado) {
    if (real <= esperado) {
        printf("%s Valor recibido '%d' NO es mayor al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool int_gte(int real, int esperado) {
    if (real < esperado) {
        printf("%s Valor recibido '%d' NO es mayor o igual al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool int_lt(int real, int esperado) {
    if (real >= esperado) {
        printf("%s Valor recibido '%d' NO es menor al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool int_lte(int real, int esperado) {
    if (real > esperado) {
        printf("%s Valor recibido '%d' NO es menor o igual al esperado '%d'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool float_eq(float real, float esperado) {
    if (real != esperado) {
        printf("%s Valor recibido '%f' es distinto al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool float_gt(float real, float esperado) {
    if (real <= esperado) {
        printf("%s Valor recibido '%f' NO es mayor al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool float_gte(float real, float esperado) {
    if (real < esperado) {
        printf("%s Valor recibido '%f' NO es mayor o igual al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool float_lt(float real, float esperado) {
    if (real >= esperado) {
        printf("%s Valor recibido '%f' NO es menor al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool float_lte(float real, float esperado) {
    if (real > esperado) {
        printf("%s Valor recibido '%f' NO es menor o igual al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool double_eq(double real, double esperado) {
    if (real != esperado) {
        printf("%s Valor recibido '%f' es distinto al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool double_gt(double real, double esperado) {
    if (real <= esperado) {
        printf("%s Valor recibido '%f' NO es mayor al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool double_gte(double real, double esperado) {
    if (real < esperado) {
        printf("%s Valor recibido '%f' NO es mayor o igual al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool double_lt(double real, double esperado) {
    if (real >= esperado) {
        printf("%s Valor recibido '%f' NO es menor al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

bool double_lte(double real, double esperado) {
    if (real > esperado) {
        printf("%s Valor recibido '%f' NO es menor o igual al esperado '%f'.\n", ERROR, real, esperado);
        return false;
    }
    return true;
}

// ------
// Arrays
// ------
bool int_array_eq(int *real, int *esperado, int longReal, int longEsperado) {
    bool coincideContenido = true;
    for (int i = 0; i < longReal; i++) {
        coincideContenido = coincideContenido && real[i] == esperado[i];
    }

    if (!coincideContenido) {
        char *cadenaReal = cadena_enteros_como_string(real, longReal);
        char *cadenaEsperado = cadena_enteros_como_string(esperado, longEsperado);
        printf("%s Valor recibido %s es distinto al esperado %s.\n", ERROR, cadenaReal, cadenaEsperado);
        free(cadenaReal);
        free(cadenaEsperado);
        return false;
    }
    return true;
}

// ------------
// TipoElemento
// ------------
bool compararPorClaves(TipoElemento este, TipoElemento otro) {
    return este->clave == otro->clave;
}

bool te_eq(TipoElemento real, TipoElemento esperado) {
    return (real->clave == esperado->clave);
}

bool te_eq_valor(TipoElemento real, TipoElemento esperado,
                 bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro)) {
    return compararTipoElemento(real, esperado);
}

// ------------
// Listas
// ------------
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
    while ((hay_siguiente(itReal)) && bIguales) {
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
    } else if (p_es_vacia(real) != p_es_vacia(esperado)) {
        print_pilas_distintas(real, esperado, toStringTipoElemento);
        return false;
    } else {
        TipoElemento te_real = p_desapilar(real);
        TipoElemento te_esperado = p_desapilar(esperado);
        bool resComparacion = compararTipoElemento(te_real, te_esperado) &&
                              pilas_eq_fn(real, esperado, compararTipoElemento, toStringTipoElemento);

        p_apilar(real, te_real);
        p_apilar(esperado, te_esperado);

        if (!resComparacion) {
            print_pilas_distintas(real, esperado, toStringTipoElemento);
        }

        return resComparacion;
    }
}

bool colas_eq(Cola real, Cola esperado) {
    return colas_eq_fn(real, esperado, compararPorClaves, NULL);
}

void intercambiar_colas(Cola cola1, Cola cola2) {
    while (!c_es_vacia(cola1)) {
        c_encolar(cola2, c_desencolar(cola1));
    }
}

bool colas_eq_fn(Cola real, Cola esperado, bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro),
                 char *(*toStringTipoElemento)(TipoElemento te)) {
    if (real == esperado) {
        return true;
    }

    bool iguales = true;
    Cola aux1 = c_crear();
    Cola aux2 = c_crear();

    // Verificar si las colas tienen los mismos elementos
    while (!c_es_vacia(real) && !c_es_vacia(esperado)) {
        TipoElemento elem1 = c_desencolar(real);
        TipoElemento elem2 = c_desencolar(esperado);
        c_encolar(aux1, elem1);
        c_encolar(aux2, elem2);
        if (!compararTipoElemento(elem1, elem2)) {
            iguales = false;
        }
    }

    // Si una de las dos es vacía y la otra no, es porque no tenían la misma cantidad de elementos, por lo tanto no son iguales
    if (c_es_vacia(real) != c_es_vacia(esperado)) {
        iguales = false;

        // Terminamos de mover los elementos de la cola no vacía a la cola auxiliar
        intercambiar_colas(real, aux1);
        intercambiar_colas(esperado, aux2);
    }

    // Devolver elementos a las colas originales
    intercambiar_colas(aux1, real);
    intercambiar_colas(aux2, esperado);

    // Liberar memoria de las colas auxiliares
    destruir_cola(aux1);
    destruir_cola(aux2);

    if (!iguales) {
        char *cadenaReal = cola_como_string(real, toStringTipoElemento);
        char *cadenaEsperado = cola_como_string(esperado, toStringTipoElemento);
        printf("%s Valor recibido %s es distinto al esperado %s.\n", ERROR, cadenaReal, cadenaEsperado);
        free(cadenaReal);
        free(cadenaEsperado);
    }

    return iguales;
}
