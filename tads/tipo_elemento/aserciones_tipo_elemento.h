#ifndef ASERCIONES_TIPO_ELEMENTO_H
#define ASERCIONES_TIPO_ELEMENTO_H

#include <stdbool.h>
#include "tipo_elemento.h"

bool compararPorClaves(TipoElemento este, TipoElemento otro);

bool te_eq(TipoElemento real, TipoElemento esperado);

bool te_eq_valor(TipoElemento real, TipoElemento esperado,
                 bool (*compararTipoElemento)(TipoElemento este, TipoElemento otro));

#endif // ASERCIONES_TIPO_ELEMENTO_H
