#ifndef ASERCIONES_H
#define ASERCIONES_H

#include <stdbool.h>

bool bool_eq(bool real, bool esperado);

bool bool_true(bool real);

bool bool_false(bool real);

bool str_eq(char *real, char *esperado);

bool enum_eq(int real, int esperado, char *(*toStringEnum)(int enumerado));

bool int_eq(int real, int esperado);

bool int_gt(int real, int esperado);

bool int_gte(int real, int esperado);

bool int_lt(int real, int esperado);

bool int_lte(int real, int esperado);

bool float_eq(float real, float esperado);

bool float_gt(float real, float esperado);

bool float_gte(float real, float esperado);

bool float_lt(float real, float esperado);

bool float_lte(float real, float esperado);

bool double_eq(double real, double esperado);

bool double_gt(double real, double esperado);

bool double_gte(double real, double esperado);

bool double_lt(double real, double esperado);

bool double_lte(double real, double esperado);

// ------
// Arrays
// ------
bool int_array_eq(int *real, int *esperado, int longReal, int longEsperado);

// ------
// Punteros
// ------
bool ptr_null(void *real);

bool ptr_not_null(void *real);

#endif // ASERCIONES_H
