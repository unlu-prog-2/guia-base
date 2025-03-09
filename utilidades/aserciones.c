#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"

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

bool enum_eq(int real, int esperado, char *(*toStringEnum)(int enumerado)) {
    if (real != esperado) {
        char *strReal = toStringEnum(real);
        char *strEsperado = toStringEnum(esperado);
        printf("%s Valor recibido '%s' es distinto al esperado '%s'.\n", ERROR, strReal, strEsperado);
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

// ------
// Punteros
// ------
bool ptr_null(void *real) {
    if (real != NULL) {
        printf("%s Valor recibido '%p' NO es NULL.\n", ERROR, real);
        return false;
    }
    return true;
}

bool ptr_not_null(void *real) {
    if (real == NULL) {
        printf("%s Valor recibido '%p' es NULL.\n", ERROR, real);
        return false;
    }
    return true;
}
