#include <stdbool.h>

#include "aserciones_tipo_elemento.h"

bool compararPorClaves(TipoElemento este, TipoElemento otro) {
    return este->clave == otro->clave;
}

bool te_eq(TipoElemento real, TipoElemento esperado) {
    return real->clave == esperado->clave;
}

bool te_eq_valor(TipoElemento real, TipoElemento esperado,
                 bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro)) {
    return compararTipoElemento(real, esperado);
}
