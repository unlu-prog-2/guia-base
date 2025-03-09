#include <stdlib.h>
#include "colas.h"
#include "aserciones_colas.h"

#include "util_colas.h"
#include "tipo_elemento/aserciones_tipo_elemento.h"

#define ERROR "\x1b[31m Error \x1b[0m"

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
